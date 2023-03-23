#ifndef CTRIAN_H
#define CTRIAN_H

#include"Figures/CFigure.h"
class CTriangle :public CFigure
{
private:
	Point p1,p2,p3,center;
	int which_corner;
public:
	CTriangle(Point P1,Point P2,Point P3, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void movefig(Point);
	virtual void SaveFigure(ofstream& save);
	virtual void LoadFigure(ifstream& load);
	virtual Point GetCenter();

	virtual void Resize_Me(Point cornerpoint);
	virtual bool Am_I_Corner(Point cornerpoint);
};



#endif 