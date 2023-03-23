#ifndef RESIZEACTION_H
#define RESIZEACTION_H

#include"Actions/Action.h"

class ResizeAction :public Action
{
private:
	Point p;
public:
	ResizeAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;

};

#endif