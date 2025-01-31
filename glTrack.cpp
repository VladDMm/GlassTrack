//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.MySQL.hpp>

#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>

#include "algorithm"

#include "glTrack.h"
#include "AddGlass.h"
#include "EditForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMenuForm* MenuForm;
TFDMemTable* FDPhysMySQLDriverLink1;

//---------------------------------------------------------------------------

__fastcall TMenuForm::TMenuForm(TComponent* Owner) : TForm(Owner) {}

//---------------------------------------------------------------------------

__fastcall TMenuForm::~TMenuForm()
{
    delete FDPhysMySQLDriverLink1;
}

//---------------------------------------------------------------------------

// Crearea Formei Principale

void __fastcall TMenuForm::FormCreate(TObject* Sender)
{
    try {
        //        FDPhysMySQLDriverLink1->VendorLib = "C:\\Program Files\\MariaDB 11.4\\lib\\libmariadb.dll";
        //
        //        FDConnection1->Params->Clear();
        //        FDConnection1->Params->Add("DriverID=MySQL");
        //        FDConnection1->Params->Add("Server=127.0.0.1");
        //        FDConnection1->Params->Add("Database=glasstrack_db");
        //        FDConnection1->Params->Add("User_Name=root");
        //        FDConnection1->Params->Add("Password=root");
        //        FDConnection1->LoginPrompt = false;

		// DBGrid1->Columns->Items[9]->ReadOnly = true;

        FDConnection1->LoginPrompt = false;
        FDConnection1->Connected = true; // Conectare la baza de date
        FormShow(this);
        FormResize(this);

    } catch (Exception &e) {
        ShowMessage("Eroare la conectare: " + e.Message);
    }
}
//---------------------------------------------------------------------------

// Functie pentru redimensionarea formei pe baza marimii zonei client si nr coloane

void __fastcall TMenuForm::FormResize(TObject* Sender)
{
    DBGrid1->AlignWithMargins = true; // Activăm alinierea cu margini

    int gridWidth = DBGrid1->ClientWidth; // Lățimea disponibilă
    int colCount = DBGrid1->Columns->Count; // Numărul total de coloane

    if (colCount <= 1) // Dacă există doar ID-ul sau nicio coloană, ieșim
        return;

    int totalMargin =
        DBGrid1->Margins->Left + DBGrid1->Margins->Right; // Marginea totală
    int effectiveWidth =
        gridWidth - totalMargin - 10; // Scădem 10 pixeli pentru a incapea datele pe forma

    int visibleCols = colCount - 1; // Excludem coloana ID
    int baseColWidth = effectiveWidth / visibleCols;
    int remainingWidth = effectiveWidth % visibleCols;

    for (int i = 0; i < colCount; i++) {
        if (DBGrid1->Columns->Items[i]->FieldName == "id") {
            DBGrid1->Columns->Items[i]->Width = 0; // Ascundem ID-ul
        } else {
            DBGrid1->Columns->Items[i]->Width =
                baseColWidth - 1; // Reducem cu 1 pixel fiecare coloană
        }
    }

    // Distribuim pixelii rămași pentru a evita marginile goale
    for (int i = 0; i < remainingWidth; i++) {
        DBGrid1->Columns->Items[i % visibleCols]->Width += 1;
    }
}
//-----------------------------------------------------------------------------

// Deschiderea Formei pentru Adaugare Produs

void __fastcall TMenuForm::AddButtonClick(TObject* Sender)
{
    AddFormG = new TAddFormG(this);
    AddFormG->ShowModal();
	delete AddFormG;
    FormShow(this);
}

//---------------------------------------------------------------------------

// Functie pentru a adauga datele din db in DBGrid

void __fastcall TMenuForm::FormShow(TObject* Sender)
{
    try {
        FDQuery1->Close();
        FDQuery1->SQL->Text =
            "SELECT pp.pa_id, a.a_marca, a.a_model, p.p_name, ct.cod, p.p_origine, c.nume_celula, p.p_count, p.p_price "
            "FROM product_auto_table pp "
            "JOIN vehicle_table a ON a.a_id = pp.a_id "
            "JOIN celula_table c ON c.id_celula = pp.celula_id "
            "JOIN code_table ct ON ct.id_cod = pp.id_cod "
            "JOIN product_table p ON p.p_id = pp.p_id ";

		FDQuery1->Open();
		FormResize(MenuForm);

    } catch (Exception &e) {
        ShowMessage("Eroare la încărcarea datelor: " + e.Message);
    }
}

//---------------------------------------------------------------------------

// Functie buton Refresh ca sa adauge si sa redimensioneze datele in DBGrid
void __fastcall TMenuForm::Button1Click(TObject* Sender)
{
    FormShow(this);
    FormResize(this);
}

//---------------------------------------------------------------------------

// Functie pentru afisarea rezultatelor cautate in SearchBox

