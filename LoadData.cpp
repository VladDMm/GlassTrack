﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoadData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoadDataForm* LoadDataForm;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <optional>

//---------------------------------------------------------------------------
__fastcall TLoadDataForm::TLoadDataForm(TComponent* Owner, TFDQuery* query) :
    TForm(Owner), FDQuery1(query)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::ResizeStringGrid()
{
    int colCount = StringGrid1->ColCount;
    int totalWidth =
        StringGrid1->Width - 20; // Lăsăm puțin spațiu pentru scrollbar

    for (int i = 0; i < colCount; i++) {
        StringGrid1->ColWidths[i] = totalWidth / colCount;
    }
}

//---------------------------------------------------------------------------

void __fastcall TLoadDataForm::AddFileButtonClick(TObject* Sender)
{
    if (OpenDialog1->Execute()) // fereastra explorer
    {
        String filePath = OpenDialog1->FileName; // calea fisierului
        PathEdit->Text = filePath; // afisare calea in edit1

        TStringList* fileContent = new TStringList();
        try {
            fileContent->LoadFromFile(filePath, TEncoding::UTF8); // încarcă fișierul

            if (fileContent->Count == 0) {
                Application->MessageBox(L"Fișierul este gol!", L"Eroare", MB_OK | MB_ICONERROR);
                delete fileContent;
                return;
            }

            // Verificăm prima linie pentru numărul de coloane
            TStringList* firstLineColumns = new TStringList();
            firstLineColumns->Delimiter = ';';
            firstLineColumns->StrictDelimiter = true;
            firstLineColumns->DelimitedText = fileContent->Strings[0];

            if (firstLineColumns->Count != 5) {
                Application->MessageBox(L"Fișierul trebuie să aibă exact 5 coloane!", L"Eroare", MB_OK | MB_ICONERROR);
                delete firstLineColumns;
                delete fileContent;
                return;
            }
            delete firstLineColumns;

            // Setează numărul de rânduri în StringGrid
            StringGrid1->RowCount = 1; // Resetăm tabelul și păstrăm header-ul
            StringGrid1->ColCount = 5; // numărul fix de coloane
            ResizeStringGrid();

            // Parcurgem fișierul linie cu linie
            for (int i = 0; i < fileContent->Count; i++) {
                String line = fileContent->Strings[i];
                TStringList* columns = new TStringList();
                columns->Delimiter = ';'; // Separator
                columns->StrictDelimiter = true;
                columns->DelimitedText = line;

                // Adăugăm un nou rând în StringGrid
                int newRow = StringGrid1->RowCount;
                StringGrid1->RowCount = newRow + 1;

                // Copiem datele în StringGrid
                for (int j = 0; j < columns->Count && j < StringGrid1->ColCount; j++) {
                    StringGrid1->Cells[j][newRow] = columns->Strings[j];
                }

                delete columns; // Eliberăm memoria pentru fiecare linie
            }
        } catch (...) {
            Application->MessageBox(L"Eroare la citirea fișierului!", L"Eroare", MB_OK | MB_ICONERROR);
        }

        delete fileContent; // Eliberăm memoria pentru fișier
    }
}


//---------------------------------------------------------------------------

// Funcție pentru corectarea formatului numerelor (ex. 1,000 → 1.000)
String fixNumberFormat(String value)
{
    value = StringReplace(value, ".", "", TReplaceFlags() << rfReplaceAll);
    value = StringReplace(value, ",", ".", TReplaceFlags() << rfReplaceAll);
    return value;
}

//-------------------------------------------------------------------------

// Functia de a adauga datele din StringGrid in baza de date

