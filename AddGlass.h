//---------------------------------------------------------------------------

#ifndef AddGlassH
#define AddGlassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TAddFormG : public TForm
{
  __published: // IDE-managed Components
    TComboBox* AutoComboBox;
    TLabel* Label1;
    TLabel* Label4;
    TEdit* CountEdit;
    TEdit* PriceEdit;
    TButton* AddButton;
    TButton* CancelButton;
    TFDQuery* FDQuery1;
    TLabel* Label7;
    TComboBox* CelulaComboBox;
    TComboBox* CodComboBox;
    void __fastcall CancelButtonClick(TObject* Sender);
    void __fastcall Initialize_Component();
    void __fastcall AddButtonClick(TObject* Sender);
    void __fastcall FormCreate(TObject* Sender);
    //	void __fastcall AutoComboBoxChange(TObject *Sender);
    void __fastcall CodComboBoxKeyPress(TObject* Sender, System::WideChar &Key);
    void __fastcall CodComboBoxSelect(TObject* Sender);
    void __fastcall AutoComboBoxKeyPress(
        TObject* Sender, System::WideChar &Key);
    void __fastcall AutoComboBoxSelect(TObject* Sender);
    void __fastcall FormKeyDown(TObject* Sender, WORD &Key, TShiftState Shift);
    void __fastcall CodComboBoxExit(TObject* Sender);
	void __fastcall AutoComboBoxExit(TObject *Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TAddFormG(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddFormG* AddFormG;
//---------------------------------------------------------------------------
#endif

