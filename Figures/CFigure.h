#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<cmath>
#include<cstring>
#include<fstream>

//Base class for all figures
class CFigure
{
protected:
	static int count;
	int ID;		//Each figure has an ID (must be unique)
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	virtual bool isinside(int x,int y) =0 ;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	int GetID();

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr,int acttype=1);	//changes the figure's filling color
	color returnFillColor();
	virtual void movefig(Point) = 0; //move the figure
	virtual void SaveFigure(ofstream& save) = 0;        //Save the figure parameters to the file
	virtual void LoadFigure(ifstream& load) = 0;        //Load the figure parameters to the file
	virtual Point GetCenter()=0;


	void setcount(int c);




	virtual bool Am_I_Corner(Point cornerpoint)  =0;
	virtual void Resize_Me(Point cornerpoint)   = 0;
	float distance_bet_2_points(Point p1, Point p2);

	string ConvertColor_to_string(color col, bool FillorDraw);                    // convert color to a string to be able to save it in a file
	color ConvertString_to_color(string colname, bool LoadAction_or_Figure = 1);        //convert a string read from a file to color to be able to draw

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif