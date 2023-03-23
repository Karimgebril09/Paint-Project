#include"playmodetoolbaraction.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "SaveAction.h"

playmodetoolbaraction::playmodetoolbaraction(ApplicationManager* pApp) :Action(pApp)
{}

void playmodetoolbaraction::ReadActionParameters()
{
}


bool playmodetoolbaraction::Execute(bool readparams )
{
	Output* pOut = pManager->GetOutput(); 
	if (pManager->getselectpointer()!=NULL)  //if there is a selected pointer it unselect it 
	{
		CFigure* p = pManager->getselectpointer();
		p->SetSelected(false);
		pManager->setselectpointer(NULL);
	}
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	sv = new SaveAction(pManager);  //save the draw mode before clear all when going to playmode
	sv->Execute(0);
	pManager->clearall();
	return true;
}

bool playmodetoolbaraction::record_me() const
{
	return false;
}

playmodetoolbaraction::~playmodetoolbaraction()
{
	delete sv;
}
