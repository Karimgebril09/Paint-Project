#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"
#include<Windows.h>
#include<mmsystem.h>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
	if (UI.sound)//play sound when dawing rectangle
		PlaySound(TEXT("rectangle-select"), NULL, SND_SYNC);
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
		
	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddRectAction::Execute(bool readparams )
{
	//This action needs to read some parameters first
	if (readparams == true)
		ReadActionParameters();
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	pManager->UpdateInterface(); //update interface before playing sound
	if (UI.sound)
		PlaySound(TEXT("rectangle-sound"), NULL, SND_SYNC);
	return false;
}

bool AddRectAction::record_me() const
{
	return true;
}

void AddRectAction::Undo()
{
}

void AddRectAction::Redo()
{
}
