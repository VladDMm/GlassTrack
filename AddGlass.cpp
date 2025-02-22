﻿//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#include "set"
#pragma hdrstop

#include "AddGlass.h"
#include "glTrack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddFormG* AddFormG;
//---------------------------------------------------------------------------
__fastcall TAddFormG::TAddFormG(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TAddFormG::CancelButtonClick(TObject* Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddFormG::Initialize_Component()
{
    FDQuery1->Connection = MenuForm->FDConnection1;

    try {
        FDQuery1->SQL->Clear();
        FDQuery1->SQL->Add("SELECT DISTINCT a_marca_model FROM vehicle_table");
        FDQuery1->Open();

        // Populăm AutoComboBox cu date din DB
        AutoComboBox->Clear();
        while (!FDQuery1->Eof) {
            AutoComboBox->Items->Add(
                FDQuery1->FieldByName("a_marca_model")->AsWideString);
            FDQuery1->Next();
        }
        FDQuery1->Close();

        // preluam numele celulei introdus
        FDQuery1->SQL->Clear();
        FDQuery1->SQL->Add("SELECT DISTINCT nume_celula FROM celula_table");
        FDQuery1->Open();

        // Populăm CelulaComboBox cu date din DB
        CelulaComboBox->Clear();
        while (!FDQuery1->Eof) {
            CelulaComboBox->Items->Add(
                FDQuery1->FieldByName("nume_celula")->AsString);
            FDQuery1->Next();
        }
        FDQuery1->Close();

        FDQuery1->SQL->Clear();
        FDQuery1->SQL->Add("SELECT DISTINCT cod FROM code_table");
        FDQuery1->Open();

        // Populăm CodComboBox cu date din DB
        CodComboBox->Clear();
        while (!FDQuery1->Eof) {
            CodComboBox->Items->Add(FDQuery1->FieldByName("cod")->AsString);
            FDQuery1->Next();
        }

        FDQuery1->Close();
    } catch (Exception &e) {
        ShowMessage("Eroare la încărcarea datelor: " + e.Message);
    }
}

//-----------------------------------------------------------------------------

// Functia butonului de adaugare ca sa inseram datele in db

void __fastcall TAddFormG::AddButtonClick(TObject* Sender)
{
    String marca, model, celula, cod_name;
	int a_id = -1, p_id, celula_id = -1, cod_id = -1;

	if(AutoComboBox->Text == "" || CelulaComboBox->Text == ""
	 || CodComboBox->Text == ""|| CountEdit->Text == "" || PriceEdit->Text == "")
	{	ShowMessage(L"Completează toate câmpurile!");
		return;
    }

	// Verificam valorile introduse
	marca = AutoComboBox->Text;
    std::transform(marca.begin(), marca.end(), marca.begin(),::toupper);
	celula = CelulaComboBox->Text;
	std::transform(celula.begin(), celula.end(), celula.begin(),::toupper);
	cod_name = CodComboBox->Text;
	std::transform(cod_name.begin(), cod_name.end(), cod_name.begin(),::toupper);

    try {
		// Verificam daca automobilul exista
        FDQuery1->SQL->Text =
            "SELECT a_id FROM vehicle_table WHERE a_marca_model = :marca";
		FDQuery1->ParamByName("marca")->AsString = marca;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            a_id = FDQuery1->FieldByName("a_id")->AsInteger;
        } else {
            // Adaugam automobilul
            FDQuery1->SQL->Text =
                "INSERT INTO vehicle_table (a_marca_model) VALUES (:marca)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS new_a_id";
            FDQuery1->Open();
            a_id = FDQuery1->FieldByName("new_a_id")->AsInteger;
        }

        // Verificam daca celula exista
        FDQuery1->SQL->Text =
            "SELECT id_celula FROM celula_table WHERE nume_celula = :nume_celula";
        FDQuery1->ParamByName("nume_celula")->AsString = celula;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            celula_id = FDQuery1->FieldByName("id_celula")->AsInteger;
        } else {
            // Adaugam celula
            FDQuery1->SQL->Text =
                "INSERT INTO celula_table (nume_celula) VALUES (:nume_celula)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS celula_id";
            FDQuery1->Open();
            celula_id = FDQuery1->FieldByName("celula_id")->AsInteger;
        }

        // Verificam daca codul exista
        FDQuery1->SQL->Text =
            "SELECT id_cod FROM code_table WHERE cod = :cod_name";
        FDQuery1->ParamByName("cod_name")->AsString = cod_name;
        FDQuery1->Open();

        if (!FDQuery1->IsEmpty()) {
            cod_id = FDQuery1->FieldByName("id_cod")->AsInteger;
        } else {
            // Adaugam codul
            FDQuery1->SQL->Text =
                "INSERT INTO code_table (cod) VALUES (:cod_name)";
            FDQuery1->ExecSQL();
            FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS id_cod";
            FDQuery1->Open();
            cod_id = FDQuery1->FieldByName("id_cod")->AsInteger;
        }

        // Adaugam produs
        //        FDQuery1->SQL->Text =
        //			"INSERT INTO product_table (p_name, p_count, p_price) VALUES (:p_name, :p_count, :p_price)";
        //		FDQuery1->ParamByName("p_name")->AsString = PNameEdit->Text;
        //		FDQuery1->ParamByName("p_count")->AsInteger = StrToInt(CountEdit->Text);
        //		FDQuery1->ParamByName("p_price")->AsFloat = StrToFloat(PriceEdit->Text);
        //        FDQuery1->ExecSQL();
        //        FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS new_p_id";
        //        FDQuery1->Open();
        //		p_id = FDQuery1->FieldByName("new_p_id")->AsInteger;

        // Adaugam date in product_auto_table
        //        FDQuery1->SQL->Text =
        //			"INSERT INTO product_auto_table (a_id, celula_id, id_cod,p_count, p_price) "
        //			"VALUES (:a_id, :celula_id, :id_cod, :p_count, :p_price)";
        //		FDQuery1->ParamByName("a_id")->AsInteger = a_id;
        //        FDQuery1->ParamByName("celula_id")->AsInteger = celula_id;
        //		FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
        //		FDQuery1->ParamByName("p_count")->AsInteger = StrToInt(CountEdit->Text);
        //		FDQuery1->ParamByName("p_price")->AsFloat = StrToFloat(PriceEdit->Text);
        //		FDQuery1->ExecSQL();

        FDQuery1->SQL->Text =
            "SELECT pa_id FROM product_auto_table WHERE a_id = :a_id AND celula_id = :celula_id AND id_cod = :id_cod";
        FDQuery1->ParamByName("a_id")->AsInteger = a_id;
        FDQuery1->ParamByName("celula_id")->AsInteger = celula_id;
        FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
        FDQuery1->Open();

        // Verificăm dacă există deja în baza de date
        if (FDQuery1->IsEmpty()) {
            // Dacă nu există, facem inserarea
            FDQuery1->SQL->Text =
                "INSERT INTO product_auto_table (a_id, celula_id, id_cod, p_count, p_price) VALUES (:a_id, :celula_id, :id_cod, :p_count, :p_price)";
            FDQuery1->ParamByName("a_id")->AsInteger = a_id;
            FDQuery1->ParamByName("celula_id")->AsInteger = celula_id;
            FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
            FDQuery1->ParamByName("p_count")->AsInteger =
                StrToInt(CountEdit->Text);
            FDQuery1->ParamByName("p_price")->AsFloat =
                StrToFloat(PriceEdit->Text);
            FDQuery1->ExecSQL();
        } else {
            // Dacă există, facem update
            int pa_Id = FDQuery1->FieldByName("pa_id")->AsInteger;

            FDQuery1->SQL->Text =
                "UPDATE product_auto_table SET p_count = :p_count, p_price = :p_price WHERE pa_id = :pa_id";
            FDQuery1->ParamByName("p_count")->AsInteger =
                StrToInt(CountEdit->Text);
            FDQuery1->ParamByName("p_price")->AsFloat =
                StrToFloat(PriceEdit->Text);
            FDQuery1->ParamByName("pa_id")->AsInteger = pa_Id;
            FDQuery1->ExecSQL();
        }

        ShowMessage("Datele au fost salvate cu succes!");
    } catch (Exception &e) {
        ShowMessage("Eroare la salvare: " + e.Message);
    }
}