void __fastcall TLoadDataForm::ConfirmButtonClick(TObject* Sender)
{
    TFDQuery* newFDQuery = new TFDQuery(this);
    newFDQuery->Connection = FDQuery1->Connection;

    try {
        for (int i = 1; i < StringGrid1->RowCount; i++) {
            // Verificăm câte coloane sunt completate
            int colCount = 0;
            for (int j = 0; j < StringGrid1->ColCount; j++) {
                if (!StringGrid1->Cells[j][i].IsEmpty()) {
                    colCount++;
                }
            }
            UnicodeString celula = StringGrid1->Cells[0][i];
            UnicodeString cod_name = StringGrid1->Cells[1][i];
			UnicodeString marca = StringGrid1->Cells[2][i];

            int p_count =
                StrToFloatDef(fixNumberFormat(StringGrid1->Cells[3][i]), 0.0);
            double p_price =
                StrToFloatDef(fixNumberFormat(StringGrid1->Cells[4][i]), 0.0);

            // daca automobilul exista
            newFDQuery->SQL->Text =
                "SELECT a_id FROM vehicle_table WHERE a_marca_model = :marca";
            newFDQuery->ParamByName("marca")->AsWideString = marca;
            newFDQuery->Open();

            int a_id;
            if (!newFDQuery->IsEmpty()) {
                a_id = newFDQuery->FieldByName("a_id")->AsInteger;
            } else {
                newFDQuery->SQL->Text =
                    "INSERT INTO vehicle_table (a_marca_model) VALUES (:marca)";
                newFDQuery->ExecSQL();
                newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS new_a_id";
                newFDQuery->Open();
                a_id = newFDQuery->FieldByName("new_a_id")->AsInteger;
            }

            // daca celula exista
            newFDQuery->SQL->Text =
                "SELECT id_celula FROM celula_table WHERE nume_celula = :nume_celula";
            newFDQuery->ParamByName("nume_celula")->AsString = celula;
            newFDQuery->Open();

            int celula_id;
            if (!newFDQuery->IsEmpty()) {
                celula_id = newFDQuery->FieldByName("id_celula")->AsInteger;
            } else {
                newFDQuery->SQL->Text =
                    "INSERT INTO celula_table (nume_celula) VALUES (:nume_celula)";
                newFDQuery->ExecSQL();
                newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS celula_id";
                newFDQuery->Open();
                celula_id = newFDQuery->FieldByName("celula_id")->AsInteger;
            }

            // verificam daca codul exista
            newFDQuery->SQL->Text =
                "SELECT id_cod FROM code_table WHERE cod = :cod_name";
            newFDQuery->ParamByName("cod_name")->AsString = cod_name;
            newFDQuery->Open();

            int cod_id;
            if (!newFDQuery->IsEmpty()) {
                cod_id = newFDQuery->FieldByName("id_cod")->AsInteger;
            } else {
                newFDQuery->SQL->Text =
                    "INSERT INTO code_table (cod) VALUES (:cod_name)";
                newFDQuery->ExecSQL();
                newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS id_cod";
                newFDQuery->Open();
                cod_id = newFDQuery->FieldByName("id_cod")->AsInteger;
            }

            // Verificăm dacă produsul există deja în product_table
            //			newFDQuery->SQL->Text =
            //				"SELECT p_id FROM product_table WHERE p_count = :p_count AND p_price = :p_price";
            //			newFDQuery->ParamByName("p_count")->AsInteger = p_count;
            //			newFDQuery->ParamByName("p_price")->AsFloat = p_price;
            //			newFDQuery->Open();
            //
            //			int p_id;
            //			if (!newFDQuery->IsEmpty()) {
            //				p_id = newFDQuery->FieldByName("p_id")->AsInteger; // Dacă există, luăm id-ul
            //			} else {
            //				// Dacă nu există, îl inserăm
            //				newFDQuery->SQL->Text =
            //					"INSERT INTO product_table (p_count, p_price) VALUES (:p_count, :p_price)";
            //				newFDQuery->ExecSQL();
            //				newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS p_id";
            //				newFDQuery->Open();
            //				p_id = newFDQuery->FieldByName("p_id")->AsInteger;
            //			}

            // inseram produsul in product_table
            //			newFDQuery->SQL->Text =
            //				"INSERT INTO product_table (p_count, p_price) VALUES (:p_count, :p_price)";
            //			newFDQuery->ParamByName("p_count")->AsInteger = p_count;
            //			newFDQuery->ParamByName("p_price")->AsFloat = p_price;
            //			newFDQuery->ExecSQL();
            //
            //			// luam id produs inserat
            //			newFDQuery->SQL->Text = "SELECT LAST_INSERT_ID() AS p_id";
            //			newFDQuery->Open();
            //			int p_id = newFDQuery->FieldByName("p_id")->AsInteger;

            // Verificăm dacă produsul legat din product_auto_table  există deja

            //            newFDQuery->SQL->Text =
            //					"INSERT IGNORE INTO product_auto_table (a_id, celula_id, id_cod, p_count, p_price) VALUES (:a_id, :celula_id, :id_cod, :p_count, :p_price)";
            //				newFDQuery->ParamByName("a_id")->AsInteger = a_id;
            //				newFDQuery->ParamByName("celula_id")->AsInteger = celula_id;
            //				newFDQuery->ParamByName("id_cod")->AsInteger = cod_id;
            //				newFDQuery->ParamByName("p_count")->AsInteger = p_count;
            //				newFDQuery->ParamByName("p_price")->AsFloat = p_price;
            //				newFDQuery->ExecSQL();

            newFDQuery->SQL->Text =
                "SELECT 1 FROM product_auto_table WHERE a_id = :a_id AND celula_id = :celula_id AND id_cod = :id_cod";
            newFDQuery->ParamByName("a_id")->AsInteger = a_id;
            newFDQuery->ParamByName("celula_id")->AsInteger = celula_id;
            newFDQuery->ParamByName("id_cod")->AsInteger = cod_id;
            newFDQuery->Open();
            // Dacă nu există, îl inserăm
            if (newFDQuery->IsEmpty()) {
                newFDQuery->SQL->Text =
                    "INSERT IGNORE INTO product_auto_table (a_id, celula_id, id_cod, p_count, p_price) VALUES (:a_id, :celula_id, :id_cod, :p_count, :p_price)";
                newFDQuery->ParamByName("a_id")->AsInteger = a_id;
                newFDQuery->ParamByName("celula_id")->AsInteger = celula_id;
                newFDQuery->ParamByName("id_cod")->AsInteger = cod_id;
                newFDQuery->ParamByName("p_count")->AsInteger = p_count;
                newFDQuery->ParamByName("p_price")->AsFloat = p_price;
                newFDQuery->ExecSQL();
            }
        }

        ShowMessage("Datele au fost salvate cu succes!");
        delete newFDQuery;
        ModalResult = mrOk;
    } catch (Exception &e) {
        ShowMessage("Eroare la salvare: " + e.Message);
    }
}

