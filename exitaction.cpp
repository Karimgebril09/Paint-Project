#include"exitaction.h"
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

exitaction::exitaction(ApplicationManager* pApp) :Action(pApp)
{
}

void exitaction::ReadActionParameters()
{
}


bool exitaction::Execute(bool readparams)
{
	pManager->clearall(); //calls the clear before exit
	return true;
}

bool exitaction::record_me() const
{
	return false;
}
