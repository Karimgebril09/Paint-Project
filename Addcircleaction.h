#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include"Actions/Action.h"

class AddcircleAction : public Action
{
private:
	Point center,radius; 
	GfxInfo cirGfxInfo;
public:
	AddcircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();

};
#endif
