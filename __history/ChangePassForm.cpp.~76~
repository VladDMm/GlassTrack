//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangePassForm.h"
#include "glTrack.h"
#include "Log.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTChangePassForm* TChangePassForm;
extern logg::LogF* logger;
//---------------------------------------------------------------------------
__fastcall TTChangePassForm::TTChangePassForm(
    TComponent* Owner, TFDQuery* query) :
    TForm(Owner),
    FDQuery1(query)
{
    logger->info(
        logger->charToWString(__func__).c_str(), L"Constructor initializat");
}

//--------------------------------------------------------------------------

UnicodeString HashPassword(const UnicodeString &password)
{
    return THashSHA2::GetHashString(password, THashSHA2::TSHA2Version::SHA256);
}

//-------------------------------------------------------------------------

bool VerifyOldPassword(TFDQuery*&query, const UnicodeString &oldPassword)
{
    UnicodeString hashedOldPass = HashPassword(oldPassword);

    try {
        query->SQL->Text =
            L"SELECT COUNT(*) FROM pass_table WHERE password = :pass";
        query->ParamByName(L"pass")->AsString = hashedOldPass;
        query->Open();

        int count = query->Fields->Fields[0]->AsInteger;
        return count > 0; // Dacă există cel puțin o parolă, este corectă
    } catch (...) {
        return false;
    }
}

//-------------------------------------------------------------------------

void __fastcall TTChangePassForm::UpdatePasswordInDB(
    TFDQuery*&query, const UnicodeString &newPassword)
{
    UnicodeString hashedNewPass = HashPassword(newPassword);

    try {
        logger->info(
            logger->charToWString(__func__).c_str(), L"Functie apelata");
        logger->debug(logger->charToWString(__func__).c_str(),
            L"Schimbare parola %s", newPassword.w_str());
        FDQuery1->SQL->Text =
            L"UPDATE pass_table SET password = :newPass WHERE pass_id = 1";
        FDQuery1->ParamByName(L"newPass")->AsString = hashedNewPass;
        FDQuery1->ExecSQL();
        logger->trace(logger->charToWString(__func__).c_str(),
            L"Interogarea sql generata %s", FDQuery1->SQL->Text.w_str());
    } catch (...) {
        ShowMessage(L"Eroare la actualizarea parolei!");
        logger->debug(logger->charToWString(__func__).c_str(),
            L"Eroare la actualizarea parolei!");
    }
}

//---------------------------------------------------------------------------

void __fastcall TTChangePassForm::ConfirmButtonClick(TObject* Sender)
{
    logger->info(logger->charToWString(__func__).c_str(), L"Functie apelata");

    UnicodeString oldPass = OldPassEdit->Text.Trim();
    UnicodeString newPass = NewPassEdit->Text.Trim();

    if (oldPass.IsEmpty() || newPass.IsEmpty()) {
        logger->debug(logger->charToWString(__func__).c_str(),
            L"Nu s-au introdus toate campurile");
        ShowMessage(L"Introduceți toate câmpurile!");
        return;
    }

    TFDQuery* newFDQuery = new TFDQuery(this);
    newFDQuery->Connection = FDQuery1->Connection;

    try {
        if (!VerifyOldPassword(newFDQuery, oldPass)) {
            ShowMessage(L"Parola veche este incorectă!");
            logger->debug(logger->charToWString(__func__).c_str(),
                L"Parola veche nu coincide");
            delete newFDQuery;
            return;
        }

        UpdatePasswordInDB(newFDQuery, newPass);
        ShowMessage(L"Parola a fost schimbată cu succes!");
        logger->debug(logger->charToWString(__func__).c_str(),
            L"Parola a fost schimbată cu succes!");

        this->Close();
    } catch (const Exception &e) {
        String str = e.Message.c_str();
        logger->warning(WARN_SAVE_DATA_TO_DB,
            logger->charToWString(__func__).c_str(), L"Eroare la salvare:",
            str.w_str());
        ShowMessage(L"Eroare: " + e.Message);
    }

    delete newFDQuery;
}

//---------------------------------------------------------------------------

