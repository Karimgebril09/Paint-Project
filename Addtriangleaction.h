#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include"Actions/Action.h"

class AddtriAction : public Action
{
private:
	Point p1,p2,p3; //3 corner points
	GfxInfo triGfxInfo;
public:
	AddtriAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add tiangle to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};

#endif
