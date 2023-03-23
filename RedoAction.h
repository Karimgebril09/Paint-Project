#pragma once
#ifndef REDO_H
#define REDO_H
#include"Actions/Action.h"
#include "ApplicationManager.h"
class RedoAction :public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();

	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};



#endif