#include <iostream>
#include <windows.h>
#include <conio.h>	
#include <string>
#include "Bausteine.h"
#include "GUI.h"



using namespace std;

int main() {
	srand((unsigned)time(NULL));
	
	//Struct Aufruf
	tetris Game;
	
	//Cursor ausblenden
	noCursor();

	//Fehlermeldungen
	bool noCollision = true;
	int ok = 0;
	//Breite, Höhe, Fallgeschw.
	int width = 9, height = 0, down = 0;
	//nächster Block, nächste Blockfrabe, aktuelle Farbe
	int nextBlock = 0, nextColor = 0, aktColor = 0;

	//Array Übergabe aktueller Block
	int aktBlock[3][3];


	//GUI Spielfeld
	//Spielfeld (9 = blau)
	simple_U(30, 1, 22, 21, 9);
	simple_U(29, 1, 24, 21, 9);
	controlsGUI();
	highscoreGUI();
	nextBlockGUI();

	//Erzeugen des Startblocks + Farbe
	nextBlock = rand() % 5;
	aktColor = rand() % 10;
	if (color == 0) aktColor = 1;
	randomBlock(Game, aktBlock, nextBlock, nextColor);

	//***Spielfeld in Bunt*** 
	while (true)
	{
		deletePosition(aktBlock, Game, width, height);
		height++;
		noCollision = isValid(aktBlock, Game, width, height);
		
		//Wenn keine Kollision
		if (noCollision) {
			//Löschen der alten Position
			
			//if rechts links
			ok = isValidShift(aktBlock, Game, width, height);
			shiftRightLeft(width, ok);


			//if fast down
			if (GetAsyncKeyState(0x28)) down = 150;
			else down = 0;

			//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (GetAsyncKeyState(0x52)) {
				rotateBlocks(aktBlock, Game, width, height);
			}
		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (!noCollision) {
			//Wenn bei height++ eine Kollision entstehen würde printe den Block an der letzten Position ohne Kollision
			//printBlocks ist hier auch wichtig, da nach randomBlock ein ganz neuer Block generiert wird
			height--;
			printBlocks(aktBlock, Game, width, height);

			//Prüfen auf Game over
			if (gameOver(Game)) {
				system("cls");
				break;
			}
			//Prüfen auf Reihe vollständig
			int gamePoints = points(Game);

			//Start Position
			height = 0;
			int width = 9;
			aktColor = nextColor;
			//Neuer Block
			randomBlock(Game, aktBlock, nextBlock, nextColor);
		}

		//Spielfeldarry in simple_U printen
		printBlocks(aktBlock, Game, width, height);
		showNextBlock(nextBlock, Game);
		for (int i = 0; i < Game.rows; i++)
		 {
			for (int j = 0; j < Game.cols; j++)
			{
				color(aktColor);
				go(i + 31, j +1);
				cout << Game.spielfeld[i][j];
			}
			cout << endl;
		}

		//Fallgeschwindigkeit
		Sleep(200-down);
	}
}
