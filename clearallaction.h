#ifndef CLEAR_ALL_ACTION_H
#define CLEAR_ALL_ACTION_H

#include"Actions/Action.h"

class clearallaction : public Action
{
public:
	clearallaction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};
#endif
