#ifndef  PLAYMODE_TOOLBAR_H
#define PLAYMODE_TOOLBAR_H
#include"Actions/Action.h"


class playmodetoolbaraction :public Action
{
private:
	Action* sv;
public:
	playmodetoolbaraction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	~playmodetoolbaraction();
};
#endif-