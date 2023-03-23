#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void Input::Getmousecoordinate(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);	//Wait for mouse click
}


bool Input::getmousestate(int& x, int& y)
{
	return pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN;
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
/////////////////////////////////
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXA:return DRAW_HEXA;
			case ITM_CIRCLE:return DRAW_CIRCLE;
			case ITM_SELECT:return SELECT;
			case ITM_FILLING:return CHANGE_FILLING;
			case ITM_DRAWINGLINE:return CHANGE_DRAWINGLINE;
			case ITM_DELETEFIG:return DELETE_FIG;
			case ITM_MOVEFIG:return MOVE_FIG;
			case ITM_MOVEBYDRAG:return MOVE_BY_DRAG;
			case ITM_RESIZE:return RESIZE;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_CLEARALL:return CLEARALL;
			case ITM_STARTREC:return STARTREC;
			case ITM_STOPREC:return STOPREC;
			case ITM_PLAYREC:return PLAYREC;
			case ITM_SAVEGRAPH:return SAVE_GRAPH;
			case ITM_LOADGRAPH:return LOAD_GRAPH;
			case ITM_SOUND:return SOUND;
			case ITM_SWITCHTOPLAYMODE:return TO_PLAY;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLORS)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_BLUE: return COL_BLUE;
			case ITM_GREEN: return COL_GREEN;
			case ITM_RED: return COL_RED;
			case ITM_ORANGE:return COL_ORANGE;
			case ITM_BLACK:return COL_BLACK;
			case ITM_YELLOW:return COL_YELLOW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else   //GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case PLAY_ITM_FIGURE: return BY_FIG;
			case PLAY_ITM_COLOR: return BY_COL;
			case PLAY_ITM_TYPEANDFILL: return BY_FIG_COL;
			case PLAY_ITM_SWITCHTODRAW:return TO_DRAW;
			case PLAY_ITM_EXIT:return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
			//[2] User clicks on the drawing area

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////
	
Input::~Input()
{
}
