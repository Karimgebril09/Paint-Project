#ifndef CSQUARE_H
#define CSQUARE_H

#include"Figures/CFigure.h"

class Csquare :public CFigure
{
private:
	Point center;
	int defaultsize;
public:
	Csquare(Point c, GfxInfo FigureGfxInfo);
	Csquare();
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