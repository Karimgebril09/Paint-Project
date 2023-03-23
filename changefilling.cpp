#include"changefilling.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


changefilling::changefilling(ApplicationManager* pApp) :Action(pApp)
{
	UndoOrRedo = 0;
}

void changefilling::ReadActionParameters()
{
	colortype = pManager->GetUserAction();

}

bool changefilling::Execute(bool readparams )
{
	Output* pOut = pManager->GetOutput();
	CFigure* selected = pManager->getselectpointer();
	if (selected)//check if there is any selected figure
	{
		pOut->CreateColorBar();
		pOut->PrintMessage("choose a color or press any where to return");
		if (readparams == true)//if used in recording, sleep to show color tool bar
			ReadActionParameters();
		else
			Sleep(1000);
		switch (colortype)//change the drawing color of the selected figure and the next figures
		{
		case COL_BLUE:
			selected->ChngFillClr(BLUE);
			UI.FillColor = BLUE;
			break;
		case COL_GREEN:
			selected->ChngFillClr(GREEN);
			UI.FillColor = GREEN;
			break;
		case COL_RED:
			selected->ChngFillClr(RED);
			UI.FillColor = RED;
			break;
		case COL_ORANGE:
			selected->ChngFillClr(ORANGE);
			UI.FillColor = ORANGE;
			break;
		case COL_BLACK:
			selected->ChngFillClr(BLACK);
			UI.FillColor = BLACK;
			break;
		case COL_YELLOW:
			selected->ChngFillClr(YELLOW);
			UI.FillColor = YELLOW;
			break;
		}
		UI.isfilled = true;
		pOut->CreateDrawToolBar();
	}
	else
	{
		pOut->PrintMessage("you must select a figure first to change filling color");
	}
	if (selected)
		pManager->AddAct(this);
	return false;
}

bool changefilling::record_me() const
{
	return true;
}

void changefilling::Undo()
{
	if (pManager->SearchFor(prevfig)) 
	{
		CFigure* x = pManager->SearchFor(prevfig);
		bool temp1;
		color temp2;

		temp1 = PrevIsFilledUI;
		PrevIsFilledUI = UI.isfilled;
		UI.isfilled = temp1;

		temp2 = PrevColorUI;
		PrevColorUI = UI.FillColor;
		UI.FillColor = temp2;
		x->ChngFillClr(UI.FillColor, UndoOrRedo);
	}
}

void changefilling::Redo()
{
	UndoOrRedo = 1;
	Undo();
	UndoOrRedo = 0;
}
