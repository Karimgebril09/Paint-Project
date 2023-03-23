#ifndef SELECT_H
#define SELECT_H
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class selectaction :public Action
{
private:
	Point p1;
	CFigure* selected_one; // pointer to the selected figure
public:
	selectaction(ApplicationManager* pApp);
	//the coordinate of the point where it will be selected
	virtual void ReadActionParameters();

	//execute the select action
	virtual bool Execute(bool readparams = true);
	virtual bool record_me()const;
};



#endif