#include"CTriangle.h"



CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
	p3 = P3;
	center.x = (p1.x + p2.x + p3.x) / 3;
	center.y = (p1.y + p2.y + p3.y) / 3;
}

CTriangle::CTriangle()
{
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::Drawtri to draw a rectangle on the screen	
	pOut->DrawTri(p1,p2,p3, FigGfxInfo, Selected);
}

void CTriangle::SaveFigure(ofstream& save)        // save its local data into a file given to the func by saveaction
{
	save << "Triangle" << "\t" << ID << "\t" << to_string(p1.x) << "\t" << to_string(p1.y) << "\t" << to_string(p2.x) << "\t" << to_string(p2.y) << "\t" << to_string(p3.x) << "\t" << to_string(p3.y) << "\t" << ConvertColor_to_string(FigGfxInfo.DrawClr, 0) << "\t" << ConvertColor_to_string(FigGfxInfo.FillClr, 1) << endl;
}

void CTriangle::LoadFigure(ifstream& load)        // load its local data from a file given to the func by loadaction
{
	string word;
	load >> word;
	ID = stoi(word);
	load >> word;
	p1.x = stoi(word);
	load >> word;
	p1.y = stoi(word);
	load >> word;
	p2.x = stoi(word);
	load >> word;
	p2.y = stoi(word);
	load >> word;
	p3.x = stoi(word);
	load >> word;
	p3.y = stoi(word);
	load >> word;
	Selected = false;
	FigGfxInfo.DrawClr = ConvertString_to_color(word);
	load >> word;
	FigGfxInfo.FillClr = ConvertString_to_color(word);
}

Point CTriangle::GetCenter()
{
	return center;
}

void CTriangle::Resize_Me(Point cornerpoint)
{
	if (which_corner == 1)
	{
		p1.x = cornerpoint.x;
		p1.y = cornerpoint.y;
	}
	if (which_corner == 2)
	{
		p2.x = cornerpoint.x;
		p2.y = cornerpoint.y;
	}
	if (which_corner == 3)
	{
		p3.x = cornerpoint.x;
		p3.y = cornerpoint.y;
	}
	center.x = (p1.x + p2.x + p3.x) / 3;
	center.y = (p1.y + p2.y + p3.y) / 3;
}

bool CTriangle::Am_I_Corner(Point cornerpoint)
{
	float dist1 = distance_bet_2_points(cornerpoint, p1);
	float dist2 = distance_bet_2_points(cornerpoint, p2);
	float dist3 = distance_bet_2_points(cornerpoint, p3);
	if (dist1 < 15)
	{
		which_corner = 1;
		return true;
	}
	if (dist2 < 15)
	{
		which_corner = 2;
		return true;
	}
	if (dist3< 15)
	{
		which_corner = 3;
		return true;
	}
	return false;
}

bool CTriangle::isinside(int x,int y)
{
	double totalarea = abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
	double area1= abs(x * (p2.y - p3.y) + p2.x * (p3.y - y) + p3.x * (y - p2.y)) / 2.0;
	double area2= abs(p1.x * (y - p3.y) + x * (p3.y - p1.y) + p3.x * (p1.y - y)) / 2.0;
	double area3= abs(p1.x * (p2.y - y) + p2.x * (y - p1.y) + x * (p1.y - p2.y)) / 2.0;
	if (area1 + area2 + area3 == totalarea)
		return true;
	else
		return false;
}
void CTriangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string xfirstp = to_string(p1.x);
	string yfrip = to_string(p1.y);
	string xsecp = to_string(p2.x);
	string ysecp = to_string(p2.y);
	string xthirdp = to_string((p3.x));
	string ythirdp = to_string(p3.y);
	string message = "Selected tiangle info:ID: " + id + " point 1:(" + xfirstp + "," + yfrip + ")" + " point 2:(" + xsecp + "," + ysecp + ")";
	message += " point 1:(" + xthirdp + "," + ythirdp + ")";
	pOut->PrintMessage(message);
}

void CTriangle::movefig(Point z)
{
	int xtranslation = z.x - center.x;
	int ytranslation = z.y - center.y;
	p1.x += xtranslation;
	p1.y += ytranslation;
	p2.x += xtranslation;
	p2.y += ytranslation;
	p3.x += xtranslation;
	p3.y += ytranslation;
	center.x = (p1.x + p2.x + p3.x) / 3;
	center.y = (p1.y + p2.y + p3.y) / 3;

}