#pragma once
#ifndef SAVEACTIOM
#define SAVEACTION
#include"Actions/Action.h"
#include<fstream>
#include"Figures/CFigure.h"
class SaveAction : public Action
{
private:
	ofstream fout; // to enter data in a file .txt
	string word1;  // to save strings in cpp
	CFigure* Cfigptr; // to call convert color to string function that already exist to maximize code reusability
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};




#endif
