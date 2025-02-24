//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("glTrack.cpp", MenuForm);
USEFORM("LoadData.cpp", LoadDataForm);
USEFORM("AddGlass.cpp", AddFormG);
USEFORM("EditForm.cpp", EditFormProduct);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMenuForm), &MenuForm);
		Application->CreateForm(__classid(TAddFormG), &AddFormG);
		Application->CreateForm(__classid(TEditFormProduct), &EditFormProduct);
		Application->CreateForm(__classid(TLoadDataForm), &LoadDataForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);

		}
	}
	return 0;
}
//---------------------------------------------------------------------------