//---------------------------------------------------------------------------

void __fastcall TLoadDataForm::FormResize(TObject* Sender)
{
    StringGrid1->AlignWithMargins = true;

    int gridWidth = StringGrid1->ClientWidth;
    int colCount = StringGrid1->ColCount;

    if (colCount <= 1) // Dacă nu avem date, ieșim
        return;

    int totalMargin = StringGrid1->Margins->Left + StringGrid1->Margins->Right;
    int effectiveWidth =
        gridWidth - totalMargin - 10; // Scădem un padding suplimentar

    int visibleCols = colCount - 1; // Excludem coloana ID
    int baseColWidth = effectiveWidth / visibleCols;
    int remainingWidth = effectiveWidth % visibleCols;

    // Setăm lățimea pentru toate coloanele (în afară de ID)
    for (int i = 1; i < colCount; i++)
    { // Începem de la 1, pentru a exclude ID-ul
        StringGrid1->ColWidths[i] = baseColWidth;
    }

    // Distribuim pixelii rămași pentru a evita marginile goale
    for (int i = 1; i <= remainingWidth; i++) {
        StringGrid1->ColWidths[i] += 1;
    }
}

//---------------------------------------------------------------------------



void __fastcall TLoadDataForm::FormKeyPress(TObject *Sender, System::WideChar &Key)

{
if(Key == VK_ESCAPE)
        this->Close();
}
//---------------------------------------------------------------------------

