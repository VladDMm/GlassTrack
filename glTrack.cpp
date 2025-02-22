#include <vcl.h>
#pragma hdrstop

#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.MySQL.hpp>

#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <Vcl.Controls.hpp>

#include "algorithm"

#include "glTrack.h"
#include "AddGlass.h"
#include "EditForm.h"
#include "LoadData.h"
#include <ustring.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMenuForm* MenuForm;
TFDMemTable* FDPhysMySQLDriverLink1;

//---------------------------------------------------------------------------

__fastcall TMenuForm::TMenuForm(TComponent* Owner) : TForm(Owner)
{
    logger = new logg::LogF("log/", "log.txt", 5);
	logger->info("CONSTRUCTOR", "Initializare constructor pentru TMenuForm.");
}

//---------------------------------------------------------------------------

__fastcall TMenuForm::~TMenuForm()
{
    if (logger) {
		logger->info("DESTRUCTOR", "Inchiderea aplicatiei si eliberarea resurselor.");
        delete logger;
        logger = nullptr;
    } else {
        // Dacă logger-ul a fost deja șters sau nu a fost inițializat corect
		ShowMessage(L"[WARNING] Logger inexistent in destructor.");
    }

    delete FDPhysMySQLDriverLink1;
}


//---------------------------------------------------------------------------

// Crearea Formei Principale

void __fastcall TMenuForm::FormCreate(TObject* Sender)
{
    try {
		logger->info("FormCreate", "Initiere creare forma si conexiune la baza de date.");

        FDConnection1->LoginPrompt = false;
        FDConnection1->Connected = true; // Conectare la baza de date

		logger->trace("FormCreate", "Conexiunea la baza de date a fost stabilita cu succes.");

        FormShow(this);
        FormResize(this);

        logger->info("FormCreate", "S-a creat forma cu succes.");

    } catch (Exception &e) {
        AnsiString ansiMessage = AnsiString(e.Message);
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

        logger->exception(61, "FormCreate",
            "Eroare la conectare: %s. Inchidere program.", my_str.c_str());

        ShowMessage(L"Eroare la conectare: " + e.Message);
        Application->Terminate();
    }
}

//---------------------------------------------------------------------------

// Functie pentru redimensionarea formei pe baza marimii zonei client si nr coloane

void __fastcall TMenuForm::FormResize(TObject* Sender)
{
	logger->debug("FormResize", "Apel functie pentru redimensionare forma.");

    DBGrid1->AlignWithMargins = true; // Activăm alinierea cu margini

    int gridWidth = DBGrid1->ClientWidth; // Lățimea disponibilă
    int colCount = DBGrid1->Columns->Count; // Numărul total de coloane

    logger->trace("FormResize", "Latime grid: %d, Numar coloane: %d", gridWidth, colCount);

    if (colCount <= 1) // Dacă există doar ID-ul sau nicio coloană, ieșim
    {
		logger->debug("FormResize", "Numar insuficient de coloane (%d). Iesire functie.", colCount);
        return;
    }

    int totalMargin = DBGrid1->Margins->Left + DBGrid1->Margins->Right; // Marginea totală
    int effectiveWidth = gridWidth - totalMargin - 10; // Scădem 10 pixeli pentru ajustare

    int visibleCols = colCount - 1; // Excludem coloana ID
    int baseColWidth = effectiveWidth / visibleCols;
    int remainingWidth = effectiveWidth % visibleCols;

    logger->trace("FormResize", "Latime efectiva: %d, Latime coloana: %d, Pixeli ramasi: %d",
                  effectiveWidth, baseColWidth, remainingWidth);

    for (int i = 0; i < colCount; i++) {
        if (DBGrid1->Columns->Items[i]->FieldName == "id") {
            DBGrid1->Columns->Items[i]->Width = 0; // Ascundem ID-ul
            logger->trace("FormResize", "Coloana 'id' ascunsă.");
        } else {
            DBGrid1->Columns->Items[i]->Width = baseColWidth - 1; // Reducem cu 1 pixel fiecare coloană
        }
    }

    // Distribuim pixelii rămași pentru a evita marginile goale
    for (int i = 0; i < remainingWidth; i++) {
        DBGrid1->Columns->Items[i % visibleCols]->Width += 1;
    }

    logger->debug("FormResize", "Redimensionarea grilei a fost finalizata.");
}

//-----------------------------------------------------------------------------

// Deschiderea Formei pentru Adaugare Produs