void __fastcall TMenuForm::SearchBoxChange(TObject* Sender)
{
    String searchText = SearchBox->Text.Trim();

    try {
        FDQuery1->Close();
        FDQuery1->SQL->Text =
            "SELECT pp.pa_id, a.a_marca, a.a_model, p.p_name, ct.cod, p.p_origine, c.nume_celula, p.p_count, p.p_price "
            "FROM product_auto_table pp "
            "JOIN vehicle_table a ON a.a_id = pp.a_id "
            "JOIN celula_table c ON c.id_celula = pp.celula_id "
            "JOIN product_table p ON p.p_id = pp.p_id "
            "JOIN code_table ct ON ct.id_cod = pp.id_cod "
            "WHERE a.a_marca LIKE :searchText OR a.a_model LIKE :searchText "
            "OR ct.cod LIKE :searchText OR p.p_name LIKE :searchText "
            "OR c.nume_celula LIKE :searchText OR p.p_origine LIKE :searchText";

        FDQuery1->ParamByName("searchText")->AsString = "%" + searchText + "%";

        FDQuery1->Open();
        FormResize(this);
    } catch (Exception &e) {
        ShowMessage("Eroare la actualizarea datelor: " + e.Message);
    }
}

//---------------------------------------------------------------------------

// La apasarea tastei DELETE sa se stearga randul selectat

void __fastcall TMenuForm::DBGrid1KeyDown(
    TObject* Sender, WORD &Key, TShiftState Shift)

{
    if (Key == VK_DELETE) // daca s-a apasat tasta Delete
    {
        if (FDQuery1->RecordCount == 0)
            return; //

        if (Application->MessageBox(L"Sigur doriți să ștergeți acest rând?",
                L"Confirmare", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            try {
                int pa_id = FDQuery1->FieldByName("pa_id")
                                ->AsInteger; // id-ul randului selectat

                FDQuery1->Close();
                FDQuery1->SQL->Text =
                    "DELETE FROM product_auto_table WHERE pa_id = :pa_id";
                FDQuery1->ParamByName("pa_id")->AsInteger = pa_id;
                FDQuery1->ExecSQL();

                FDQuery1->Close();

                ShowMessage(L"Rândul a fost șters cu succes.");
                FormShow(this);
            } catch (Exception &e) {
                ShowMessage(L"Eroare la ștergere: " + e.Message);
            }
        }
    }
}
//---------------------------------------------------------------------------

// La click dreapta si alegerea vanzarii produsului de vanzare sa scada cantitatea lui

void __fastcall TMenuForm::MenuItemVindeClick(TObject* Sender)
{
    int pa_id = FDQuery1->FieldByName("pa_id")->AsInteger; // preia randul selectat
    if (FDQuery1->Active) {
        FDQuery1->Close();
    }
    FormShow(this);
    if (MessageDlg(L"Doreşti să vinzi produsul?", mtConfirmation,
            TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)

    {   // Daca e apasat No atunci se reafiseaza datele
		FormShow(this);
		return;
    } else {    // Daca e apasat Yes atunci se vinde produsul
        FDQuery1->SQL->Text =
            "UPDATE product_table SET p_count = p_count - 1 "
            "WHERE p_id = (SELECT p_id FROM product_auto_table WHERE pa_id = :pa_id) "
            "AND p_count > 0";
        FDQuery1->ParamByName("pa_id")->AsInteger = pa_id;
		FDQuery1->ExecSQL();
        // Afisarea datelor actualizate
        FormShow(this);
        ShowMessage(L"Produs Vândut!");
    }
}

//---------------------------------------------------------------------------

// Apelarea formei Edit pentru editarea randului selectat

void __fastcall TMenuForm::MenuItemEditClick(TObject* Sender)
{
    if (FDQuery1->IsEmpty()) {
        ShowMessage("Nu există rând selectat.");
        return;
    }

    int pa_id = FDQuery1->FieldByName("pa_id")->AsInteger;  // id rand
	// Deschiderea Formei pentru editare, se transmite  id-ul randului,
	TEditFormProduct* EditForm = new TEditFormProduct(this, FDQuery1, pa_id);

	if (EditForm->ShowModal() == mrOk) {
		FormShow(this);// se reafiseaza datele
	}

	delete EditForm;
	FormShow(this);
}

//---------------------------------------------------------------------------

// Daca cantitatea produsului este pe 0 se afiseaza randul cu rosu

void __fastcall TMenuForm::DBGrid1DrawColumnCell(TObject* Sender,
    const TRect &Rect, int DataCol, TColumn* Column, TGridDrawState State)
{
    int p_count =
        DBGrid1->DataSource->DataSet->FieldByName("p_count")->AsInteger;

    if (p_count == 0) {
        DBGrid1->Canvas->Brush->Color =
            clRed; // Fundal rosu pentru produse epuizate
        DBGrid1->Canvas->Font->Color = clWhite; // Text alb
    }

    DBGrid1->Canvas->FillRect(Rect);
    DBGrid1->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
