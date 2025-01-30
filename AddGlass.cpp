//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddGlass.h"
#include "glTrack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddFormG *AddFormG;
//---------------------------------------------------------------------------
__fastcall TAddFormG::TAddFormG(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddFormG::CancelButtonClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddFormG::Initialize_Component()
{
	FDQuery1->Connection = MenuForm->FDConnection1;

    try {
        FDQuery1->SQL->Clear();
		FDQuery1->SQL->Add("SELECT DISTINCT a_marca FROM automobile");
        FDQuery1->Open();

        // Populăm AutoComboBox cu date din DB
        AutoComboBox->Clear();
        while (!FDQuery1->Eof) {
			AutoComboBox->Items->Add(FDQuery1->FieldByName("a_marca")->AsString);
            FDQuery1->Next();
        }
        FDQuery1->Close();

        FDQuery1->SQL->Clear();
        FDQuery1->SQL->Add("SELECT DISTINCT a_model FROM automobile");
        FDQuery1->Open();

        // Populăm ModelComboBox cu date din DB
        ModelComboBox->Clear();
        while (!FDQuery1->Eof) {
            ModelComboBox->Items->Add(FDQuery1->FieldByName("a_model")->AsString);
            FDQuery1->Next();
        }
		FDQuery1->Close();

		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Add("SELECT DISTINCT nume_sectie FROM sectia");
		FDQuery1->Open();

		// Populăm SectiaComboBox cu date din DB
		SectiaComboBox->Clear();
        while (!FDQuery1->Eof) {
			SectiaComboBox->Items->Add(FDQuery1->FieldByName("nume_sectie")->AsString);
			FDQuery1->Next();
		}
		FDQuery1->Close();

        FDQuery1->SQL->Clear();
		FDQuery1->SQL->Add("SELECT DISTINCT nume_celula FROM celula");
		FDQuery1->Open();

		// Populăm CelulaComboBox cu date din DB
		CelulaComboBox->Clear();
        while (!FDQuery1->Eof) {
			CelulaComboBox->Items->Add(FDQuery1->FieldByName("nume_celula")->AsString);
			FDQuery1->Next();
		}
		FDQuery1->Close();
	}
	catch (Exception &e) {
		ShowMessage("Eroare la încărcarea datelor: " + e.Message);
	}
}

void __fastcall TAddFormG::AddButtonClick(TObject *Sender)
{
    String marca, model, sectia, celula;
    int a_id = -1, p_id, sectia_id = -1, celula_id = -1;

    // Verificăm valorile introduse
    marca = (AutoComboBox->Text != "") ? AutoComboBox->Text : AutoEdit->Text;
    model = (ModelComboBox->Text != "") ? ModelComboBox->Text : ModelEdit->Text;
    sectia = (SectiaComboBox->Text != "") ? SectiaComboBox->Text : SectiaEdit->Text;
    celula = (CelulaComboBox->Text != "") ? CelulaComboBox->Text : CelulaEdit->Text;

    try {
        // Verificăm dacă automobilul există
        FDQuery1->SQL->Text = "SELECT a_id FROM automobile WHERE a_marca = :marca AND a_model = :model";
        FDQuery1->ParamByName("marca")->AsString = marca;
        FDQuery1->ParamByName("model")->AsString = model;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            a_id = FDQuery1->FieldByName("a_id")->AsInteger;
        } else {
            // Adăugăm automobilul
            FDQuery1->SQL->Text = "INSERT INTO automobile (a_marca, a_model) VALUES (:marca, :model)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS new_a_id";
            FDQuery1->Open();
            a_id = FDQuery1->FieldByName("new_a_id")->AsInteger;
        }

        // Verificăm dacă secția există
        FDQuery1->SQL->Text = "SELECT id_sectia FROM sectia WHERE nume_sectie = :nume_sectie";
        FDQuery1->ParamByName("nume_sectie")->AsString = sectia;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            sectia_id = FDQuery1->FieldByName("id_sectia")->AsInteger;
        } else {
            // Adăugăm secția
            FDQuery1->SQL->Text = "INSERT INTO sectia (nume_sectie) VALUES (:nume_sectie)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS sectia_id";
            FDQuery1->Open();
            sectia_id = FDQuery1->FieldByName("sectia_id")->AsInteger;
        }

        // Verificăm dacă celula există
        FDQuery1->SQL->Text = "SELECT id_celula FROM celula WHERE nume_celula = :nume_celula";
        FDQuery1->ParamByName("nume_celula")->AsString = celula;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            celula_id = FDQuery1->FieldByName("id_celula")->AsInteger;
        } else {
            // Adăugăm celula
            FDQuery1->SQL->Text = "INSERT INTO celula (nume_celula) VALUES (:nume_celula)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS celula_id";
            FDQuery1->Open();
            celula_id = FDQuery1->FieldByName("celula_id")->AsInteger;
        }

        // Inserăm parbriz
        FDQuery1->SQL->Text = "INSERT INTO parbrize (p_code, p_origine, p_count, p_price) VALUES (:p_code, :p_origine, :p_count, :p_price)";
        FDQuery1->ParamByName("p_code")->AsString = PCodeEdit->Text;
        FDQuery1->ParamByName("p_origine")->AsString = POrigineEdit->Text;
        FDQuery1->ParamByName("p_count")->AsInteger = StrToInt(CountEdit->Text);
        FDQuery1->ParamByName("p_price")->AsFloat = StrToFloat(PriceEdit->Text);
        FDQuery1->ExecSQL();
        FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS new_p_id";
        FDQuery1->Open();
        p_id = FDQuery1->FieldByName("new_p_id")->AsInteger;

        // Legăm celula la secție
        FDQuery1->SQL->Text = "UPDATE sectia SET id_celula = :id_celula WHERE id_sectia = :sectia_id";
        FDQuery1->ParamByName("id_celula")->AsInteger = celula_id;
        FDQuery1->ParamByName("sectia_id")->AsInteger = sectia_id;
        FDQuery1->ExecSQL();

        // Inserăm în parbrize_auto
        FDQuery1->SQL->Text = "INSERT INTO parbrize_auto (a_id, p_id, sectia_id) VALUES (:a_id, :p_id, :sectia_id)";
        FDQuery1->ParamByName("a_id")->AsInteger = a_id;
        FDQuery1->ParamByName("p_id")->AsInteger = p_id;
        FDQuery1->ParamByName("sectia_id")->AsInteger = sectia_id;
        FDQuery1->ExecSQL();

		ShowMessage("Datele au fost salvate cu succes!");
	  //  FDQuery1->Open();
    }
    catch (Exception &e) {
        ShowMessage("Eroare la salvare: " + e.Message);
    }
}


//---------------------------------------------------------------------------

void __fastcall TAddFormG::FormCreate(TObject *Sender)
{
	Initialize_Component();
}
//---------------------------------------------------------------------------

void __fastcall TAddFormG::AutoComboBoxChange(TObject *Sender)
{
String marcaSelectata = AutoComboBox->Text;

    try {
        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT a_model FROM automobile WHERE a_marca = :marca";
        FDQuery1->ParamByName("marca")->AsString = marcaSelectata;
        FDQuery1->Open();

		ModelComboBox->Items->Clear();
        while (!FDQuery1->Eof) {
            ModelComboBox->Items->Add(FDQuery1->FieldByName("a_model")->AsString);
            FDQuery1->Next();
        }
    }
    catch (Exception &e) {
        ShowMessage("Eroare la încărcarea modelelor: " + e.Message);
    }
}
//---------------------------------------------------------------------------

