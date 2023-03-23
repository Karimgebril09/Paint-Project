#include"CHexagon.h"
#include<cmath>
CHexagon::CHexagon(Point c, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = c;
	defaultsize = 100;
}

CHexagon::CHexagon()
{
	defaultsize = 100;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::Drawhexagon to draw a rectangle on the screen	
	pOut->Drawhexa(center, FigGfxInfo, Selected,defaultsize);
}

void CHexagon::SaveFigure(ofstream& save)    // save its local data into a file given to the func by saveaction
{
	save << "Hexagon" << "\t\t" << ID << "\t" << to_string(center.x) << "\t" << to_string(center.y) << "\t" << ConvertColor_to_string(FigGfxInfo.DrawClr, 0) << "\t" << ConvertColor_to_string(FigGfxInfo.FillClr, 1) << endl;
}

void CHexagon::LoadFigure(ifstream& load)        // load its local data from a file given to the func by loadaction
{
	string word;
	load >> word;
	ID = stoi(word);
	load >> word;
	center.x = stoi(word);
	load >> word;
	center.y = stoi(word);
	load >> word;
	Selected = false;
	FigGfxInfo.DrawClr = ConvertString_to_color(word);
	load >> word;
	FigGfxInfo.FillClr = ConvertString_to_color(word);
}

Point CHexagon::GetCenter()
{
	return center;
}

bool CHexagon::Am_I_Corner( Point cornerpoint)
{
	float x = distance_bet_2_points(cornerpoint, center);
	if ((x < (defaultsize + 15)) && ((x > defaultsize-15)))
		return true;
	else
		return false;
}

void CHexagon::Resize_Me(Point cornerpoint)
{
	defaultsize = distance_bet_2_points(cornerpoint, center);
}

bool CHexagon::isinside(int x, int y)
{
	int xcorners[6] = { center.x + defaultsize ,center.x + defaultsize/2 ,center.x - defaultsize/2 ,center.x - defaultsize ,center.x - defaultsize/2 ,center.x + defaultsize/2 };
	int ycorners[6] = { center.y,center.y + 0.866 * defaultsize,center.y + 0.866 * defaultsize,center.y,center.y - 0.866 * defaultsize,center.y - 0.866 * defaultsize };
	bool checkrectangle=false,checkrighttri=false,checklefttri=false;
	
	if (x <= center.x + defaultsize/2 && x >= center.x - defaultsize/2 && y <= center.y + 0.866 * defaultsize && y >= center.y - 0.866 * defaultsize)
		checkrectangle=true;

	Point p1, p2, p3;
	p1.x = center.x + defaultsize/2, p1.y = center.y - 0.866 * defaultsize;
	p2.x = center.x + defaultsize/2, p2.y = center.y + 0.866 * defaultsize;
	p3.x = center.x+ defaultsize, p3.y = center.y;

	double RIGHTtotalarea = abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
	double RIGHTarea1 = abs(x * (p2.y - p3.y) + p2.x * (p3.y - y) + p3.x * (y - p2.y)) / 2.0;
	double RIGHTarea2 = abs(p1.x * (y - p3.y) + x * (p3.y - p1.y) + p3.x * (p1.y - y)) / 2.0;
	double RIGHTarea3 = abs(p1.x * (p2.y - y) + p2.x * (y - p1.y) + x * (p1.y - p2.y)) / 2.0;
	if (RIGHTarea1 + RIGHTarea2 + RIGHTarea3 == RIGHTtotalarea)
		checkrighttri = true;

	Point z1, z2, z3;
	z1.x = center.x + defaultsize/2, z1.y = center.y - 0.866* defaultsize;
	z2.x = center.x + defaultsize/2, z2.y = center.y + 0.866 * defaultsize;
	z3.x = center.x- defaultsize, z3.y = center.y;


	double totalarea = abs(z1.x * (z2.y - z3.y) + z2.x * (z3.y - z1.y) + z3.x * (z1.y - z2.y)) / 2.0;
	double area1 = abs(x * (z2.y - z3.y) + z2.x * (z3.y - y) + z3.x * (y - z2.y)) / 2.0;
	double area2 = abs(z1.x * (y - z3.y) + x * (z3.y - z1.y) + z3.x * (z1.y - y)) / 2.0;
	double area3 = abs(z1.x * (z2.y - y) + z2.x * (y - z1.y) + x *(z1.y - z2.y)) / 2.0;
	if (area1 + area2 + area3 == totalarea)
	{
		checklefttri = true;
	}

	if (checkrectangle || checkrighttri || checklefttri)
	{
		return true;
	}
	return false;
}
void CHexagon::PrintInfo(Output* pOut)
{
	string id=to_string(ID);
	string sidelength = to_string(defaultsize);
	string xcenterpoint = to_string(center.x);
	string ycenterpoint = to_string(center.y);
	string message = "Selected Hexagone info: ID: " + id + " sidelength:" + sidelength + " center point:(" + xcenterpoint + "," + ycenterpoint+")";
	pOut->PrintMessage(message);
}

void CHexagon::movefig(Point z)
{
	center = z;
}