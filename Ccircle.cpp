#include"Ccircle.h"

Ccircle::Ccircle(Point c, Point rad, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	radiuspoint = rad;
	center = c;
}
Ccircle::Ccircle()
{
}
void Ccircle::Draw(Output* pOut) const
{
	//Call Output::Drawcircle to draw a rectangle on the screen	
	pOut->drawcircle(center,radiuspoint, FigGfxInfo, Selected);
}
bool Ccircle::isinside(int x, int y)
{
	double radius = sqrt(pow(center.x - radiuspoint.x, 2) + pow(center.y - radiuspoint.y, 2));
	double distance = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	if (radius >= distance)
	{
		return true;
	}
	return false;
}

void Ccircle::SaveFigure(ofstream& save)     // save its local data into a file given to the func by saveaction
{
	save << "Circle" << "\t\t" << ID << "\t" << to_string(center.x) << "\t" << to_string(center.y) << "\t" << to_string(radiuspoint.x) << "\t" << to_string(radiuspoint.y) << "\t" << ConvertColor_to_string(FigGfxInfo.DrawClr, 0) << "\t" << ConvertColor_to_string(FigGfxInfo.FillClr, 1) << endl;
}

void Ccircle::LoadFigure(ifstream& load)  // load its local data from a file given to the func by loadaction
{
	string word;
	load >> word;
	ID = stoi(word);
	load >> word;
	center.x = stoi(word);
	load >> word;
	center.y = stoi(word);
	load >> word;
	radiuspoint.x = stoi(word);
	load >> word;
	radiuspoint.y = stoi(word);
	load >> word;
	Selected = false;
	FigGfxInfo.DrawClr = ConvertString_to_color(word);
	load >> word;
	FigGfxInfo.FillClr = ConvertString_to_color(word);
}

Point Ccircle::GetCenter()
{
	return center;
}

void Ccircle::Resize_Me(Point cornerpoint)
{
	radiuspoint.x = cornerpoint.x;
	radiuspoint.y = cornerpoint.y;
}

bool Ccircle::Am_I_Corner(Point cornerpoint)
{
	float cornerradius = distance_bet_2_points(cornerpoint, center);
	float actual_radius = distance_bet_2_points(radiuspoint, center);
	if ((cornerradius < (actual_radius + 15)) && (cornerradius > (actual_radius - 15)))
		return true;
	else return false;
}

void Ccircle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string  radius = to_string(sqrt(pow(center.x - radiuspoint.x, 2) + pow(center.y - radiuspoint.y, 2)));
	string xcenterpoint = to_string(center.x);
	string ycenterpoint = to_string(center.y);
	string xradpoint = to_string(radiuspoint.x);
	string yradpoint = to_string((radiuspoint.y));
	string message = "Selected circle info: ID: " + id + " radius:" + radius + " center point:(" + xcenterpoint + "," + ycenterpoint + ")";
	message+=" other point:(" + xradpoint + "," + yradpoint + ")";
	pOut->PrintMessage(message);
}

void Ccircle::movefig(Point z)
{
	int xtranslation =( z.x - center.x);
	int ytranslation =(z.y - center.y);
	center = z;
	radiuspoint.x += xtranslation;
	radiuspoint.y += ytranslation;
}



