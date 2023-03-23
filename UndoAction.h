#pragma once
#ifndef UNDO_H
#define UNDO_H
#include"Actions/Action.h"
#include "ApplicationManager.h"
class UndoAction :public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();

	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};



#endif