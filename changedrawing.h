#ifndef CHANGE_DRAWING_H
#define CHANGE_DRAWING_H
#include"Actions/Action.h"

class changedrawing :public Action
{
private:
	ActionType colortype;
	color PrevColorUI;
	int prevfig;
public:
	changedrawing(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};

#endif
