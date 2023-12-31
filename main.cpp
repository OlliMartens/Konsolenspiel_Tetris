#include <iostream>
#include <windows.h>
#include <conio.h>	
#include <string>
//#include <time.h>
#include "Bausteine.h"
#include "GUI.h"



using namespace std;

int main() {
	srand((unsigned)time(NULL));
	
	//Struct Aufruf
	tetris Game;
	
	//Cursor ausblenden
	noCursor();
	
	//Hilfsvariablen
	bool noCollision = true;
	int ok = 0, deg = 0;
	int width = 9, height = 0, down = 0;
	//aktueller und n�chster Block
	int nextBlock = 0;

	//Array �bergabe
	int aktBlock[3][3];


	//GUI Spielfeld
		//Spielfeld (9 = blau)
	simple_U(30, 1, 22, 21, 9);
	simple_U(29, 1, 24, 21, 9);
	controlsGUI();
	highscoreGUI();
	nextBlockGUI();

	//Erzeugen des Startblocks
	nextBlock = rand() % 5;
	randomForm(Game, aktBlock, nextBlock);

	//***Spielfeld in Bunt*** 
	while (true)
	{
		deletePosition(aktBlock, Game, width, height);
		height++;
		noCollision = isValid(aktBlock, Game, width, height);
		
		//Wenn keine Kollision
		if (noCollision) {
			//L�schen der alten Position
			
			//if rechts links
			ok = isValidShift(aktBlock, Game, width, height);
			shiftRightLeft(width, ok);


			//if fast down
			if (GetAsyncKeyState(0x28)) down = 150;
			else down = 0;

			//Wenn 'R' (0x52) gedr�ckt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (GetAsyncKeyState(0x52)) {
				rotateBlocks(aktBlock, Game, width, height);
			}
		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (!noCollision) {
			//Wenn bei height++ eine Kollision entstehen w�rde printe den Block an der letzten Position ohne Kollision
			//printBlocks ist hier auch wichtig, da nach randomForm ein ganz neuer Block generiert wird
			height--;
			printBlocks(aktBlock, Game, width, height);

			//Start Position
			height = 0;
			//Neuer Block
			randomForm(Game, aktBlock, nextBlock);
		}

		//Spielfeldarry in simple_U printen
		printBlocks(aktBlock, Game, width, height);

		for (int i = 0; i < Game.rows; i++)
		{
			for (int j = 0; j < Game.cols; j++)
			{
				//Game.spielfeld[i][j] = '1';
				color(3);
				go(i + 31, j +1);
				cout << Game.spielfeld[i][j];
			}
			cout << endl;
		}

		Sleep(200-down);
		//system("cls");
	}
}
