#ifndef LOADACTION_H
#define LOADACTION_H
#include<fstream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class LoadAction :public Action
{
private:
	string crntdrst, crntfillst, figcount, word1; // a Bunch of strings to record current drawcolor and fillcolor and figure count 
	ifstream fin;                                // To Read from a File
	CFigure* figptr;							// to call convert string to color function that already exist to maximize code reusability
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool readparams = true);

	void Search_and_Create(string name);                          // to take a Figure as a string given from a file and create its equivalent figure object
	virtual bool record_me()const;
};




#endif#pragma once