void __fastcall TMenuForm::AddButtonClick(TObject* Sender)
{
	logger->debug("AddButtonClick", "Butonul 'Adaugare' a fost apasat. Se creeaza fereastra de adaugare.");

    AddFormG = new TAddFormG(this);
	logger->info("AddButtonClick", "Fereastra 'Adaugare' a fost creata.");

    AddFormG->ShowModal();

    delete AddFormG;
	logger->trace("AddButtonClick", "Fereastra 'Adaugare' a fost distrusa.");

    logger->debug("AddButtonClick", "Se reincarcă datele in grid.");
    FormShow(this);
}


//---------------------------------------------------------------------------

// Functie pentru a adauga datele din db in DBGrid

void __fastcall TMenuForm::FormShow(TObject* Sender)
{
	logger->info("FormShow", "Functia FormShow a fost apelata.");

    try {
        FDQuery1->Close();

        std::string query =
            "SELECT pp.pa_id, a.a_marca_model, ct.cod, c.nume_celula, pp.p_count, pp.p_price "
            "FROM product_auto_table pp "
            "JOIN vehicle_table a ON a.a_id = pp.a_id "
            "JOIN celula_table c ON c.id_celula = pp.celula_id "
            "JOIN code_table ct ON ct.id_cod = pp.id_cod";

		logger->debug("FormShow", "Execut interogarea SQL.");

        FDQuery1->SQL->Text = query.c_str();

		logger->trace("FormShow", "Interogare SQL generata: %s", query.c_str());
		FDQuery1->Open();

        FormResize(MenuForm);
        logger->info("FormShow", "Datele au fost afisate cu succes în grid.");
    }
    catch (Exception &e) {
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

		logger->warning(WARN_DATA_LOAD_FAIL, "FormShow", "Eroare CRITICA la încarcarea datelor: %s", my_str.c_str());
        ShowMessage(L"Eroare CRITICA la incarcarea datelor: " + e.Message);
    }
}


//---------------------------------------------------------------------------

// Functie pentru afisarea rezultatelor cautate in SearchBox

void __fastcall TMenuForm::SearchBoxChange(TObject* Sender)
{
    logger->info("SearchBoxChange", "Functia de cautare a fost apelata.");

    String searchText = SearchBox->Text.Trim();
    std::wstring my_wstr = searchText.c_str();
    std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

    logger->debug("SearchBoxChange", "Valoarea searchText: %s", my_str.c_str());

    try {
        FDQuery1->Close();

        std::string search_query =
            "SELECT pp.pa_id, a.a_marca_model, ct.cod, c.nume_celula, pp.p_count, pp.p_price "
            "FROM product_auto_table pp "
            "JOIN vehicle_table a ON a.a_id = pp.a_id "
            "JOIN celula_table c ON c.id_celula = pp.celula_id "
            "JOIN code_table ct ON ct.id_cod = pp.id_cod "
            "WHERE a.a_marca_model LIKE :searchText "
            "OR ct.cod LIKE :searchText OR pp.p_price LIKE :searchText "
            "OR pp.p_count LIKE :searchText";

		logger->debug("SearchBoxChange", "Execut interogarea SQL.");

        FDQuery1->SQL->Text = search_query.c_str();
        FDQuery1->ParamByName("searchText")->AsString = "%" + searchText + "%";

		logger->trace("SearchBoxChange", "Interogare SQL generata: %s", search_query.c_str());
		FDQuery1->Open();

        FormResize(this);
		logger->info("SearchBoxChange", "Cautarea s-a finalizat cu succes.");
    }
    catch (Exception &e) {
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

		logger->warning(WARN_SQL_SEARCH, "SearchBoxChange", "Eroare la cautarea datelor: %s", my_str.c_str());
        ShowMessage(L"Eroare la afişarea datelor din cautare: " + e.Message);
    }
}


//---------------------------------------------------------------------------

//
void __fastcall TMenuForm::ConfirmDialogKeyDown(
    TObject* Sender, WORD &Key, TShiftState Shift)
{
    logger->trace("ConfirmDialogKeyDown", "Tasta apasata: %d", Key);

    if (Key == VK_SPACE) {
		logger->debug("ConfirmDialogKeyDown", "Tasta SPACE a fost blocata.");
        Key = 0;
    }
}


//---------------------------------------------------------------------------

// La apasarea tastei DELETE sa se stearga randul selectat

