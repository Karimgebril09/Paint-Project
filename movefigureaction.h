#ifndef MOVE_FIG_ACTION
#define MOVE_FIG_ACTION
#include"Actions/Action.h"

class movefigureaction :public Action
{
private:
	Point p1 , prev;
	int prevFig;
public:
	movefigureaction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};


#endif
