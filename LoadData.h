//---------------------------------------------------------------------------

#ifndef LoadDataH
#define LoadDataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>

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
class TLoadDataForm : public TForm
{
__published:	// IDE-managed Components
	TButton *AddFileButton;
	TEdit *PathEdit;
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TButton *ConfirmButton;
	void __fastcall AddFileButtonClick(TObject *Sender);
	void __fastcall ConfirmButtonClick(TObject *Sender);
    void __fastcall ResizeStringGrid();
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
	TFDQuery* FDQuery1;
public:		// User declarations
	__fastcall TLoadDataForm(TComponent* Owner, TFDQuery* query);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoadDataForm *LoadDataForm;
//---------------------------------------------------------------------------
#endif
