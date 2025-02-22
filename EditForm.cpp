﻿//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#pragma hdrstop

#include "glTrack.h"
#include "EditForm.h"
#include "glTrack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditFormProduct* EditFormProduct;
//---------------------------------------------------------------------------
// Constructorul care initializeaza datele din edituri pe baza id-ului, randului selectat
__fastcall TEditFormProduct::TEditFormProduct(
    TComponent* Owner, TFDQuery* query, int pa_id) :
    TForm(Owner),
    FDQuery1(query), ProductId(pa_id)
{
    FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT pp.pa_id, a.a_marca_model, ct.cod, "
                          "c.nume_celula, pp.p_count, pp.p_price "
                          "FROM product_auto_table pp "
                          "JOIN vehicle_table a ON a.a_id = pp.a_id "
                          "JOIN celula_table c ON c.id_celula = pp.celula_id "
                          "JOIN code_table ct ON ct.id_cod = pp.id_cod "
                          "WHERE pp.pa_id = :pa_id";

    FDQuery1->ParamByName("pa_id")->AsInteger = pa_id;
    FDQuery1->Open();

    if (!FDQuery1->IsEmpty()) {
        AutoEdit->Text = (FDQuery1->FieldByName("a_marca_model")->AsWideString);
        CodEdit->Text = FDQuery1->FieldByName("cod")->AsString;
        CelulaEdit->Text = FDQuery1->FieldByName("nume_celula")->AsString;
        CountEdit->Text = FDQuery1->FieldByName("p_count")->AsString;
        PriceEdit->Text = FDQuery1->FieldByName("p_price")->AsString;
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditFormProduct::CancelButtonClick(TObject* Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

// Functia butonului de confirmare pentru a adauga datele in db

void __fastcall TEditFormProduct::ConfirmButtonClick(TObject* Sender)
{
    if (CodEdit->Text == "" || AutoEdit->Text == "") {
        ShowMessage(L"Câmpurile automobil sau cod sunt obligatorii!");
        return;
    }

    if (!StrToInt(PriceEdit->Text) && StrToInt(PriceEdit->Text) != 0) {
		ShowMessage(L"Doar Cifre!");
        return;
    }
    if (!StrToInt(CountEdit->Text) && StrToInt(CountEdit->Text) != 0) {
		ShowMessage(L"Doar Cifre!");
		return;
	}
    TFDQuery* newFDQuery = new TFDQuery(
        this); // Creează un nou FDQuery temporar  sa nu faca conflict cu cel principal
    try {
        newFDQuery->Connection =
            FDQuery1->Connection; // Folosește aceeași conexiune
        newFDQuery->Close();
        newFDQuery->SQL->Clear();
        newFDQuery->Params->Clear();

        int celulaId = -1;
        String celulaNume = CelulaEdit->Text;
        std::transform(celulaNume.begin(), celulaNume.end(), celulaNume.begin(),
            ::toupper);
        //        ShowMessage("pa_id primit: " + IntToStr(ProductId));

        // verificare daca celula exista
        newFDQuery->Close();
        newFDQuery->SQL->Text =
            "SELECT id_celula FROM celula_table WHERE nume_celula = :celula_nume";
        newFDQuery->ParamByName("celula_nume")->AsString = celulaNume;
        newFDQuery->Open();

        if (!newFDQuery->IsEmpty()) {
            celulaId = newFDQuery->FieldByName("id_celula")->AsInteger;
        } else {
            // daca nu exista, o inseram și preia noul ID
            newFDQuery->Close();
            newFDQuery->SQL->Text =
                "INSERT INTO celula_table (nume_celula) VALUES (:celula_nume)";
            newFDQuery->ParamByName("celula_nume")->AsString = celulaNume;
            newFDQuery->ExecSQL();

            // luam id-ul nou inserat
            newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS celula_id";
            newFDQuery->Open();
            celulaId = newFDQuery->FieldByName("celula_id")->AsInteger;
        }

        newFDQuery->Close();

        // Update product_auto_table
        newFDQuery->SQL->Text =
            "UPDATE product_auto_table SET celula_id = :celula_id WHERE pa_id = :pa_id";
        newFDQuery->ParamByName("celula_id")->AsInteger = celulaId;
        newFDQuery->ParamByName("pa_id")->AsInteger = ProductId;
        newFDQuery->ExecSQL();

        //--------------

        newFDQuery->SQL->Text =
            "UPDATE vehicle_table SET a_marca_model = :a_marca "
            "WHERE a_id = (SELECT a_id FROM product_auto_table WHERE pa_id = :pa_id)";
        String a_marca = AutoEdit->Text;
        std::transform(
            a_marca.begin(), a_marca.end(), a_marca.begin(), ::toupper);
        newFDQuery->ParamByName("a_marca")->AsWideString = a_marca;
        newFDQuery->ParamByName("pa_id")->AsInteger = ProductId;
        newFDQuery->ExecSQL();

        // verificare daca codul exista
        newFDQuery->Close();
        int cod_id = -1;
        String cod_nume = CodEdit->Text;
        std::transform(
            cod_nume.begin(), cod_nume.end(), cod_nume.begin(), ::toupper);
        newFDQuery->SQL->Text =
            "SELECT id_cod FROM code_table WHERE cod = :cod";
        newFDQuery->ParamByName("cod")->AsString = cod_nume;
        newFDQuery->Open();

        if (!newFDQuery->IsEmpty()) {
            cod_id = newFDQuery->FieldByName("id_cod")->AsInteger;
        } else {
            // daca nu exista, o inseram și preia noul ID
            newFDQuery->Close();
            newFDQuery->SQL->Text =
                "INSERT INTO code_table (cod) VALUES (:cod_nume)";
            newFDQuery->ParamByName("cod_nume")->AsString = cod_nume;
            newFDQuery->ExecSQL();

            // luam id-ul nou inserat
            newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS id_cod";
            newFDQuery->Open();
            cod_id = newFDQuery->FieldByName("id_cod")->AsInteger;
        }

        newFDQuery->Close();

        // Update product_auto_table cu codul nou sau vechi inserat
        newFDQuery->SQL->Text =
            "UPDATE product_auto_table SET id_cod = :cod_id WHERE pa_id = :pa_id";
        newFDQuery->ParamByName("cod_id")->AsInteger = cod_id;
        newFDQuery->ParamByName("pa_id")->AsInteger = ProductId;
        newFDQuery->ExecSQL();

        // Update product_auto_table cu pret nou sau vechi inserat
        newFDQuery->SQL->Text =
            "UPDATE product_auto_table SET p_count = :p_count, p_price = :price WHERE pa_id = :pa_id";
        newFDQuery->ParamByName("p_count")->AsInteger =
            StrToIntDef(CountEdit->Text, 0);
        newFDQuery->ParamByName("price")->AsFloat =
            StrToFloatDef(PriceEdit->Text, 0);
        newFDQuery->ParamByName("pa_id")->AsInteger = ProductId;
        newFDQuery->ExecSQL();

        ShowMessage("Modificările au fost salvate!");
        ModalResult = mrOk;

    } catch (Exception &e) {
        ShowMessage("Eroare la actualizare: " + e.Message);
    }

    delete newFDQuery;
}
//---------------------------------------------------------------------------

void __fastcall TEditFormProduct::CancelButtonKeyDown(
    TObject* Sender, WORD &Key, TShiftState Shift)
{
    if (Key == VK_ESCAPE)
        this->Close();
}
//---------------------------------------------------------------------------

