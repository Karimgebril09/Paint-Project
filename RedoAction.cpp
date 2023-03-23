#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}

void RedoAction::ReadActionParameters()
{
}

bool RedoAction::Execute(bool readparams)
{
	Output* pOut = pManager->GetOutput();
	pManager->StepUpAct();
	if (pManager->GetLastAct()) {
		Action* x = pManager->GetLastAct();
		x->Redo();
	}
	else {
		pManager->StepDownAct();
		pOut->PrintMessage("there is no actions yet");
	}
	return false;
}

bool RedoAction::record_me() const
{
	return true;
}
