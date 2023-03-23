#include "ResizeAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"

ResizeAction::ResizeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
}

bool ResizeAction::Execute(bool readparams)
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* selected = pManager->getselectpointer();
	if (selected)
	{
		pOut->PrintMessage("Select one of the corners");

		while (!(pIn->getmousestate(p.x, p.y)))
		{
		}
		bool check=selected->Am_I_Corner(p);
		while (pIn->getmousestate(p.x, p.y) && check)
		{
			Sleep(5);
			selected->Resize_Me(p);
			pManager->UpdateInterface();
		}
	}
	else
	{
		pOut->PrintMessage("no selected figure");
	}
	return true;
}

bool ResizeAction::record_me() const
{
	return false;
}

