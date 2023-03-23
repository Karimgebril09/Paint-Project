#include"LoadAction.h"
#include"ApplicationManager.h"
#include"Ccircle.h"
#include"CHexagon.h"
#include"Csquare.h"
#include"CTriangle.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"Figures/CRectangle.h"
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Write the file name you want to load"); // Ask Him The Name of the file he wants to load
	Output* word = pOut;

	word1 = pIn->GetSrting(word);

}

bool LoadAction::Execute(bool readparams)
{
	word1 = "__PLay__Mode__";
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	pManager->clearall();
	Output* pOut = pManager->GetOutput();
	fin.open(word1 + ".txt"); //opens the file 


	if (!(fin.is_open()))
		pOut->PrintMessage("File Doesnt Exsit"); // to alert him that there is no such file with that given name


	else
	{
		pOut->PrintMessage("File loaded");
		fin >> crntdrst >> crntfillst;        // first to words in every saved file is alaways the current draw color and fill color
		UI.DrawColor = figptr->ConvertString_to_color(crntdrst, 0);
		UI.FillColor = figptr->ConvertString_to_color(crntfillst, 0);
		fin >> figcount; // to get the fig count
		for (int i = 0; i < stoi(figcount); i++)
		{
			fin >> word1;
			Search_and_Create(word1);
		}
		fin.close();
	}
	return true;
}

void LoadAction::Search_and_Create(string name)
{
	if (name == "Rectangle")
	{
		CFigure* fig = new CRectangle();
		fig->LoadFigure(fin);
		pManager->AddFigure(fig);
	}
	if (name == "Triangle")
	{
		CFigure* fig = new CTriangle();
		fig->LoadFigure(fin);
		pManager->AddFigure(fig);
	}
	if (name == "Hexagon")
	{
		CFigure* fig = new CHexagon();
		fig->LoadFigure(fin);
		pManager->AddFigure(fig);
	}
	if (name == "Square")
	{
		CFigure* fig = new Csquare();
		fig->LoadFigure(fin);
		pManager->AddFigure(fig);
	}
	if (name == "Circle")
	{
		CFigure* fig = new Ccircle();
		fig->LoadFigure(fin);
		pManager->AddFigure(fig);
	}

}

bool LoadAction::record_me() const
{
	return false;
}
