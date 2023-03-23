#include"Addhexagonaction.h"
#include "CHexagon.h"
#include<Windows.h>
#include<mmsystem.h>
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddhexaAction::AddhexaAction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound)//play sound when dawing hexagon
		PlaySound(TEXT("hexagon-select"), NULL, SND_SYNC);
}

void AddhexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagone: Click at any point");

	//Read center and store in point P1
	pIn->GetPointClicked(p1.x, p1.y);

	hexaGfxInfo.isFilled = UI.isfilled;	//default is not filled  
	//get drawing, filling colors and pen width from the interface
	hexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	hexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddhexaAction::Execute(bool readparams )
{
	//This action needs to read some parameters first
	if (readparams == true)
		ReadActionParameters();
	//Create a hexagon with the parameters read from the user
	CHexagon* hex = new CHexagon(p1,hexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(hex);
	pManager->UpdateInterface(); //update interface before playing the sound
	if (UI.sound)
		PlaySound(TEXT("hexagon-sound"), NULL, SND_SYNC);
	return false;
}

bool AddhexaAction::record_me() const
{
	return true;
}

void AddhexaAction::Undo()
{
}

void AddhexaAction::Redo()
{
}