int __fastcall TMenuForm::ShowConfirmationDeleteDialog()
{
    TForm* ConfirmDialog = new TForm(this);
    ConfirmDialog->Caption = "Confirmare";
    ConfirmDialog->Position = poScreenCenter;
    ConfirmDialog->BorderStyle = bsDialog;
    ConfirmDialog->Width = 300;
    ConfirmDialog->Height = 150;

    TLabel* Label = new TLabel(ConfirmDialog);
    Label->Parent = ConfirmDialog;
    Label->Caption = L"Doreşti să ştergi produsul?";
    Label->Left = 50;
    Label->Top = 30;
    Label->AutoSize = true;

    TButton* YesButton = new TButton(ConfirmDialog);
    YesButton->Parent = ConfirmDialog;
    YesButton->Caption = "Da";
    YesButton->ModalResult = mrYes;
    YesButton->Left = 50;
    YesButton->Top = 70;

    TButton* NoButton = new TButton(ConfirmDialog);
    NoButton->Parent = ConfirmDialog;
    NoButton->Caption = "Nu";
    NoButton->ModalResult = mrNo;
    NoButton->Left = 150;
    NoButton->Top = 70;
    NoButton->Cancel = true;
    NoButton->TabStop = true;

    // Permite procesarea tastelor înainte de controalele din fereastră
    ConfirmDialog->KeyPreview = true;

    // Asociază metoda ConfirmDialogKeyDown
    ConfirmDialog->OnKeyDown = ConfirmDialogKeyDown;

    int Result = ConfirmDialog->ShowModal();
    delete ConfirmDialog;
    return Result;
}

//
void __fastcall TMenuForm::DBGrid1KeyDown(
    TObject* Sender, WORD &Key, TShiftState Shift)
{
    logger->trace("DBGrid1KeyDown", "Functia a fost apelata");

    if (Key == VK_DELETE) // dacă s-a apăsat tasta Delete
    {
        if (FDQuery1->RecordCount == 0) {
			logger->warning(WARN_NO_SELECTED_ROW, "DBGrid1KeyDown", "Nu exista rand selectat!");
            ShowMessage(L"Nu există rând selectat!");
            return;
        }

        int Result = ShowConfirmationDeleteDialog();
        if (Result != mrYes) { // Acceptă doar mrYes pentru ștergere
            logger->info("DBGrid1KeyDown", "Stergerea a fost anulata de utilizator.");
            return;
        }

        try {
            int pa_id = FDQuery1->FieldByName("pa_id")->AsInteger; // ID-ul rândului selectat
            logger->debug("DBGrid1KeyDown", "ID rand selectat pentru stergere: %d", pa_id);

            logger->info("DBGrid1KeyDown", "Incepe stergerea produsului ID: %d", pa_id);

            FDQuery1->Close();
            FDQuery1->SQL->Text = "DELETE FROM product_auto_table WHERE pa_id = :pa_id";
            FDQuery1->ParamByName("pa_id")->AsInteger = pa_id;
            FDQuery1->ExecSQL();

            FDQuery1->Close();

			logger->info("DBGrid1KeyDown", "Produsul a fost sters cu succes.");
            ShowMessage(L"Produsul a fost șters cu succes.");
            FormShow(this);
        } catch (Exception &e) {
            std::wstring my_wstr = e.Message.c_str();
            std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);
			logger->warning(WARN_DELETE_FAILED, "DBGrid1KeyDown", "Eroare la stergere: %s", my_str.c_str());
            ShowMessage(L"Eroare la ștergere: " + e.Message);
        }
    }

    logger->trace("DBGrid1KeyDown", "Functia s-a incheiat");
}

//---------------------------------------------------------------------------

// La click dreapta si alegerea vanzarii produsului de vanzare sa scada cantitatea lui

int __fastcall TMenuForm::ShowConfirmationDialog()
{
    TForm* ConfirmDialog = new TForm(Application);
    ConfirmDialog->Caption = "Confirmare";
    ConfirmDialog->Position = poScreenCenter;
    ConfirmDialog->BorderStyle = bsDialog;
    ConfirmDialog->Width = 300;
    ConfirmDialog->Height = 150;

    TLabel* Label = new TLabel(ConfirmDialog);
    Label->Parent = ConfirmDialog;
    Label->Caption = "Doreşti să vinzi produsul?";
    Label->Left = 50;
    Label->Top = 30;
    Label->AutoSize = true;

    TButton* YesButton = new TButton(ConfirmDialog);
    YesButton->Parent = ConfirmDialog;
    YesButton->Caption = "Da";
    YesButton->ModalResult = mrYes;
    YesButton->Left = 50;
    YesButton->Top = 70;

    // Permite procesarea tastelor înainte de controalele din fereastră
    ConfirmDialog->KeyPreview = true;

    TButton* NoButton = new TButton(ConfirmDialog);
    NoButton->Parent = ConfirmDialog;
    NoButton->Caption = "Nu";
    NoButton->ModalResult = mrNo;
    NoButton->Left = 150;
    NoButton->Top = 70;
    NoButton->Cancel = true;

    // Eveniment pentru prevenirea confirmării la Space
    ConfirmDialog->OnKeyDown = ConfirmDialogKeyDown;

    int Result = ConfirmDialog->ShowModal();
    delete ConfirmDialog;
    return Result;
}

