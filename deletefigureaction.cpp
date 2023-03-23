#include"deletefigureaction.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

deletefigureaction::deletefigureaction(ApplicationManager* pApp) :Action(pApp)
{}

void deletefigureaction::ReadActionParameters()
{

}
bool deletefigureaction::Execute(bool readparams)
{
    Output* pOut = pManager->GetOutput();
    CFigure* selected = pManager->getselectpointer();
    if (selected)//if there is a figure selected it execute it
    {
        pManager->deletefigure(selected);
        pOut->PrintMessage("Figure deleted");
        pManager->AddAct(this);
    }
    else
    {
        pOut->PrintMessage("select a figure first to delete");
    }
    return false;
}

void deletefigureaction::Undo()
{
  //  pManager->AddFigure(pManager->TrnsLFig());
}

void deletefigureaction::Redo()
{
   // pManager->deletefigure(pManager->GetLastFigure());
}

bool deletefigureaction::record_me() const
{
	return 1;
}
