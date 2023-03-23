#include "UndoAction.h"

UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{}

void UndoAction::ReadActionParameters()
{
}

bool UndoAction::Execute(bool readparams)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetLastAct()) {
		Action* x = pManager->GetLastAct();
		x->Undo();
		pManager->StepDownAct();
		pManager->SetUF(1);
	}
	else {
		pOut->PrintMessage("there is no actions yet");
	}
	return false;
}

bool UndoAction::record_me() const
{
	return true;
}
