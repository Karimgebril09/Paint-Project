#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Addsquareaction.h"
#include"Addtriangleaction.h"
#include"Addhexagonaction.h"
#include"Addcircleaction.h"
#include"Selectaction.h"
#include"changefilling.h"
#include"changedrawing.h"
#include"deletefigureaction.h"
#include"playmodetoolbaraction.h"
#include"DrawModetoolbaraction.h"
#include"movefigureaction.h"
#include"movebydragaction.h"
#include"soundaction.h"
#include"ByFigureAction.h"
#include"ByColorAction.h"
#include"SaveAction.h"
#include"LoadAction.h"
#include"UndoAction.h"
#include"RedoAction.h"
#include "ResizeAction.h"
#include"StopRecordingAction.h"
#include"StartRecording.h"
#include"PlayRecordAction.h"
#include"clearallaction.h"
#include"exitaction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output; //creates output object
	pIn = pOut->CreateInput(); //create input object
	SelectedFig = NULL;
	FigCount = 0;
	RecCount = 0;
	FigC = 0;
	RecordingState = false;
	ActC = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 0;i < MaxReccount;i++)
		RecordingList[i] = NULL;
	LastAction = NULL;
	for (int i = 0; i < 5; i++) {
		ActArr[i] = NULL;
		FigHis[i] = NULL;
	}
	UndoFlag = 0;
	isplaying = false;
}

void ApplicationManager::SaveAll(ofstream& save)const                    //loops on the fig list and make every figure itself
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SaveFigure(save);
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL; //base class pointer for other actions
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);//create only object
			break;
		//to do:continue each case and make object of each action with same steps
		case DRAW_SQUARE:
			pAct = new 	AddsquareAction(this);//create only object
			break;
		case DRAW_TRIANGLE:
			pAct = new AddtriAction(this);//create only object
			break;
		case DRAW_HEXA:
			pAct = new AddhexaAction(this);//create only object
			break;
		case DRAW_CIRCLE:
			pAct = new AddcircleAction(this);//create only object
			break;
		case SELECT:
			pAct = new selectaction(this);//create only object
			break;
		case CHANGE_FILLING:
			pAct = new changefilling(this);
			break;
		case CHANGE_DRAWINGLINE:
			pAct = new changedrawing(this);
			break;
		case DELETE_FIG:
			pAct = new deletefigureaction(this);
			break;
		case MOVE_FIG:
			pAct = new movefigureaction(this);
			break;
		case MOVE_BY_DRAG:
			pAct = new movebydrag(this);
			break;
		case SOUND:
			pAct = new soundaction(this);
			break;
		case TO_PLAY:
			pAct = new playmodetoolbaraction(this);
			break;
		case TO_DRAW:
			pAct = new DrawModetoolbaraction(this);
			break;
		case BY_FIG:
			pAct = new ByFigureAction(this);
			break;
		case BY_COL:
			pAct = new ByColorAction(this);
			break;
		case SAVE_GRAPH:
			pAct = new SaveAction(this);
			break;
		case LOAD_GRAPH:
			pAct = new LoadAction(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case RESIZE:
			pAct = new ResizeAction(this);
			break;
		case STARTREC:
			pAct = new StartRecAction(this);
			Recptr = pAct;
			break;
		case STOPREC:
			pAct = new StopRecording(this);
			break;
		case PLAYREC:
			pAct = new PlayRecord(this);
			break;
		case CLEARALL:
			pAct = new clearallaction(this);
			break;
		case EXIT:
			pAct = new exitaction(this);///create ExitAction here
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	if (pAct != NULL)
	{
		LastAction = pAct;
		bool Delete_Or_Not = pAct->Execute();
		if (RecordingState)                        // if recording proceed to excute the recordingaction once again
		{
			Recptr->Execute(false);
		}
		if (Delete_Or_Not)
		{
			delete pAct;
			pAct = NULL;
		}
		pAct = NULL;
	}
}
void ApplicationManager::AddAct(Action* pACT)
{
	if (UndoFlag) {
		for (int i = ActC; i < 5; i++)
		{
			ActArr[i] = NULL;
		}
	}
	if (ActC<5)
	ActArr[ActC++] = pACT;
else {
	if(!ActArr[0]->getisrecorded())
	delete ActArr[0];
	for (int i = 0; i < 4; i++)
	{
		ActArr[i] = ActArr[i + 1];
	}
	ActArr[4] = pACT;
	}
}

Action* ApplicationManager::GetLastAct()
{
	if (ActC - 1 >= 0)
		return ActArr[ActC - 1];
	else
		return nullptr;
}

void ApplicationManager::DelLastAct()
{
	ActC--;
	delete ActArr[ActC];
	ActArr[ActC] = NULL;
}

