//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include "IniFiles.hpp"
#include <windows.h>
#include <StrUtils.hpp>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <exception>
#include <stdexcept>
#pragma hdrstop

#include "UnitMain.h"
#include "GeoPoint.h"
#include "Const.h"
#include "Converter.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
TIniFile *Ini = new TIniFile(ExtractFilePath(ParamStr(0))+INI_NAME);
void CopyÑoordinates();
void LoadIni();
void ShowError(string text, string header);
void CreateFile(GeoPoint pointMin, GeoPoint pointMax,
				double boxSize, UnicodeString alphabet, GeoPoint lengthPlanet,
				char* hlmns, UnicodeString filePath);
GeoPoint NewStep(double angle, double box_size, GeoPoint lengthPlanet,
				GeoPoint pointI, double rad);
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	LoadIni();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormActivate(TObject *Sender)
{
	CopyÑoordinates();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ComboBoxBoxSizeChange(TObject *Sender)
{
	Ini->WriteString(INI_BOX,INI_SIZE,ComboBoxBoxSize->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ComboBoxPointsTypeChange(TObject *Sender)
{
	string lang;
	if (ComboBoxPointsType->ItemIndex == 0) lang = INI_EN;
	else if (ComboBoxPointsType->ItemIndex == 1) lang = INI_RU;
	else lang = INI_NUM;
	Ini->WriteString(INI_POINT,INI_TYPE,lang.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonCopyÑoordinatesClick(TObject *Sender)
{
	CopyÑoordinates();
}
//---------------------------------------------------------------------------
void LoadIni()
{
	FormMain->ComboBoxBoxSize->Text = Ini->ReadString(INI_BOX,INI_SIZE,BOX_SIZE_DEFAULT);
	if (Ini->ReadString(INI_POINT,INI_TYPE,POINT_TYPE_DEFAULT) == INI_EN)
		FormMain->ComboBoxPointsType->ItemIndex = 0;
	else if (Ini->ReadString(INI_POINT,INI_TYPE,POINT_TYPE_DEFAULT) == INI_RU)
		FormMain->ComboBoxPointsType->ItemIndex = 1;
	else
		FormMain->ComboBoxPointsType->ItemIndex = 2;
}
//---------------------------------------------------------------------------
void CopyÑoordinates()
{
	ifstream file_in(POINTS_FILE);
	string line;
	if (file_in.is_open()) {
		while (getline(file_in, line))
        {
			if (line.find(POINT_LON_MIN) == 0)
				FormMain->EditLon1->Text = (line.substr(strlen(POINT_LON_MIN)).c_str());
			else if (line.find(POINT_LAT_MIN) == 0)
				FormMain->EditLat1->Text = (line.substr(strlen(POINT_LAT_MIN)).c_str());
			else if (line.find(POINT_LON_MAX) == 0)
				FormMain->EditLon2->Text = (line.substr(strlen(POINT_LON_MAX)).c_str());
			else if (line.find(POINT_LAT_MAX) == 0)
				FormMain->EditLat2->Text = (line.substr(strlen(POINT_LAT_MAX)).c_str());
		}
	} else {
		ShowError(ERROR_LAST_SELECTION, ERROR_LAST_SELECTION_HEADER);
    }
	file_in.close(); 
}
//---------------------------------------------------------------------------
void ShowError(string text, string header)
{
	MessageBox(NULL, text.c_str(), header.c_str(), MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonSaveClick(TObject *Sender)
{
	ButtonSave->Enabled = false;
	ProgressBar->Position = 0;

	GeoPoint pointMin;
	GeoPoint pointMax;
	GeoPoint lengthPlanet(
		(Ini->ReadString(INI_SETTING,INI_PLANET_LAT,PLANET_LAT_DEFAULT)).ToDouble(),
		(Ini->ReadString(INI_SETTING,INI_PLANET_LON,PLANET_LON_DEFAULT)).ToDouble());
	Ini->WriteString(INI_SETTING,INI_PLANET_LAT,lengthPlanet.lat);
	Ini->WriteString(INI_SETTING,INI_PLANET_LON,lengthPlanet.lon);

	if(IsNum(EditLat1->Text))
		pointMin.lat = OnDouble(EditLat1->Text);
	else {
		ShowError(ERROR_INPUT_LAT_1,ERROR_INPUT_POINT_HEADER);
		return;
	}

	if(IsNum(EditLon1->Text))
		pointMin.lon = OnDouble(EditLon1->Text);
	else {
		ShowError(ERROR_INPUT_LON_1,ERROR_INPUT_POINT_HEADER);
		return;
	}

	if(IsNum(EditLat2->Text))
		pointMax.lat = OnDouble(EditLat2->Text);
	else {
		ShowError(ERROR_INPUT_LAT_2,ERROR_INPUT_POINT_HEADER);
		return;
	}

	if(IsNum(EditLon2->Text))
		pointMax.lon = OnDouble(EditLon2->Text);
	else {
		ShowError(ERROR_INPUT_LON_2,ERROR_INPUT_POINT_HEADER);
		return;
	}

	if (pointMin.lat < pointMax.lat) {
		ShowError(ERROR_LAT_MORE,ERROR_INPUT_POINT_HEADER);
		return;
	}

	if (pointMin.lon > pointMax.lon) {
		ShowError(ERROR_LON_MORE,ERROR_INPUT_POINT_HEADER);
		return;
	}

    double boxSize = 0;
	if(IsNum(ComboBoxBoxSize->Text))
		boxSize = OnDouble(ComboBoxBoxSize->Text);
	else {
		ShowError(ERROR_INPUT_BOX_SIZE,ERROR_INPUT_BOX_HEADER);
		return;
	}

	UnicodeString alphabet = "";
	if(ComboBoxPointsType->ItemIndex == 0 || ComboBoxPointsType->ItemIndex == 1 || ComboBoxPointsType->ItemIndex == 2) {
		if (ComboBoxPointsType->ItemIndex == 0){
			alphabet = Ini->ReadString(INI_POINT,INI_ALPHABET_EN,ALPHABET_EN_DEFAULT);
			Ini->WriteString(INI_POINT,INI_ALPHABET_EN,alphabet.c_str());
		} else if (ComboBoxPointsType->ItemIndex == 1){
			alphabet = Ini->ReadString(INI_POINT,INI_ALPHABET_RU,ALPHABET_RU_DEFAULT);
			Ini->WriteString(INI_POINT,INI_ALPHABET_RU,alphabet.c_str());
		} else
			alphabet = "";
	} else {
		ShowError(ERROR_INPUT_POINTS_TYPE,ERROR_INPUT_BOX_HEADER);
		return;
	}

	if (SaveDialog->Execute()) {
		try
		{
			SaveDialog->InitialDir = Ini->ReadString(INI_FILE, INI_LAST, "");
			CreateFile(pointMin, pointMax, boxSize, alphabet, lengthPlanet,
				(char*)XML_HLMNS, SaveDialog->FileName);
			Ini->WriteString(INI_FILE,INI_LAST,SaveDialog->FileName);
        }
		catch(exception e)
		{
        }
	}
	ButtonSave->Enabled = true;
	ProgressBar->Position = 0;
}
//---------------------------------------------------------------------------
GeoPoint NewStep(double angle, double box_size, GeoPoint lengthPlanet, GeoPoint pointI, double rad)
{
	double lat = (360.0 * sin(angle) * box_size) / lengthPlanet.lat;
	double lon = (360.0 * cos(angle) * box_size) / (lengthPlanet.lon * cos(pointI.lat * rad));
	GeoPoint step(lat,lon);
	return step;
}
//---------------------------------------------------------------------------
void CreateFile(GeoPoint pointMin, GeoPoint pointMax,
				double boxSize, UnicodeString alphabet, GeoPoint lengthPlanet,
				char* xmlns, UnicodeString filePath)
{
	Application->ProcessMessages();
	FormMain->ProgressBar->Position = PROGRESSBAR_START;

	TFormatSettings dateTimeFormat;
	dateTimeFormat.DateSeparator = GPX_DATESEPARATOR;
	dateTimeFormat.TimeSeparator = GPX_TIMESEPARATOR;
	dateTimeFormat.LongTimeFormat = GPX_TIMEFORMAT;

	_di_IXMLDocument XMLDocument = NewXMLDocument();
	XMLDocument->Active = true;
	XMLDocument->Options = XMLDocument->Options << doNodeAutoIndent;	
	XMLDocument->Version = XML_VERSION;
	XMLDocument->Encoding = XML_ENCODING;
	XMLDocument->StandAlone = XML_STANDALONE;
	IXMLNode *gpx = XMLDocument->AddChild(GPX);
	gpx->SetAttribute(GPX_XMLNS,xmlns);
	gpx->SetAttribute(GPX_CREATOR,GPX_CREATOR_VALUE);
	gpx->SetAttribute(GPX_VERSION,GPX_VERSION_VALUE);
	gpx->SetAttribute(GPX_XMLNS_XSI,GPX_XMLNS_XSI_VALUE);
	gpx->SetAttribute(GPX_XSI_SCHEMALOCATION,GPX_XSI_SCHEMALOCATION_VALUE);
	IXMLNode *nodMetadata = gpx->AddChild(GPX_METADATA,xmlns);
	IXMLNode *nodTime = nodMetadata->AddChild(GPX_TIME);
	string stringTime = AnsiString(DateTimeToStr(Now(),dateTimeFormat)).c_str();
	stringTime.erase(0,1); //fix
	nodTime->SetText(stringTime.c_str());
	IXMLNode *nodBounds = nodMetadata->AddChild(GPX_BOUNDS);
	FormMain->ProgressBar->Position = PROGRESSBAR_SECOND;
	Application->ProcessMessages();

	GeoPoint pointI = pointMin;
	GeoPoint step;
	int countX = 0;
	int countY = 0;
	while (pointI.lat - (step.lat / 2) > pointMax.lat){
		step = NewStep(ANGLEDOWN, boxSize, lengthPlanet, pointI, RAD);
		pointI.Step(step);
		countY++;
		Application->ProcessMessages();
	}
	pointI = pointMin;
	step.Clear();

	while (pointI.lon - (step.lon / 2) < pointMax.lon){
		step = NewStep(ANGLERIGHT, boxSize, lengthPlanet, pointI, RAD);
		pointI.Step(step);
		countX++;
		Application->ProcessMessages();
	}
	vector<vector<GeoPoint> > points(countY);

	pointI = pointMin;
	GeoPoint pointFirstInLine = pointMin;
	for (int j = 0; j < countY; ++j) {
		points[j].resize(countX);
		for (int i = 0; i < countX; ++i) {
			pointI.NewTitle(j,i,AnsiString(alphabet).c_str());
			points[j][i] = pointI;
			pointI.Step(NewStep(ANGLERIGHT, boxSize, lengthPlanet, pointI, RAD));
		}
		pointI = pointFirstInLine;
		pointI.Step(NewStep(ANGLEDOWN, boxSize, lengthPlanet, pointI, RAD));
		pointFirstInLine = pointI;
		Application->ProcessMessages();
	}

	nodBounds->SetAttribute(GPX_MINLAT,AnsiReplaceStr(pointMin.lat,",","."));
	nodBounds->SetAttribute(GPX_MINLON,AnsiReplaceStr(pointMin.lon,",","."));
	nodBounds->SetAttribute(GPX_MAXLAT,AnsiReplaceStr(pointMax.lat,",","."));
	nodBounds->SetAttribute(GPX_MAXLON,AnsiReplaceStr(pointMax.lon,",","."));

	IXMLNode *nodTrk = gpx->AddChild(GPX_TRK,xmlns);
	IXMLNode *nodTrkName = nodTrk->AddChild(GPX_NAME,xmlns);
	nodTrkName->SetText(GPX_GRID);
	IXMLNode *nodTrkSeg = nodTrk->AddChild(GPX_TRKSEG,xmlns);

	FormMain->ProgressBar->Position = PROGRESSBAR_THIRD;
	Application->ProcessMessages();

	float floatProgress = FormMain->ProgressBar->Position;
	float stepProgess = (PROGRESSBAR_FULL - floatProgress - PROGRESSBAR_SAVEFILE) / (countY + countX);

	for (int j = 0; j < countY; ++j) {
		for (int i = 0; i < countX; ++i) {
			IXMLNode *nodWpt = gpx->AddChild(GPX_WPT,xmlns);
			nodWpt->SetAttribute(GPX_LAT,AnsiReplaceStr(points[j][i].lat,",","."));
			nodWpt->SetAttribute(GPX_LON,AnsiReplaceStr(points[j][i].lon,",","."));
			IXMLNode *nodTrkPt = nodTrkSeg->AddChild(GPX_TRKPT,xmlns);
			nodTrkPt->SetAttribute(GPX_LAT,AnsiReplaceStr(points[j][i].lat,",","."));
			nodTrkPt->SetAttribute(GPX_LON,AnsiReplaceStr(points[j][i].lon,",","."));
			IXMLNode *nodWptName = nodWpt->AddChild(GPX_NAME);
			nodWptName->SetText(points[j][i].title.c_str());
		}
        IXMLNode *nodTrkPt = nodTrkSeg->AddChild(GPX_TRKPT,xmlns);
		nodTrkPt->SetAttribute(GPX_LAT,AnsiReplaceStr(points[j][0].lat,",","."));
		nodTrkPt->SetAttribute(GPX_LON,AnsiReplaceStr(points[j][0].lon,",","."));
		floatProgress += stepProgess;
		FormMain->ProgressBar->Position = floatProgress;
		Application->ProcessMessages();
	}
	for (int i = countX-1; i >= 0; --i) {
		for (int j = countY-1; j >= 0; --j) {
			IXMLNode *nodTrkPt = nodTrkSeg->AddChild(GPX_TRKPT,xmlns);
			nodTrkPt->SetAttribute(GPX_LAT,AnsiReplaceStr(points[j][i].lat,",","."));
			nodTrkPt->SetAttribute(GPX_LON,AnsiReplaceStr(points[j][i].lon,",","."));
		}
		IXMLNode *nodTrkPt = nodTrkSeg->AddChild(GPX_TRKPT,xmlns);
		nodTrkPt->SetAttribute(GPX_LAT,AnsiReplaceStr(points[countY-1][i].lat,",","."));
		nodTrkPt->SetAttribute(GPX_LON,AnsiReplaceStr(points[countY-1][i].lon,",","."));
		floatProgress += stepProgess;
		FormMain->ProgressBar->Position = floatProgress;
		Application->ProcessMessages();
	}

	FormMain->ProgressBar->Position = PROGRESSBAR_FULL - PROGRESSBAR_SAVEFILE;
	Application->ProcessMessages();
	XMLDocument->SaveToFile(filePath);
	FormMain->ProgressBar->Position = PROGRESSBAR_FULL;
    MessageBox(NULL, FILE_READY, READY, MB_OK);
}
//---------------------------------------------------------------------------
