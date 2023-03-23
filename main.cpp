#include "ApplicationManager.h"


int main()
{

	ActionType ActType; //to get which action will be executed
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType); //betcreate object men el action type we bey3mel el execute

		//Update the interface
		AppManager.UpdateInterface();	//clear drawing area we betersemha tani

	} while(ActType != EXIT);
	

	
	return 0;
}

