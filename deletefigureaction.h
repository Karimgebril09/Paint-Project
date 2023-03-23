#ifndef DELETE_FIG_H
#define DELETE_FIG_H
#include"Actions/Action.h"

class deletefigureaction :public Action
{
public:
	deletefigureaction(ApplicationManager* pApp);	
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};

#endif