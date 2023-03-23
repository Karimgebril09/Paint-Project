#ifndef STARTRECORDING_H
#define STARTRECORDING_H
#include "Actions/Action.h"
#include "ApplicationManager.h"



class StartRecAction :public Action
{
    bool checkstate;  //state of the program (cleared and can start recording or not)
public:
    StartRecAction(ApplicationManager* pApp);
    //Reads parameters required for action to execute (code depends on action type)
    virtual void ReadActionParameters();

    //Execute action (code depends on action type)
    virtual bool Execute(bool readparams = true);
    virtual bool record_me()const;
};


#endif