void ApplicationManager::StepDownAct()
{
	if(ActC>0)
	ActC--;
}

void ApplicationManager::StepUpAct()
{
	if (ActC<5)
	ActC++;
}

void ApplicationManager::SetUF(bool f)
{
	UndoFlag = f;
}

CFigure* ApplicationManager::SearchFor(int id)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetID() == id)
			return FigList[i];
	}
	return nullptr;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
	}
}
//function delete gets a pointer te3melo delete we replace a5er wahed makano 
void ApplicationManager::deletefigure(CFigure* Figdel)
{
	int i = 0;
	while (i < FigCount)
	{
		if (FigList[i] == Figdel)// || FigList[i]->GetDelState())   //find the 
		{
			delete FigList[i]; // 3ayzen nshel 
			//AddFigToHis(FigList[i]);
			for (int j = i; j < FigCount; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigList[FigCount] = NULL;
			FigCount--;
			SelectedFig = NULL;
		}
		i++;
	}
}

void ApplicationManager::clearall()
{
	for (int i = 0; i < FigCount; i++) //delete all figures
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	for (int i = 0; i < 5; i++) //delete all fighistory
	{
		if (FigHis[i] != NULL)
		{
			delete FigHis[i];
			FigHis[i] = NULL;
		}
	}
	for (int i = 0; i < 5; i++) //delete the undo action that are'nt recorded
	{
		if (ActArr[i] != NULL && !(ActArr[i]->getisrecorded()))
		{
			delete ActArr[i];
			ActArr[i] = NULL;
		}
	}
	if(!isplaying)//delete the record list if not from recording
	{
		for (int i = 0; i < RecCount; i++)
		{
			delete RecordingList[i];
			RecordingList[i] = NULL;
		}
		RecCount = 0;
		RecordingState = false;
	}

	SelectedFig = NULL;
	FigCount = 0;
	ActC = 0;
	FigC = 0;
	UndoFlag = false;
	UI.isfilled = false;
	UI.sound = false;
	UI.DrawColor = BLUE;
	isplaying = false;
	pOut->ClearStatusBar();
}




////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	
	int j = -1;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isinside(x,y))
		{
			j = i;
		}
	}
	if (j >= 0)
	{
		return FigList[j];
	}
	
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::setselectpointer(CFigure* p)
{
	SelectedFig = p;
}

CFigure* ApplicationManager::getselectpointer()
{
	return SelectedFig;
}

int ApplicationManager::GetFiglistcount()
{
	return FigCount;
}

void ApplicationManager::setisplaying(bool isplay)
{
	isplaying = isplay;
}

Action* ApplicationManager::GetLastAction() const
{
	return LastAction;
}

void ApplicationManager::AddinRecList(Action* Act)
{
	if (RecCount < MaxReccount)
		RecordingList[RecCount++] = Act;
	else
		RecordingState = false;
}

void ApplicationManager::SetRecordingState(bool R)
{
	RecordingState = R;
}

bool ApplicationManager::Get_Recording_State() const
{
	return RecordingState;
}

int ApplicationManager::Get_Rec_Count() const
{
	return RecCount;
}

void ApplicationManager::Play_Record()
{
	clearall();
	UpdateInterface();
	for (int i = 0;i < RecCount;i++) //play every action with a 1 second period sleep
	{
		Sleep(1000);
		RecordingList[i]->Execute(false);
		UpdateInterface();
	}
}

int ApplicationManager::getfigcount() const
{
	return FigCount;
}

int ApplicationManager::GetShapeCount(int x)
{
	int c = 0;
	switch (x) {
	case 0:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<Ccircle*>(FigList[i]))
				c++;
		}
		return c;
		break;
	case 1:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CRectangle*>(FigList[i]))
				c++;
		}
		return c;
		break;
	case 2:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<Csquare*>(FigList[i]))
				c++;
		}
		return c;
		break;
	case 3:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CTriangle*>(FigList[i]))
				c++;
		}
		return c;
		break;
	case 4:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CHexagon*>(FigList[i]))
				c++;
		}
		return c;
		break;
	}
}
int ApplicationManager::GetColorCount(int x)
{
	int c = 0;
	switch (x) {
	case 0:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == BLACK)
				c++;
		}
		return c;
		break;
	case 1:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == BLUE)
				c++;
		}
		return c;
		break;
	case 2:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == YELLOW)
				c++;
		}
		return c;
		break;
	case 3:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == RED)
				c++;
		}
		return c;
		break;
	case 4:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == ORANGE)
				c++;
		}
		return c;
		break;
	case 5:
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->returnFillColor() == GREEN)
				c++;
		}
		return c;
		break;
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();//clear drawing area first

	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)  gowa kol function
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