//---------------------------------------------------------------------------

void __fastcall TAddFormG::FormCreate(TObject* Sender)
{
    Initialize_Component();
}
//-----------------------------------------------------------------------------

// Functia care preia codul selectat din comboboxul cu codul disponibil la apasarea
// tastei ENTER daca e, si pe baza lui se atribuie produsele si automobilul la codul dat,
// sau se adauga cod nou

void __fastcall TAddFormG::CodComboBoxKeyPress(
    TObject* Sender, System::WideChar &Key)
{
	if (Key != VK_RETURN)
        return;

	String cod_name = CodComboBox->Text;
    if (cod_name == "") {

		AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
        AutoComboBox->Clear();
        CelulaComboBox->Clear();

        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}

    FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT id_cod FROM code_table WHERE cod = :cod_name";
    FDQuery1->ParamByName("cod_name")->AsString = cod_name;
    FDQuery1->Open();

    int cod_id = -1;
    if (!FDQuery1->IsEmpty()) {
        cod_id = FDQuery1->FieldByName("id_cod")->AsInteger;
    } else {
        if (MessageDlg(
                L"Nu există informaţii la acest cod,\nDoriţi să adăugaţi un produs nou?",
                mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
        {
            Close();
            return;
        }

        AutoComboBox->Items->Clear();
        CelulaComboBox->Items->Clear();

        FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT a_marca_model FROM vehicle_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsWideString;

            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT nume_celula FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;
            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);
            FDQuery1->Next();
        }
        return;
    }

    FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT a.a_marca_model FROM product_auto_table pa "
                          "JOIN vehicle_table a ON a.a_id = pa.a_id "
                          "JOIN code_table ct ON ct.id_cod = pa.id_cod "
                          "WHERE ct.id_cod = :id_cod";
    FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
    FDQuery1->Open();

    AutoComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    while (!FDQuery1->Eof) {
        //        String marca = FDQuery1->FieldByName("a_marca")->AsString;
        //        String model = FDQuery1->FieldByName("a_model")->AsString;
        //        String inceput_an = FDQuery1->FieldByName("a_year")->AsString;
        //        String sfarsit_an = FDQuery1->FieldByName("a_year_end")->AsString;
        //        String origine = FDQuery1->FieldByName("p_origine")->AsString;
        //
        //        POrigineEdit->Text = origine;
        //
        //        if (YearComboBox->Items->IndexOf(inceput_an) == -1)
        //            YearComboBox->Items->Add(inceput_an);
        //
        //        if (EndYearComboBox->Items->IndexOf(sfarsit_an) == -1)
        //            EndYearComboBox->Items->Add(sfarsit_an);
        //

        String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

        if (AutoComboBox->Items->IndexOf(marca) == -1)
            AutoComboBox->Items->Add(marca);

        FDQuery1->Next();
    }

    FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
                          "WHERE pa.id_cod = :id_cod";
    FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
    FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}