void __fastcall TMenuForm::MenuItemVindeClick(TObject* Sender)
{
	logger->trace("MenuItemVindeClick", "Functia a fost apelata");

    if (!FDQuery1->Active || FDQuery1->IsEmpty()) {
        logger->warning(WARN_NO_SELECTED_PRODUCT, "MenuItemVindeClick", "Nu exista un produs selectat!");
        ShowMessage(L"Nu există un produs selectat!");
        return;
    }

    int pa_id = FDQuery1->FieldByName("pa_id")->AsInteger; // Preia id-ul produsului
    logger->debug("MenuItemVindeClick", "ID produs selectat: %d", pa_id);

    int Result = ShowConfirmationDialog();
    if (Result != mrYes) { // Acceptă doar mrYes pentru vânzare
        logger->info("MenuItemVindeClick", "Vanzare anulata de utilizator.");
        return;
    }

    try {
        logger->info("MenuItemVindeClick", "Incepe actualizarea bazei de date pentru ID: %d", pa_id);

        FDQuery1->Close();
        FDQuery1->SQL->Text = "UPDATE product_auto_table SET p_count = p_count - 1 "
                              "WHERE pa_id = :pa_id AND p_count > 0";
        FDQuery1->ParamByName("pa_id")->AsInteger = pa_id;
        FDQuery1->ExecSQL();

        FormShow(this);
        logger->info("MenuItemVindeClick", "Produs vandut cu succes!");
        ShowMessage(L"Produs Vândut!");
    }
    catch (Exception &e) {
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);
        logger->warning(WARN_SQL_UPDATE, "MenuItemVindeClick", "Eroare la actualizarea bazei de date: %s", my_str.c_str());
        ShowMessage(L"Eroare la vânzare: " + e.Message);
    }

    logger->trace("MenuItemVindeClick", "Funcția s-a încheiat");
}


//---------------------------------------------------------------------------

void __fastcall TMenuForm::MenuItemEditClick(TObject* Sender)
{
    logger->trace("MenuItemEditClick", "Functia a fost apelata");

    if (FDQuery1->IsEmpty()) {
        logger->warning(WARN_NO_SELECTED_ROW, "MenuItemEditClick", "Nu exista rand selectat.");
        ShowMessage(L"Nu există rând selectat.");
        return;
    }

    int pa_id = FDQuery1->FieldByName("pa_id")->AsInteger; // id rand
    logger->debug("MenuItemEditClick", "ID rand selectat: %d", pa_id);

    logger->info("MenuItemEditClick", "Deschiderea formei de editare pentru ID: %d", pa_id);
    TEditFormProduct* EditForm = new TEditFormProduct(this, FDQuery1, pa_id);

    if (EditForm->ShowModal() == mrOk) {
        logger->info("MenuItemEditClick", "Editare confirmata, reafisare date.");
        FormShow(this);
    }

    delete EditForm;
    FormShow(this);

    logger->trace("MenuItemEditClick", "Functia s-a încheiat");
}


//---------------------------------------------------------------------------

// Daca cantitatea produsului este pe 0 se afiseaza randul cu alta culoare

void __fastcall TMenuForm::DBGrid1DrawColumnCell(TObject* Sender,
    const TRect &Rect, int DataCol, TColumn* Column, TGridDrawState State)
{
    int p_count =
        DBGrid1->DataSource->DataSet->FieldByName("p_count")->AsInteger;
	bool isSelected = (State.Contains(gdSelected));

	if (p_count == 0 && !isSelected) {
        DBGrid1->Canvas->Brush->Color = clInfoBk; // Fundal pentru produse epuizate
        DBGrid1->Canvas->Font->Color = clInactiveCaptionText; // Text alb
        DBGrid1->Canvas->FillRect(Rect);
    }

    if (!isSelected || p_count != 0) {
        DBGrid1->DefaultDrawColumnCell(Rect, DataCol, Column, State);
	}
}

//---------------------------------------------------------------------------

