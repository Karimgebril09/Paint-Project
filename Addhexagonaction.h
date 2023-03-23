#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H


#include"Actions/Action.h"

class AddhexaAction : public Action
{
private:
	Point p1; //hexa center
	GfxInfo hexaGfxInfo;
public:
	AddhexaAction(ApplicationManager* pApp);

	//Reads hexagone parameters
	virtual void ReadActionParameters();

	//Add hexagone to the ApplicationManager
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
	virtual void Undo();
	virtual void Redo();
};





#endif