//---------------------------------------------------------------------------

// Functia care preia codul selectat din comboboxul cu codul disponibil daca
// e, si pe baza lui se atribuie produsele si automobilul la codul dat, sau se adauga cod nou

void __fastcall TAddFormG::CodComboBoxSelect(TObject* Sender)
{
	String cod_name = CodComboBox->Text;
    if (cod_name == "") {

		AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
		AutoComboBox->Clear();
        CelulaComboBox->Clear();

        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}
    int cod_id = -1;

	// Verifică dacă există codul în baza de date
    FDQuery1->SQL->Text = "SELECT id_cod FROM code_table WHERE cod = :cod_name";
    FDQuery1->ParamByName("cod_name")->AsString = cod_name;
    FDQuery1->Open();

    if (!FDQuery1->IsEmpty()) {
        // Codul există, extrage id_cod
		cod_id = FDQuery1->FieldByName("id_cod")->AsInteger;
        FDQuery1
            ->Close(); // Închide FDQuery1 înainte de a face o altă interogare
    } else {
        // Dacă nu există, întreabă utilizatorul dacă dorește să adauge un produs nou
        if (MessageDlg(
                L"Nu există informaţii la acest cod,\nDoriţi să adăugaţi un produs nou?",
                mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
		{
            Close();
            return;
        }

        // Dacă utilizatorul răspunde cu "Yes", încarcă mașinile și celulele
        AutoComboBox->Items->Clear();
        CelulaComboBox->Items->Clear();

        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }
        return;
    }
    FDQuery1->Close();
    //	FDQuery1->SQL->Text = "SELECT a_marca, a_model FROM vehicle_table";
    FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                          "FROM product_auto_table pa "
                          "JOIN vehicle_table a ON a.a_id = pa.a_id "
                          "JOIN code_table ct ON ct.id_cod = pa.id_cod "
                          "WHERE ct.id_cod = :id_cod ";
    FDQuery1->ParamByName("id_cod")->AsString = cod_id;
    FDQuery1->Open();

    AutoComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    // umplem combo boxul automobile si modelele lor cu datele din db
    while (!FDQuery1->Eof) {
        String marca = FDQuery1->FieldByName("a_marca_model")->AsWideString;

        if (AutoComboBox->Items->IndexOf(marca) == -1)
            AutoComboBox->Items->Add(marca);

        FDQuery1->Next();
    }
    // umplem comboboxul cu celule din db
     FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
                          "WHERE pa.id_cod = :id_cod";
    FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
    FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}

//---------------------------------------------------------------------------

void __fastcall TAddFormG::AutoComboBoxKeyPress(TObject *Sender, System::WideChar &Key)
{
   if (Key != VK_RETURN)
        return;

	String a_name = AutoComboBox->Text;
	if (a_name == "") {
        AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
		CodComboBox->Items->Clear();
		CodComboBox->Clear();
		CelulaComboBox->Clear();
		FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
		}

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod "
							  "FROM code_table ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod = FDQuery1->FieldByName("cod")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
			if (CodComboBox->Items->IndexOf(cod) == -1)
				CodComboBox->Items->Add(cod);

            FDQuery1->Next();
		}

        FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}

	FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT a_id FROM vehicle_table WHERE a_marca_model = :a_name";
	FDQuery1->ParamByName("a_name")->AsWideString = a_name;
	FDQuery1->Open();

	int a_id = -1;
    if (!FDQuery1->IsEmpty()) {
		a_id = FDQuery1->FieldByName("a_id")->AsInteger;
    } else {

		CodComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod FROM code_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod_name = FDQuery1->FieldByName("cod")->AsString;

			if (CodComboBox->Items->IndexOf(cod_name) == -1)
				CodComboBox->Items->Add(cod_name);

            FDQuery1->Next();
        }

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT nume_celula FROM celula_table";
        FDQuery1->Open();

		while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;
            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);
			FDQuery1->Next();
        }
        return;
    }

    FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT ct.cod FROM product_auto_table pa "
						  "JOIN vehicle_table a ON a.a_id = pa.a_id "
						  "JOIN code_table ct ON ct.id_cod = pa.id_cod "
						  "WHERE a.a_id = :a_id";
    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
    FDQuery1->Open();

    CodComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    while (!FDQuery1->Eof) {

		String cod_name = FDQuery1->FieldByName("cod")->AsString;

		if (CodComboBox->Items->IndexOf(cod_name) == -1)
			CodComboBox->Items->Add(cod_name);

        FDQuery1->Next();
    }

	FDQuery1->Close();

    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
						  "WHERE pa.a_id = :a_id";

    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
	FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TAddFormG::AutoComboBoxSelect(TObject *Sender)
{
	String a_name = AutoComboBox->Text;
	if (a_name == "") {
        AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
		CodComboBox->Items->Clear();
		CodComboBox->Clear();
		CelulaComboBox->Clear();
		FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
		}

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod "
							  "FROM code_table ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod = FDQuery1->FieldByName("cod")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
			if (CodComboBox->Items->IndexOf(cod) == -1)
				CodComboBox->Items->Add(cod);

            FDQuery1->Next();
		}

        FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}

	FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT a_id FROM vehicle_table WHERE a_marca_model = :a_name";
	FDQuery1->ParamByName("a_name")->AsWideString = a_name;
	FDQuery1->Open();

	int a_id = -1;
    if (!FDQuery1->IsEmpty()) {
		a_id = FDQuery1->FieldByName("a_id")->AsInteger;
	}
	   else {

		CodComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod FROM code_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod_name = FDQuery1->FieldByName("cod")->AsString;

			if (CodComboBox->Items->IndexOf(cod_name) == -1)
				CodComboBox->Items->Add(cod_name);

            FDQuery1->Next();
        }

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT nume_celula FROM celula_table";
        FDQuery1->Open();

		while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;
            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);
			FDQuery1->Next();
        }
        return;
    }

    FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT ct.cod FROM product_auto_table pa "
						  "JOIN vehicle_table a ON a.a_id = pa.a_id "
						  "JOIN code_table ct ON ct.id_cod = pa.id_cod "
						  "WHERE a.a_id = :a_id";
    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
    FDQuery1->Open();

    CodComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    while (!FDQuery1->Eof) {
		String cod_name = FDQuery1->FieldByName("cod")->AsString;

		if (CodComboBox->Items->IndexOf(cod_name) == -1)
			CodComboBox->Items->Add(cod_name);

        FDQuery1->Next();
    }

	FDQuery1->Close();

    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
						  "WHERE pa.a_id = :a_id";

    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
	FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}

//---------------------------------------------------------------------------

void __fastcall TAddFormG::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_ESCAPE)
		this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAddFormG::CodComboBoxExit(TObject *Sender)
{
	String cod_name = CodComboBox->Text;
	if (cod_name == "") {

		AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
        AutoComboBox->Clear();
        CelulaComboBox->Clear();

        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}
    int cod_id = -1;

	// Verifică dacă există codul în baza de date
    FDQuery1->SQL->Text = "SELECT id_cod FROM code_table WHERE cod = :cod_name";
    FDQuery1->ParamByName("cod_name")->AsString = cod_name;
    FDQuery1->Open();

    if (!FDQuery1->IsEmpty()) {
        // Codul există, extrage id_cod
		cod_id = FDQuery1->FieldByName("id_cod")->AsInteger;
        FDQuery1
            ->Close(); // Închide FDQuery1 înainte de a face o altă interogare
    } else {
        // Dacă nu există, întreabă utilizatorul dacă dorește să adauge un produs nou
        if (MessageDlg(
                L"Nu există informaţii la acest cod,\nDoriţi să adăugaţi un produs nou?",
                mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
		{
            Close();
            return;
        }

        // Dacă utilizatorul răspunde cu "Yes", încarcă mașinile și celulele
        AutoComboBox->Items->Clear();
        CelulaComboBox->Items->Clear();

        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
        }

        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }
        return;
    }
    FDQuery1->Close();

	FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                          "FROM product_auto_table pa "
                          "JOIN vehicle_table a ON a.a_id = pa.a_id "
                          "JOIN code_table ct ON ct.id_cod = pa.id_cod "
                          "WHERE ct.id_cod = :id_cod ";
    FDQuery1->ParamByName("id_cod")->AsString = cod_id;
    FDQuery1->Open();

    AutoComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    // umplem combo boxul automobile si modelele lor cu datele din db
    while (!FDQuery1->Eof) {
        String marca = FDQuery1->FieldByName("a_marca_model")->AsWideString;

        if (AutoComboBox->Items->IndexOf(marca) == -1)
            AutoComboBox->Items->Add(marca);

        FDQuery1->Next();
    }
    // umplem comboboxul cu celule din db
     FDQuery1->Close();
    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
                          "WHERE pa.id_cod = :id_cod";
    FDQuery1->ParamByName("id_cod")->AsInteger = cod_id;
    FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}

