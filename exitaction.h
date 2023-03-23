#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H

#include"Actions/Action.h"

class exitaction : public Action
{
public:
	exitaction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};
#endif
