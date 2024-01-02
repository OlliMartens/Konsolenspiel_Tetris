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
	//Breite, H�he, Fallgeschw.
	int width = 9, height = 0, down = 0;
	//n�chster Block, n�chste Blockfrabe, aktuelle Farbe
	int nextBlock = 0, nextColor = 0, aktColor = 0;

	//Array �bergabe aktueller Block
	int aktBlock[3][3];

	//Aktuelle Punkte
	int points = 0;
	//nur jedes 2 mal height++
	bool count = false;

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

	//***Spiel-loop*** 
	while (true)
	{
		//L�schen der alten Position
		deletePosition(aktBlock, Game, width, height);

		//jede 2. Runde height ++
		if (count == false) {
			height++;
			count = true;
		}
		else {
			count = false;
		}

		noCollision = isValid(aktBlock, Game, width, height);
		//Wenn keine Kollision
		if (noCollision) {
			
			ok = isValidShift(aktBlock, Game, width, height);
			shiftRightLeft(width, ok);


			//if fast down
			if (GetAsyncKeyState(0x28)) down = 75;
			else down = 0;

			//Wenn 'R' (0x52) gedr�ckt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (GetAsyncKeyState(0x52)) {
				rotateBlocks(aktBlock, Game, width, height);
			}
		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (!noCollision) {

			//Wenn bei height++ eine Kollision entstehen w�rde printe den Block an der letzten Position ohne Kollision
			//writeBlockToField ist hier auch wichtig, da nach randomBlock ein ganz neuer Block generiert wird
			height--;
			writeBlockToField(aktBlock, Game, width, height);


			//Pr�fen auf Game over
			if (gameOver(Game)) {
				system("cls");
				break;
			}

			//Pr�fen auf Reihe vollst�ndig (8 Pkt f�r jeden gesetzten Block)
			points = points + rowCompleted(Game) + 8;

			//Start Position
			height = 0;
			width = 9;
			aktColor = nextColor;
			//Neuer Block
			randomBlock(Game, aktBlock, nextBlock, nextColor);
		}

		//Ausgabe der beweglichen Elemente
		writeBlockToField(aktBlock, Game, width, height);
		showNextBlock(nextBlock, Game);
		showPoints(points, Game);
		printField(Game);

		//Fallgeschwindigkeit
		Sleep(100 - down);
	}
}
