#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Center;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	//lesaa fi save load undo redo printinfo
	virtual void movefig(Point);
	virtual void SaveFigure(ofstream& save);
	virtual void LoadFigure(ifstream& load);
	virtual Point GetCenter();
	virtual void Resize_Me(Point cornerpoint);
	virtual bool Am_I_Corner(Point cornerpoint);
};

#endif