#include "Output.h"
#include<cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = LIGHTGRAY;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = GRAY;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\hexa.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_FILLING] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ITM_DRAWINGLINE] = "images\\MenuItems\\outline.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DELETEFIG] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVEFIG] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_MOVEBYDRAG] = "images\\MenuItems\\move-by-drag.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\clear.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\start.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\sound.jpg";
	MenuItemImages[ITM_SWITCHTOPLAYMODE] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorBar() const {
	UI.InterfaceMode = MODE_COLORS;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	string MenuItemImages[COLORS_ITM_COUNT];
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";

	for (int i = 0; i < COLORS_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLAY_ITM_FIGURE] = "images\\MenuItems\\fig.jpg";
	MenuItemImages[PLAY_ITM_COLOR] = "images\\MenuItems\\color.jpg";
	MenuItemImages[PLAY_ITM_TYPEANDFILL] = "images\\MenuItems\\fig&color.jpg";
	MenuItemImages[PLAY_ITM_SWITCHTODRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[PLAY_ITM_EXIT] = "images\\MenuItems\\exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}

//////////////////////////////////////////////////////////////////////////////////////////





int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}
void Output::Drawsquare(Point P1, GfxInfo squareGfxInfo,int defsize, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int xcorners[4], ycorners[4];
	xcorners[0] = P1.x - defsize / 2, ycorners[0] = P1.y + defsize / 2;
	xcorners[1] = P1.x - defsize / 2, ycorners[1] = P1.y - defsize / 2;
	xcorners[3] = P1.x + defsize / 2, ycorners[3] = P1.y + defsize / 2;
	xcorners[2] = P1.x + defsize / 2, ycorners[2] = P1.y - defsize / 2;
	pWind->DrawPolygon(xcorners, ycorners, 4, style);
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo triGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = triGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (triGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::Drawhexa(Point P1, GfxInfo hexaGfxInfo, bool selected,int defsize) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = hexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (hexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int xcorners[6] = { P1.x + defsize ,P1.x + defsize/2 ,P1.x - defsize/2 ,P1.x - defsize ,P1.x - defsize/2 ,P1.x + defsize/2 };
	int ycorners[6] = { P1.y,P1.y + 0.866 * defsize,P1.y + 0.866 * defsize,P1.y,P1.y - 0.866 * defsize,P1.y - 0.866 * defsize };
	pWind->DrawPolygon(xcorners, ycorners, 6, style);
}




void Output::drawcircle(Point P1, Point P2, GfxInfo circleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}