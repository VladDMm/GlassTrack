﻿//---------------------------------------------------------------------------

#ifndef glTrackH
#define glTrackH
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
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include "EditForm.h"
#include <Datasnap.DBClient.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Log.h"

//---------------------------------------------------------------------------
class TMenuForm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TButton *AddButton;
	TEdit *SearchBox;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TFDConnection *FDConnection1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TLabel *Label1;
	TFDUpdateSQL *FDUpdateSQL1;
	TPopupMenu *PopupMenu1;
	TMenuItem *MenuItemVinde;
	TMenuItem *MenuItemEdit;
	TButton *Button2;
	TLongWordField *FDQuery1p_count;
	TLongWordField *FDQuery1p_price;
	TFDAutoIncField *FDQuery1pa_id;
	TMemoField *FDQuery1a_marca_model;
	TMemoField *FDQuery1cod;
	TMemoField *FDQuery1nume_celula;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	//void __fastcall DBGrid1MouseDown(TObject *Sender, TMouseButton Button,
    //  TShiftState Shift, int X, int Y);
	//void __fastcall Initialize_Component();
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall SearchBoxChange(TObject *Sender);
  //	void __fastcall FDQuery1AfterPost(TDataSet *DataSet);
   //	void __fastcall DBGrid1CellClick(TColumn *Column);
   //	void __fastcall FDQuery1CalcFields(TDataSet *DataSet);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall MenuItemVindeClick(TObject *Sender);
    void __fastcall FormShow(TObject* Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall MenuItemEditClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall SearchBoxClick(TObject *Sender);
    int __fastcall ShowConfirmationDeleteDialog();
	int __fastcall ShowConfirmationDialog();
	void __fastcall SearchBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations
   //	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	void __fastcall ConfirmDialogKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    logg::LogF* logger;

public:		// User declarations
	__fastcall TMenuForm(TComponent* Owner);
    __fastcall ~TMenuForm(); // Destructor pentru a elibera memoria
};
//---------------------------------------------------------------------------
extern PACKAGE TMenuForm *MenuForm;
//---------------------------------------------------------------------------
#endif
