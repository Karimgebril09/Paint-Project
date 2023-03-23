#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "selectaction.h"
#include"deletefigureaction.h"
#include"ByColorAction.h"
#include"Figures/CFigure.h"
ByColorAction::ByColorAction(ApplicationManager* pApp) :Action(pApp) {
	ppo = pApp;
}
void ByColorAction::ReadActionParameters()
{
}
bool ByColorAction::Execute(bool readparams ) {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFiglistcount() > 0) {
		int arrCount[5];
		int arrind[5];
		int c = 0;
		for (int i = 0; i < 5; i++)
		{
			int x = pManager->GetColorCount(i);
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
			pOut->PrintMessage("Pick the Black Figures ! Pick the " + to_string(arrCount[r]) + " Black Figures");
			Point m;
			int wc=0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == BLACK)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Black Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL "+ to_string(arrCount[r]) +" Black Figures ! you Clicked Incorrectly "+ to_string(wc)+" times");
					}
					pManager->UpdateInterface();
					i++;
				}
				else {
					wc++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try Again, you Picked Incorrectly "+to_string(wc)+" times");
				}
			}
			break;
		}
		case 1: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Blue Figures ! Pick the " + to_string(arrCount[r]) + " Blue Figures");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == BLUE)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Blue Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Blue Figures ! you Clicked Incorrectly " + to_string(wc) + " times");
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
			pOut->PrintMessage("Pick the Yellow Figures ! Pick the " + to_string(arrCount[r]) + " Yellow Figures");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == YELLOW)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Yellow Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Yellow Figures ! you Clicked Incorrectly " + to_string(wc) + " times");
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
		case 3: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Red Figures ! Pick the " + to_string(arrCount[r]) + " Red Figures");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == RED)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Red Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Red Figures ! you Clicked Incorrectly " + to_string(wc) + " times");
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
			pOut->PrintMessage("Pick the Orange Figures ! Pick the " + to_string(arrCount[r]) + " Orange Figures");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == ORANGE)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Orange Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Orange Figures ! you Clicked Incorrectly " + to_string(wc) + " times");
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
		case 5: {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pick the Green Figures ! Pick the " + to_string(arrCount[r]) + " Green Figures");
			Point m;
			int wc = 0;
			for (int i = 0; i < arrCount[r];)
			{
				pIn->GetPointClicked(m.x, m.y);
				CFigure* x = pManager->GetFigure(m.x, m.y);
				if (x->returnFillColor() == GREEN)
				{
					x->SetSelected(1);
					pManager->deletefigure(x);
					pOut->ClearStatusBar();
					pOut->PrintMessage("Good you picked " + to_string(i + 1) + " Green Figures from " + to_string(arrCount[r]) + " Figures!");
					if (i == arrCount[r] - 1) {
						pOut->ClearStatusBar();
						pOut->PrintMessage("Good job, You picked ALL " + to_string(arrCount[r]) + " Green Figures ! you Clicked Incorrectly " + to_string(wc) + " times");
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
}
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("NO Shapes TO PLay With");
	}
	return true;
}

bool ByColorAction::record_me() const
{
	return false;
}
