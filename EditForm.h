﻿//---------------------------------------------------------------------------

#ifndef EditFormH
#define EditFormH
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
class TEditFormProduct : public TForm
{
__published:	// IDE-managed Components
	TEdit *CodEdit;
	TEdit *CountEdit;
	TEdit *PriceEdit;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *AutoEdit;
	TEdit *CelulaEdit;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *ConfirmButton;
	TButton *CancelButton;
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall ConfirmButtonClick(TObject *Sender);
	void __fastcall CancelButtonKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
	TFDQuery* FDQuery1; // Adaugă un membru pentru query-ul primit
    int ProductId;
public:		// User declarations
	__fastcall TEditFormProduct(TComponent* Owner, TFDQuery* query, int pa_id);

};
//---------------------------------------------------------------------------
extern PACKAGE TEditFormProduct *EditFormProduct;
//---------------------------------------------------------------------------
#endif