void __fastcall TMenuForm::Button2Click(TObject* Sender)
{
    logger->trace("Button2Click", "Functia a fost apelata");

    logger->debug("Button2Click", "Se creeaza formularul TLoadDataForm.");
    TLoadDataForm* LoadForm = new TLoadDataForm(this, FDQuery1);

    if (LoadForm->ShowModal() == mrOk) {
        logger->info("Button2Click", "Utilizatorul a confirmat (mrOk). Se reafisează datele.");
        FormShow(this); // Se reafisează datele
    }

	logger->debug("Button2Click", "Se sterge formularul TLoadDataForm.");
    delete LoadForm;

	logger->info("Button2Click", "Se reafisează datele în FormShow.");
	FormShow(this);

    logger->trace("Button2Click", "Functia s-a incheiat");
}

//---------------------------------------------------------------------------

void __fastcall TMenuForm::SearchBoxClick(TObject* Sender)
{
    SearchBox->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMenuForm::SearchBoxKeyDown(
    TObject* Sender, WORD &Key, TShiftState Shift)
{
	logger->trace("SearchBoxKeyDown", "Functia a fost apelata");
	logger->debug("SearchBoxKeyDown", "Tasta apasata: %d", Key);

    if (Key == VK_ESCAPE) {
		logger->info("SearchBoxKeyDown", "S-a apasat ESC. Se sterge continutul cautarii.");
        SearchBox->Clear();
    }

    logger->trace("SearchBoxKeyDown", "Functia s-a incheiat");
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TMenuForm::DBGrid1TitleClick(TColumn* Column)
{
    logger->trace("DBGrid1TitleClick", "Functia a fost apelata");

    static bool sortAsc = true;
    String sortOrder = sortAsc ? "ASC" : "DESC";

    logger->debug("DBGrid1TitleClick", "Ordonarea în mod: %s", sortOrder.c_str());

    String columnName = Column->FieldName; // Obține numele câmpului
    if (columnName == "cod") {
        logger->info("DBGrid1TitleClick", "Sortarea ignorata pentru coloana 'cod'");
        return;
    }

    try {
        logger->info("DBGrid1TitleClick", "Utilizatorul a apasat pe coloana: %s", columnName.c_str());

        FDQuery1->Close();
        FDQuery1->SQL->Text =
            "SELECT pp.pa_id AS pa_id, "
            "a.a_marca_model AS a_marca_model, "
            "ct.cod AS cod, "
            "c.nume_celula AS nume_celula, "
            "pp.p_count AS p_count, "
            "pp.p_price AS p_price "
            "FROM product_auto_table pp "
            "JOIN vehicle_table a ON a.a_id = pp.a_id "
            "JOIN celula_table c ON c.id_celula = pp.celula_id "
            "JOIN code_table ct ON ct.id_cod = pp.id_cod "
            "ORDER BY " +
            columnName + " " + sortOrder;

        logger->trace("DBGrid1TitleClick", "Interogarea SQL este: %s", FDQuery1->SQL->Text.c_str());

        FDQuery1->Open();
        sortAsc = !sortAsc;

        logger->info("DBGrid1TitleClick", "Sortare realizata cu succes pentru coloana: %s", columnName.c_str());
    }
    catch (Exception &e) {
        AnsiString ansiMessage = AnsiString(e.Message);
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

        logger->warning(WARN_SQL_SORT, "DBGrid1TitleClick", "Eroare la sortare: %s", my_str.c_str());

        ShowMessage(L"Eroare la sortare: " + e.Message);
    }

    logger->trace("DBGrid1TitleClick", "Functia s-a incheiat");
}


//---------------------------------------------------------------------------

void __fastcall TMenuForm::Timer1Timer(TObject* Sender)
{
    logger->trace("Timer1Timer", "Functia a fost apelata");

    try {
        logger->info("Timer1Timer", "Se incearca reconectarea la baza de date...");
        FDConnection1->Connected = true;
		logger->info("Timer1Timer", "Conectare reusita.");
    }
    catch (Exception &e) {
        AnsiString ansiMessage = AnsiString(e.Message);
        std::wstring my_wstr = e.Message.c_str();
        std::string my_str = std::wstring_convert<std::codecvt_utf8_utf16<System::Char>>{}.to_bytes(my_wstr);

        logger->warning(WARN_NO_RESPONSE_SERVER, "Timer1Timer", "Eroare la conectare: %s", my_str.c_str());
        logger->exception(606, "Timer1Timer", "Conexiune esuata! Aplicatia se va inchide. Mesaj: %s", my_str.c_str());

        ShowMessage(L"Eroare la conectare: " + e.Message);
        Application->Terminate();
    }

    logger->trace("Timer1Timer", "Functia s-a incheiat");
}

//---------------------------------------------------------------------------

