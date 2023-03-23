#ifndef  DRAWMODE_TOOLBAR_H
#define DRAWMODE_TOOLBAR_H
#include"Actions/Action.h"


class DrawModetoolbaraction :public Action
{
public:
	DrawModetoolbaraction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};
#endif-