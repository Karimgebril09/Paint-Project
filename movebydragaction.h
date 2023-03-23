#ifndef MOVE_BY_DRAG_H
#define MOVE_BY_DRAG_H

#include"Actions/Action.h"

class movebydrag :public Action
{
private:
	Point p;
public:
	movebydrag(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;

};

#endif