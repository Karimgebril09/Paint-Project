#ifndef CHANGE_FILLING_H
#define CHANGE_FILLING_H
#include"Actions/Action.h"

class changefilling :public Action
{
private:
	ActionType colortype;
	int prevfig;
	bool PrevIsFilledUI;
	color PrevColorUI;
	int UndoOrRedo;
public:
	changefilling(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};

#endif
