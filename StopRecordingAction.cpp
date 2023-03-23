#include"StopRecordingAction.h"

StopRecording::StopRecording(ApplicationManager* pApp) :Action(pApp)
{
}
//Reads parameters required for action to execute (code depends on action type)


void StopRecording::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->Get_Recording_State())						// to see if he is recording or not
	{
		pOut->PrintMessage("Record Stopped");
	}
	else
		pOut->PrintMessage("You Are Not Recording");

}

//Execute action (code depends on action type)
bool StopRecording::Execute(bool readparams)
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	pManager->SetRecordingState(false);						//stops the recording
	return true;
}

bool StopRecording::record_me() const
{
	return false;
}