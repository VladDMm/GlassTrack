//---------------------------------------------------------------------------

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
	TButton *Button1;
	TFDUpdateSQL *FDUpdateSQL1;
	TFDAutoIncField *FDQuery1pa_id;
	TStringField *FDQuery1a_marca;
	TStringField *FDQuery1a_model;
	TStringField *FDQuery1p_code;
	TStringField *FDQuery1p_origine;
	TIntegerField *FDQuery1p_count;
	TFMTBCDField *FDQuery1p_price;
	TStringField *FDQuery1nume_sectie;
	TStringField *FDQuery1nume_celula;
	TPopupMenu *PopupMenu1;
	TMenuItem *MenuItemVinde;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);
	//void __fastcall Initialize_Component();
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SearchBoxChange(TObject *Sender);
	void __fastcall FDQuery1AfterPost(TDataSet *DataSet);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall FDQuery1CalcFields(TDataSet *DataSet);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall MenuItemVindeClick(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
private:	// User declarations
   //	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;  // Adăugat aici

public:		// User declarations
	__fastcall TMenuForm(TComponent* Owner);
    __fastcall ~TMenuForm(); // Destructor pentru a elibera memoria
};
//---------------------------------------------------------------------------
extern PACKAGE TMenuForm *MenuForm;
//---------------------------------------------------------------------------
#endif
