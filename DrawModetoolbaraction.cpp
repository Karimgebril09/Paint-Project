#include"DrawModetoolbaraction.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "LoadAction.h"

DrawModetoolbaraction::DrawModetoolbaraction(ApplicationManager* pApp) :Action(pApp)
{}

void DrawModetoolbaraction::ReadActionParameters()
{
}


bool DrawModetoolbaraction::Execute(bool readparams)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	Action* lo = new LoadAction(pManager);
	lo->Execute(0);
	return true;
}

bool DrawModetoolbaraction::record_me() const
{
	return false;
}
