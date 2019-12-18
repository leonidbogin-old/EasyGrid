//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBoxStep1;
	TGroupBox *GroupBoxPoint1;
	TLabel *Label1;
	TEdit *EditLat1;
	TEdit *EditLon1;
	TLabel *Label2;
	TGroupBox *GroupBoxPoint2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditLat2;
	TEdit *EditLon2;
	TButton *ButtonCopy—oordinates;
	TGroupBox *GroupBoxStep2;
	TLabel *Label5;
	TComboBox *ComboBoxBoxSize;
	TLabel *Label6;
	TComboBox *ComboBoxPointsType;
	TGroupBox *GroupBoxStep3;
	TButton *ButtonSave;
	TSaveDialog *SaveDialog;
	TProgressBar *ProgressBar;
	void __fastcall ComboBoxBoxSizeChange(TObject *Sender);
	void __fastcall ComboBoxPointsTypeChange(TObject *Sender);
	void __fastcall ButtonCopy—oordinatesClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
