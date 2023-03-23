#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
}

CRectangle::CRectangle()
{
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isinside(int x, int y)
{
	int lx, sx, ly, sy;
	if (Corner1.x >= Corner2.x)
	{
		lx = Corner1.x;
		sx = Corner2.x;
	}
	else
	{
		lx = Corner2.x;
		sx = Corner1.x;
	}
	if (Corner1.y >= Corner2.y)
	{
		ly = Corner1.y;
		sy = Corner2.y;
	}
	else
	{
		ly = Corner2.y;
		sy = Corner1.y;
	}
	if (x <= lx && x >= sx && y <= ly && y >= sy)
		return true;

	return false;
}

void CRectangle::SaveFigure(ofstream& save)            // save its local data into a file given to the func by saveaction
{
	save << "Rectangle" << "\t" << ID << "\t" << to_string(Corner1.x) << "\t" << to_string(Corner1.y) << "\t" << to_string(Corner2.x) << "\t" << to_string(Corner2.y) << "\t" << ConvertColor_to_string(FigGfxInfo.DrawClr, 0) << "\t" << ConvertColor_to_string(FigGfxInfo.FillClr, 1) << endl;
}

void CRectangle::LoadFigure(ifstream& load)            // load its local data from a file given to the func by loadaction
{
	string word;
	load >> word;
	ID = stoi(word);
	load >> word;
	Corner1.x = stoi(word);
	load >> word;
	Corner1.y = stoi(word);
	load >> word;
	Corner2.x = stoi(word);
	load >> word;
	Corner2.y = stoi(word);
	load >> word;
	Selected = false;
	FigGfxInfo.DrawClr = ConvertString_to_color(word);
	load >> word;
	FigGfxInfo.FillClr = ConvertString_to_color(word);
}

Point CRectangle::GetCenter()
{
	return Center;
}

void CRectangle::Resize_Me(Point cornerpoint)
{
	Corner2.x = cornerpoint.x;
	Corner2.y = cornerpoint.y;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
}

bool CRectangle::Am_I_Corner(Point cornerpoint)
{
	float dist_point_center = distance_bet_2_points(cornerpoint, Center);
	float dist_corner_center = distance_bet_2_points(Corner1, Center);
	if((dist_point_center)<(dist_corner_center+15) && (dist_point_center>dist_corner_center-15))
		return true;
	else
		return false;
}

void CRectangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string  width= to_string(abs(Corner1.x- Corner2.x));
	string  length = to_string(abs(Corner1.y - Corner2.y));
	string xstartp = to_string(Corner1.x);
	string ystartp = to_string(Corner1.y);
	string xendp = to_string(Corner2.x);
	string yendp = to_string((Corner2.y));
	string message = "Selected rectangle info:ID: " + id + " width:" + width + " length:" + length + " start point:(" + xstartp + "," + ystartp + ")";
	message+="end point:("+xendp + "," + yendp + ")";
	pOut->PrintMessage(message);
}

void CRectangle::movefig(Point z)
{
	int xtranslation = z.x - Center.x,ytranslation = z.y - Center.y;
	Corner1.x += xtranslation;
	Corner1.y += ytranslation;
	Corner2.x += xtranslation;
	Corner2.y += ytranslation;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
}