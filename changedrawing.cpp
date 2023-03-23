#include"changedrawing.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

changedrawing::changedrawing(ApplicationManager* pApp) :Action(pApp)
{
}

void changedrawing::ReadActionParameters()
{
	colortype = pManager->GetUserAction();
}


bool changedrawing::Execute(bool readparams )
{
	Output* pOut = pManager->GetOutput();
	CFigure* selected = pManager->getselectpointer();
	if (selected)  //check if there is any selected figure
	{
		pOut->CreateColorBar();
		if (readparams == true) //if used in recording, sleep to show color tool bar
			ReadActionParameters(); 
		else
			Sleep(1000);
		switch (colortype) //change the drawing color of the selected figure and the next figures
		{
		case COL_BLUE:
			selected->ChngDrawClr(BLUE);
			UI.DrawColor = BLUE;
			break;
		case COL_GREEN:
			selected->ChngDrawClr(GREEN);
			UI.DrawColor = GREEN;
			break;
		case COL_RED:
			selected->ChngDrawClr(RED);
			UI.DrawColor = RED;
			break;
		case COL_ORANGE:
			selected->ChngDrawClr(ORANGE);
			UI.DrawColor = ORANGE;
			break;
		case COL_BLACK:
			selected->ChngDrawClr(BLACK);
			UI.DrawColor = BLACK;
			break;
		case COL_YELLOW:
			selected->ChngDrawClr(YELLOW);
			UI.DrawColor = YELLOW;
			break;
		}
		pOut->CreateDrawToolBar();
	}
	else
	{
		pOut->PrintMessage("you must select a figure first to change drawing color");
	}
	if (selected)
		pManager->AddAct(this);
	return false;
}
bool changedrawing::record_me() const
{
	return true;
}
void changedrawing::Undo()
{
	if (pManager->SearchFor(prevfig))
	{
		CFigure* x = pManager->SearchFor(prevfig);
		color temp2;

		temp2 = PrevColorUI;
		PrevColorUI = UI.DrawColor;
		UI.DrawColor = temp2;
		x->ChngDrawClr(UI.DrawColor);
	}
}

void changedrawing::Redo()
{
	Undo();
}