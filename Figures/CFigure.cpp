#include "CFigure.h"

int CFigure::count = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	count++;
	ID = count;
}

CFigure::CFigure()
{
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

int CFigure::GetID()
{
    return ID;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }




void CFigure::ChngFillClr(color Fclr, int acttype)
{
    if (acttype == 1)
    {
        FigGfxInfo.PrevIsFilled = FigGfxInfo.isFilled;
        FigGfxInfo.isFilled = true;
        FigGfxInfo.FillClr = Fclr;
    }
    if (acttype == 0)
    {
        FigGfxInfo.isFilled = FigGfxInfo.PrevIsFilled;
        FigGfxInfo.FillClr = Fclr;
    }
}

float CFigure::distance_bet_2_points(Point p1, Point p2)
{
    return  (sqrt(pow(((p1.x) - p2.x), 2) + pow(((p1.y) - p2.y), 2)));
}

string CFigure::ConvertColor_to_string(color col, bool FillorDraw)
{
    if (FillorDraw == 1)
    {
        if (FigGfxInfo.isFilled == false)
            return"NO_FILL";
    }
    if (col == RED)
        return "RED";
    else if (col == YELLOW)
        return"YELLOW";
    else if (col == GREEN)
        return "GREEN";
    else if (col == BLACK)
        return "BLACK";
    else if (col == ORANGE)
        return "ORANGE";
    else
        return "BLUE";
}

color CFigure::ConvertString_to_color(string colname, bool LoadAction_or_Figure) // if called be load action its UI if figure object its Figgfxinfo
{

    if (colname == "NO_FILL")
    {
        if (LoadAction_or_Figure == 1)
            FigGfxInfo.isFilled = false;
        else
            UI.isfilled = false;
        return GREEN;
    }
    else if (LoadAction_or_Figure == 1)
        FigGfxInfo.isFilled = true;
    else
        UI.isfilled = true;


    if (colname == "RED")
        return RED;
    else if (colname == "YELLOW")
        return YELLOW;
    else if (colname == "GREEN")
        return GREEN;
    else if (colname == "BLACK")
        return BLACK;
    else if (colname == "ORANGE")
        return ORANGE;
    else
        return BLUE;
}

color CFigure::returnFillColor()
{
	return FigGfxInfo.FillClr;
}

void CFigure::setcount(int c)
{
    count = c;
}