//---------------------------------------------------------------------------

void __fastcall TAddFormG::AutoComboBoxExit(TObject *Sender)
{
  String a_name = AutoComboBox->Text;
	if (a_name == "") {
        AutoComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();
		CodComboBox->Items->Clear();
		CodComboBox->Clear();
        CelulaComboBox->Clear();
		FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT a.a_marca_model "
                              "FROM vehicle_table a ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String marca = FDQuery1->FieldByName("a_marca_model")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
            if (AutoComboBox->Items->IndexOf(marca) == -1)
                AutoComboBox->Items->Add(marca);

            FDQuery1->Next();
		}

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod "
							  "FROM code_table ";

        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod = FDQuery1->FieldByName("cod")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate
			if (CodComboBox->Items->IndexOf(cod) == -1)
				CodComboBox->Items->Add(cod);

            FDQuery1->Next();
		}

        FDQuery1->Close();
        FDQuery1->SQL->Text = "SELECT nume_celula "
                              "FROM celula_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;

            // Adaugă elemente în ComboBox doar dacă nu sunt deja adăugate

            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);

            FDQuery1->Next();
        }

        return;
	}

	FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT a_id FROM vehicle_table WHERE a_marca_model = :a_name";
	FDQuery1->ParamByName("a_name")->AsWideString = a_name;
	FDQuery1->Open();

	int a_id = -1;
    if (!FDQuery1->IsEmpty()) {
		a_id = FDQuery1->FieldByName("a_id")->AsInteger;
	}
	   else {

		CodComboBox->Items->Clear();
		CelulaComboBox->Items->Clear();

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT cod FROM code_table";
        FDQuery1->Open();

        while (!FDQuery1->Eof) {
			String cod_name = FDQuery1->FieldByName("cod")->AsString;

			if (CodComboBox->Items->IndexOf(cod_name) == -1)
				CodComboBox->Items->Add(cod_name);

            FDQuery1->Next();
        }

        FDQuery1->Close();
		FDQuery1->SQL->Text = "SELECT nume_celula FROM celula_table";
        FDQuery1->Open();

		while (!FDQuery1->Eof) {
            String celula = FDQuery1->FieldByName("nume_celula")->AsString;
            if (CelulaComboBox->Items->IndexOf(celula) == -1)
                CelulaComboBox->Items->Add(celula);
			FDQuery1->Next();
        }
        return;
    }

    FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT ct.cod FROM product_auto_table pa "
						  "JOIN vehicle_table a ON a.a_id = pa.a_id "
						  "JOIN code_table ct ON ct.id_cod = pa.id_cod "
						  "WHERE a.a_id = :a_id";
    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
    FDQuery1->Open();

    CodComboBox->Items->Clear();
    CelulaComboBox->Items->Clear();

    while (!FDQuery1->Eof) {
		String cod_name = FDQuery1->FieldByName("cod")->AsString;

		if (CodComboBox->Items->IndexOf(cod_name) == -1)
			CodComboBox->Items->Add(cod_name);

        FDQuery1->Next();
    }

	FDQuery1->Close();

    FDQuery1->SQL->Text = "SELECT c.nume_celula FROM product_auto_table pa "
                          "JOIN celula_table c ON c.id_celula = pa.celula_id "
						  "WHERE pa.a_id = :a_id";

    FDQuery1->ParamByName("a_id")->AsInteger = a_id;
	FDQuery1->Open();

    while (!FDQuery1->Eof) {
        String nume_celula = FDQuery1->FieldByName("nume_celula")->AsString;
        if (CelulaComboBox->Items->IndexOf(nume_celula) == -1)
            CelulaComboBox->Items->Add(nume_celula);
        FDQuery1->Next();
	}
}
//---------------------------------------------------------------------------

