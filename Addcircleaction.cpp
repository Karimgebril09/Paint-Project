#include"AddCircleaction.h"
#include "Ccircle.h"
#include<Windows.h>
#include"ApplicationManager.h"
#include<Windows.h>
#include<mmsystem.h>
#include "GUI/Input.h"
#include "GUI/Output.h"

AddcircleAction::AddcircleAction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound) //play sound when dawing circle
		PlaySound(TEXT("circle-select"), NULL, SND_SYNC);
}

void AddcircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New circle: Click at the center");

	//Read center and store in point center
	pIn->GetPointClicked(center.x,center.y);

	pOut->PrintMessage("New circle: Click at the radius");

	//Read radius point and store in radius
	pIn->GetPointClicked(radius.x, radius.y);

	cirGfxInfo.isFilled = UI.isfilled;	//default is not filled 
	//get drawing, filling colors and pen width from the interface
	cirGfxInfo.DrawClr = pOut->getCrntDrawColor();
	cirGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddcircleAction::Execute(bool readparams )
{
	//This action needs to read some parameters first
	if(readparams==true)
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	Ccircle* circ = new Ccircle(center,radius, cirGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(circ);
	pManager->UpdateInterface(); //update interface before playing the sound
	if (UI.sound)
		PlaySound(TEXT("circle-sound"), NULL, SND_SYNC);
	return false;
}
bool AddcircleAction::record_me() const
{
	return true;
}

void AddcircleAction::Undo()
{
}

void AddcircleAction::Redo()
{
}
