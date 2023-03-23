#include"PlayRecordAction.h"







PlayRecord::PlayRecord(ApplicationManager* pApp) :Action(pApp)
{
}
//Reads parameters required for action to execute (code depends on action type)


void PlayRecord::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->Get_Recording_State())						// get the current recording to state wether recording or not
	{
		checkstate = false;
	}
	else if (pManager->Get_Rec_Count() == 0)
	{
		pOut->PrintMessage("Empty Recording, Please Record Some Actions First");				// nothing to play because the array is empty
		checkstate = false;
	}
	else
	{
		pOut->PrintMessage("Record Will Start Playing Please Wait");			// he is stopped and the array not empty so continue to play the recor
		checkstate = true;
	}
}

//Execute action (code depends on action type)
bool PlayRecord::Execute(bool readparams)
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	if (checkstate)
	{
		pManager->setisplaying(true);
		pManager->Play_Record();	// no class loop on the figure list its appmanger property so make him do the play
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Record Finished You Can Continue Now");			// he can continue on the drawing
	}
	return true;
}

bool PlayRecord::record_me() const
{
	return false;
}