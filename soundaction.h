#ifndef SOUND_H
#define SOUND_H
#include"Actions/Action.h"
class soundaction :public Action
{
public:
	soundaction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();

	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;



};

#endif