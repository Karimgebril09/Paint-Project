#include"Csquare.h"



Csquare::Csquare(Point c, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = c;
	defaultsize = 200;
}

Csquare::Csquare()
{
	defaultsize = 200;
}


void Csquare::Draw(Output* pOut) const
{
	//Call Output::Drawsquare to draw a rectangle on the screen	
	pOut->Drawsquare(center, FigGfxInfo,defaultsize, Selected);
}
bool Csquare::isinside(int x, int y)
{
	if (x >= center.x - defaultsize/2 && x <= center.x + defaultsize/2 && y >= center.y - defaultsize/2 && y <= center.y + defaultsize/2)
		return true;
	return false;
}

void Csquare::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string sidelength = to_string(defaultsize);
	string xcenterpoint = to_string(center.x);
	string ycenterpoint = to_string(center.y);
	string message = "Selected square info:ID: " + id + " sidelength : " + sidelength + " center point : (" + xcenterpoint + ", " + ycenterpoint + ")";
	pOut->PrintMessage(message);
}

void Csquare::SaveFigure(ofstream& save)  // save its local data into a file given to the func by saveaction
{
	save << "Square" << "\t\t" << ID << "\t" << to_string(center.x) << "\t" << to_string(center.y) << "\t" << ConvertColor_to_string(FigGfxInfo.DrawClr, 0) << "\t" << ConvertColor_to_string(FigGfxInfo.FillClr, 1) << endl;
}

void Csquare::LoadFigure(ifstream& load)    // load its local data from a file given to the func by loadaction
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

Point Csquare::GetCenter()
{
	return center;
}

void Csquare::Resize_Me(Point cornerpoint)
{
	float x = distance_bet_2_points(cornerpoint, center);
	defaultsize = x / sqrt(2) * 2;
}

bool Csquare::Am_I_Corner(Point cornerpoint)
{
	float x = distance_bet_2_points(center, cornerpoint);
	if (x < (defaultsize / 2 * sqrt(2) + 15) && (x > (defaultsize / 2 * sqrt(2)-15)))
		return true;
	else
		return false;

}

void Csquare::movefig(Point z)
{
	center = z;
}