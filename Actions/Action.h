#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager* pManager;								//Actions needs AppMngr to do their job
private:
	bool isrecorded; //if the action isrecorded
public:

	Action(ApplicationManager* pApp) { pManager = pApp; isrecorded = false; }		//constructor //kol el actions ma3aha pointer men el manager
	void setisrecorded(bool act) { isrecorded = act; }   //set the recorded action
	bool getisrecorded() { return isrecorded; }   //get the recorded action
	//Reads parameters required for action to execute (code depends on action type)

	virtual bool Execute(bool readparams = true) = 0;       // bool to decide to readparmaters or not(for recording /loading/saving)
	virtual bool record_me()const = 0;                     // a Virtual Function to ask within every action wether to add this action to a list or not

	virtual void Undo() {};
	virtual void Redo() {};

};

#endif