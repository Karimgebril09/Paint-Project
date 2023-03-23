#ifndef ADD_SQUA_ACT_H
#define ADD_SQUA_ACT_H
#include"Actions/Action.h"

class AddsquareAction : public Action
{
private:
	Point p1; //square center
	GfxInfo squGfxInfo;
public:
	AddsquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};






#endif
