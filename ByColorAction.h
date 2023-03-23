#pragma once
#ifndef BY_COL_H
#define BY_COL_H
#include"Actions/Action.h"

class ByColorAction :public Action
{
private:
	ApplicationManager* ppo;
public:
	ByColorAction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();
	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};



#endif