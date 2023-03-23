#include"selectaction.h"
#include"Figures/CFigure.h"
#include<Windows.h>
#include<mmsystem.h>
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

selectaction::selectaction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound)
		PlaySound(TEXT("select-sound"), NULL, SND_SYNC);
	selected_one = NULL;
}

void selectaction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("select figure action");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();

}

bool selectaction::Execute(bool readparams)
{
	//read the point

	Output* pOut = pManager->GetOutput();
	if (readparams == true)
		ReadActionParameters();
	CFigure* pselect = pManager->getselectpointer();
	selected_one = pManager->GetFigure(p1.x, p1.y);
	if (selected_one != NULL)
	{
		if (selected_one->IsSelected())
		{
			pManager->setselectpointer(NULL);
			selected_one->SetSelected(false);
		}
		else
		{
			if (pselect)
			{
				pselect->SetSelected(false);
			}
			pManager->setselectpointer(selected_one);
			selected_one->SetSelected(true);
			selected_one->PrintInfo(pOut);
		}
	}
	return false;
}

bool selectaction::record_me() const
{
	if (selected_one != NULL) // so if the kid didnt select anything and clicked on empty area in the drawing area it doesnt add it to the list
		return true;
	else
		return false;
}
