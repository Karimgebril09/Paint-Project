#ifndef CCIRC_H
#define CCIRC_H
#include"Figures/CFigure.h"

class Ccircle :public CFigure
{
private:
	Point center;
	Point radiuspoint;
public:
	Ccircle(Point c,Point radius, GfxInfo FigureGfxInfo);
	Ccircle();
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x,int y);
	virtual void PrintInfo(Output* pOut);
	virtual void movefig(Point);
	virtual void SaveFigure(ofstream& save);
	virtual void LoadFigure(ifstream& load);
	virtual Point GetCenter();
	virtual void Resize_Me(Point cornerpoint);
	virtual bool Am_I_Corner(Point cornerpoint);
};
#endif 