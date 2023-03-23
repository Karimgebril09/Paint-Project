#ifndef BY_FIG_H
#define BY_FIG_H
#include"Actions/Action.h"

class ByFigureAction :public Action
{
private:
	ApplicationManager* ppo;
public:
	ByFigureAction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();
	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};



#endif