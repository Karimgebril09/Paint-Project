#include"Addsquareaction.h"
#include "Csquare.h"
#include<Windows.h>
#include<mmsystem.h>
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddsquareAction::AddsquareAction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound)//play sound when dawing square
		PlaySound(TEXT("square-select"), NULL, SND_SYNC);
}

void AddsquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New square: Click at any point");

	//Read center and store in point P1
	pIn->GetPointClicked(p1.x, p1.y);

	squGfxInfo.isFilled = UI.isfilled;	//default is not filled 
	//get drawing, filling colors and pen width from the interface
	squGfxInfo.DrawClr = pOut->getCrntDrawColor();
	squGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddsquareAction::Execute(bool readparams )
{
	//This action needs to read some parameters first
	if (readparams == true)
		ReadActionParameters();

	//Create a square with the parameters read from the user
	Csquare* squ = new Csquare(p1, squGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(squ);
	pManager->UpdateInterface();//update interface before playing sound
	if (UI.sound)
		PlaySound(TEXT("square-sound"), NULL, SND_SYNC);
	return false;
}

bool AddsquareAction::record_me() const
{
	return true;
}

void AddsquareAction::Undo()
{
}

void AddsquareAction::Redo()
{
}
