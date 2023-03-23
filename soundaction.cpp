#include"soundaction.h"

#include"ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

soundaction::soundaction(ApplicationManager* pApp) :Action(pApp)
{
	UI.sound = (UI.sound == true) ? false : true; //if sound is on make it off and vise versa
}

void soundaction::ReadActionParameters()
{
}

bool soundaction::Execute(bool readparams )
{
	Output* pOut = pManager->GetOutput();
	if (UI.sound) //if sound is on print message
	{
		pOut->PrintMessage("SOUND ON");
	}
	else
	{
		pOut->PrintMessage("SOUND OFF");
	}
	return true;
}

bool soundaction::record_me() const
{
	return false;
}
