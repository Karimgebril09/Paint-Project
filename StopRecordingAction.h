#ifndef STOPRECORDINGACTION_H
#define STOPRECORDINGACTION_H
#include "Actions/Action.h"
#include "ApplicationManager.h"




class StopRecording : public Action
{

public:
    StopRecording(ApplicationManager* pApp);
    //Reads parameters required for action to execute (code depends on action type)
    virtual void ReadActionParameters();

    //Execute action (code depends on action type)
    virtual bool Execute(bool readparams = true);
    virtual bool record_me()const;


};

#endif