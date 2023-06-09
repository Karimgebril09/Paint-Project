#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLORS
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are *(ordered)* here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu

	//TODO: Add more items names here
	ITM_SQUARE,
	ITM_TRIANGLE,
	ITM_HEXA,
	ITM_CIRCLE,
	ITM_FILLING,
	ITM_DRAWINGLINE,
	ITM_SELECT,
	ITM_DELETEFIG,
	ITM_MOVEFIG,
	ITM_MOVEBYDRAG,
	ITM_RESIZE,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLEARALL,
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_SAVEGRAPH,
	ITM_LOADGRAPH,
	ITM_SOUND,
	ITM_SWITCHTOPLAYMODE,
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are *(ordered)* here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	PLAY_ITM_FIGURE,
	PLAY_ITM_COLOR,
	PLAY_ITM_TYPEANDFILL,
	PLAY_ITM_SWITCHTODRAW,
	PLAY_ITM_EXIT,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};

enum ColorsMenuItem {
	ITM_BLUE,
	ITM_GREEN,
	ITM_RED,
	ITM_YELLOW,
	ITM_BLACK,
	ITM_ORANGE,
	COLORS_ITM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool isfilled=false;
	bool sound = false;
	/// Add more members if needed

}UI;	//create a global object UI

#endif