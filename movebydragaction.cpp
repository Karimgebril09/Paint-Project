#include"movebydragaction.h"
#include"ApplicationManager.h"
#include"movefigureaction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
movebydrag::movebydrag(ApplicationManager* pApp) :Action(pApp)
{
}

void movebydrag::ReadActionParameters()
{
}


bool movebydrag::Execute(bool readparams )
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* selected = pManager->getselectpointer();
	if (selected)
	{
		pOut->PrintMessage("DRAG FIGURE");

		while (!(pIn->getmousestate(p.x, p.y)))   //waits until the mouse state is down
		{
		}
		CFigure* check = pManager->GetFigure(p.x, p.y);
		while (pIn->getmousestate(p.x, p.y) && check == selected) //while mouse state is down gets point and draw it
		{
			Sleep(5);
			selected->movefig(p);   //change the figure to the new coordinate
			pManager->UpdateInterface();   //draw the figure with the new position
		}
	}
	else
	{
		pOut->PrintMessage("no selected figure");
	}
	return true;
}

bool movebydrag::record_me() const
{
	return false;
}
