#ifndef CHEXA_H
#define CHEXA_H
#include"Figures/CFigure.h"

class CHexagon :public CFigure
{
private:
	Point center;
	int defaultsize;
public:
	CHexagon(Point c, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x,int y);
	virtual void PrintInfo(Output* pOut);
	virtual void movefig(Point);
	virtual void SaveFigure(ofstream& save);
	virtual void LoadFigure(ifstream& load);
	virtual Point GetCenter();

	virtual bool Am_I_Corner(Point cornerpoint);
	virtual void Resize_Me(Point cornerpoint);
};




#endif 