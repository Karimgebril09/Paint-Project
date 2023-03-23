#include"SaveAction.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"




SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
}


void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Write the file name"); // ask him the name of the file he wants to save
	Output* word = pOut;
	word1 = pIn->GetSrting(word);
	pOut->PrintMessage("File saved");
}



bool SaveAction::Execute(bool readparams)
{
	word1 = "__PLay__Mode__";
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	fout.open(word1 + ".txt"); //opens the file of the given name


	fout << Cfigptr->ConvertColor_to_string(UI.DrawColor, 0) << "\t";
	if (UI.isfilled == false)    // if defualt is no fill then write it in file
		fout << "NO_FILL" << endl;
	else
		fout << Cfigptr->ConvertColor_to_string(UI.FillColor, 0) << endl; //if there is a color then write it
	fout << pManager->getfigcount() << endl;


	pManager->SaveAll(fout);  // loops on fig list to make every figure save itself

	fout.close();      // close the file to be ready to be loaded
	return true;
}

bool SaveAction::record_me() const
{
	return false;
}
