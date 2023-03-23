#include"Addtriangleaction.h"
#include "Ctriangle.h"
#include<Windows.h>
#include<mmsystem.h>
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddtriAction::AddtriAction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound)//play sound when dawing circle
		PlaySound(TEXT("triangle-select"), NULL, SND_SYNC);
}

void AddtriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New triangle: Click anywhere for the first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("New triangle: Click anywhere for the second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(p2.x, p2.y);

	pOut->PrintMessage("New triangle: Click anywhere for the third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(p3.x, p3.y);


	triGfxInfo.isFilled = UI.isfilled;	//default is not filled  
	//get drawing, filling colors and pen width from the interface
	triGfxInfo.DrawClr = pOut->getCrntDrawColor();
	triGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddtriAction::Execute(bool readparams )
{
	//This action needs to read some parameters first
	if (readparams == true)
		ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CTriangle* tri = new CTriangle(p1,p2,p3, triGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(tri);
	pManager->UpdateInterface(); //update interface before playing sound
	if (UI.sound)
		PlaySound(TEXT("triangle-sound"), NULL, SND_SYNC);
	return false;
}

bool AddtriAction::record_me() const
{
	return true;
}

void AddtriAction::Undo()
{
}

void AddtriAction::Redo()
{
}
