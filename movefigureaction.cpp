#include"movefigureaction.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include<Windows.h>
#include<mmsystem.h>

movefigureaction::movefigureaction(ApplicationManager* pApp) :Action(pApp)
{
	if (UI.sound)
		PlaySound(TEXT("Move"), NULL, SND_SYNC);
}

void movefigureaction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure *p=pManager->getselectpointer();
	if (p)
	{
		pOut->PrintMessage("click anywhere to move figure");
		pIn->GetPointClicked(p1.x, p1.y);
	}
	else
	{
		pOut->PrintMessage("there is no selected figures");
	}
}
bool movefigureaction::Execute(bool readparams )
{
	if (readparams == true)
		ReadActionParameters();
	CFigure* p = pManager->getselectpointer();
	if (p)
	{
		prevFig = p->GetID();
		prev =p->GetCenter();
		p->movefig(p1);
		
	}
	pManager->AddAct(this);
	return false;
}

bool movefigureaction::record_me() const
{
	return true;
}

void movefigureaction::Undo()
{
	if (pManager->SearchFor(prevFig)) {
		CFigure* x = pManager->SearchFor(prevFig);
		x->movefig(prev);
	}
}

void movefigureaction::Redo()
{
	if (pManager->SearchFor(prevFig)) {
		CFigure* x = pManager->SearchFor(prevFig);
		x->movefig(p1);
	}
}
