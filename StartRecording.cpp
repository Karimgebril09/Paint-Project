#include"StartRecording.h"

StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp)
{
}
//Reads parameters required for action to execute (code depends on action type)


void StartRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->Get_Recording_State())									 // get recording state now
		pOut->PrintMessage("You Are Already Recording");					//the kid is already recording because its true
	else
	{
		if ((pManager->getfigcount() == 0) && (UI.DrawColor == BLUE) && (UI.isfilled == false))  //check state of the program to see wether to start recording or not
		{
			pOut->PrintMessage("Recording Started"); // record started successfully 
			checkstate = true;
		}
		else
		{
			pOut->PrintMessage("You Can Only Record After a Clear All or at Start");      // to alret him to clear all first
			checkstate = false;
		}
	}
}

//Execute action (code depends on action type)
bool StartRecAction::Execute(bool readparams)
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (pManager->Get_Recording_State())
	{
		Action* Recording_Action = pManager->GetLastAction();		// gets the last action pointer and asign it to the recording action pointer


		if (Recording_Action->record_me())							// to see if this action can be recorded or not 
		{
			Recording_Action->setisrecorded(true);
			pManager->AddinRecList(Recording_Action);		 //sent it to the function which add it in the recording list in appmanger
		}
		else
		{
			if (Recording_Action != this)
			{
				pManager->SetRecordingState(false);
				pOut->PrintMessage("This Action is Not Supported, Recording Has Been Stopped Automatically");
			}
		}
	}
	else if (checkstate)                            // given from readparamters to see if to startrecording or not
		pManager->SetRecordingState(true);
	return false;
}

bool StartRecAction::record_me() const
{
	return false;
}
