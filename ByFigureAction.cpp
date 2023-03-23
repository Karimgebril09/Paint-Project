#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "selectaction.h"
#include"deletefigureaction.h"
#include"ByFigureAction.h"
#include"Figures/CFigure.h"

ByFigureAction::ByFigureAction(ApplicationManager* pApp) :Action(pApp) {
	ppo = pApp;
}
void ByFigureAction::ReadActionParameters()
{
}
bool ByFigureAction::Execute(bool readparams ) {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFiglistcount() > 0) {
		int arrCount[5];
		int arrind[5];
		int c = 0;
		for (int i = 0; i < 5; i++)
		{
			int x = pManager->GetShapeCount(i);
			if (x > 0) {
				arrCount[c] = x;
				arrind[c++] = i;
			}
		}
		int r = rand() % c;
		switch (arrind[r])
		{
		case 0: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Circles ! Pick the " + to_string(arrCount[r]) + " Circles");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (dynamic_cast<Ccircle*>(x) )
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Circles from " + to_string(arrCount[r]) + " Circles!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Circles ! you Clicked Incorrectly " + to_string(wc) + " times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else if(m.y > UI.ToolBarHeight){
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly " + to_string(wc) + " times");
				}

			}
			break;
		}
		case 1: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Rectangles ! Pick the " + to_string(arrCount[r]) + " Rectangles");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (dynamic_cast<CRectangle*>(x))
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Rectangles from " + to_string(arrCount[r]) + " Rectangles!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Rectangles ! you Clicked Incorrectly " + to_string(wc) + " times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else {
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly " + to_string(wc) + " times");
				}

			}

			break;
		}
		case 2: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Squares ! Pick the " + to_string(arrCount[r]) + " Squares");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (dynamic_cast<Csquare*>(x))
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Squares from " + to_string(arrCount[r]) + " Squares!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Squares ! you Clicked Incorrectly " + to_string(wc) + " times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else if (m.y > UI.ToolBarHeight) {
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly " + to_string(wc) + " times");
				}

			}
			break;
		}
		case 3: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Triangles ! Pick the " + to_string(arrCount[r]) + " Triangles");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (dynamic_cast<CTriangle*>(x))
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Triangles from " + to_string(arrCount[r]) + " Triangles!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Triangles ! you Clicked Incorrectly " + to_string(wc) + " times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else {
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly " + to_string(wc) + " times");
				}

			}
			break;
		}
		case 4: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Hexagons ! Pick the " + to_string(arrCount[r]) + " Hexagons");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (dynamic_cast<CHexagon*>(x))
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Hexagons from " + to_string(arrCount[r]) + " Hexagons!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Hexagons ! you Clicked Incorrectly " + to_string(wc) + " times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else {
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly " + to_string(wc) + " times");
				}

			}
			break;
		}
		default:
			break;
		}
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("NO Shapes TO PLay With");
	}
	return true;
}

bool ByFigureAction::record_me() const
{
	return false;
}
