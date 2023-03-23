#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "Ccircle.h"
#include "Csquare.h"
#include "Figures\CRectangle.h"
#include "CTriangle.h"
#include "CHexagon.h"
#include"DrawModetoolbaraction.h"
#include"playmodetoolbaraction.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200,MaxReccount=20 };	//Max no of figures , max no of recording actions

private:
	int ActC;
	int FigCount;		//Actual number of figures
	int FigC;
	bool UndoFlag;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure  

	CFigure* FigHis[5]; //save figure history


	Action* LastAction;    //Last Action Excuted pointer

	bool isplaying;      
	Action* RecordingList[MaxReccount];		//Array of Actions to be Played at Any Time
	int RecCount;							// Current RecCount
	bool RecordingState;					// Current Recording State (true for recording and false for not recording)
	Action* Recptr;							 // Recording Action Pointer to be able to sent to him the Last Action to Check on it



	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Action* ActArr[5];

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void AddAct(Action* pACT);
	Action* GetLastAct();
	void DelLastAct();
	void StepDownAct();
	void StepUpAct();
	void SetUF(bool f);
	CFigure* SearchFor(int id);
	// -- Figures Management Functions


	void deletefigure(CFigure* Figdel); //delete the selected figure

	void clearall();

	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	///////////////////////////////////////////////////////////////////////////////////////		
	// 			
	//Setter for the is recording bool to start recording

	void setisplaying(bool);
	Action* GetLastAction() const; // Returns The Last Action Excuted	
	void AddinRecList(Action* Act); // Add Given Pointer To the Recording List
	void SetRecordingState(bool R);   // Change the Recording state 
	bool Get_Recording_State()const;  // return the recording state
	int Get_Rec_Count()const;		// gets the current count of recorded actions
	void Play_Record();           // play the last recorded list

	////////////////////////////////////////////////////////////////////////////////////
	int getfigcount()const;
	void SaveAll(ofstream& save)const; //Save all figures into specfiv file
	void setselectpointer(CFigure*);
	CFigure*getselectpointer();
	int GetFiglistcount();
	int GetShapeCount(int x);
	int GetColorCount(int x);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif