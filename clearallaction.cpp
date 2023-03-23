#include"clearallaction.h"
#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

clearallaction::clearallaction(ApplicationManager* pApp) :Action(pApp)
{
}

void clearallaction::ReadActionParameters()
{
}


bool clearallaction::Execute(bool readparams)
{
	pManager->clearall(); //execute the clear all function
	return true;
}

bool clearallaction::record_me() const
{
	return false;
}
