#include <iostream>
#include <windows.h>
#include <conio.h>	
#include <string>
#include "functions.h"
#include "GUI.h"
#include "GameOver.h"

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
	//Breite, Höhe, Fallgeschw., Fallgeschw.-Änderung, Anzahl Runden
	int width = 9, height = 0, speed = 0, down = 0, rounds = 0;
	//nächster Block, nächste Blockfrabe, aktuelle Farbe
	int nextBlock = 0, nextColor = 0, aktColor = 0;

	//Array Übergabe aktueller Block
	int aktBlock[3][3];

	//Aktuelle Punkte und Nutzername
	int points = 0;
	string username;
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
		//Löschen der alten Position
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

			//automatische Erhöhung des Spieltempos
			speedUp(rounds, speed);

			//if fast down
			if (GetAsyncKeyState(0x28) && speed <= 75) {
				down = speed;
				speed = 75;
			}
			else if (speed > down && speed != 95) speed = down;

			//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (GetAsyncKeyState(0x52)) {
				rotateBlocks(aktBlock, Game, width, height);
			}
		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (!noCollision) {

			//Wenn bei height++ eine Kollision entstehen würde printe den Block an der letzten Position ohne Kollision
			//writeBlockToField ist hier auch wichtig, da nach randomBlock ein ganz neuer Block generiert wird
			height--;
			writeBlockToField(aktBlock, Game, width, height);

			//Prüfen auf Game over
			if (gameOver(Game)) {
				system("cls");
				break;
			}

			//plazierte Blöcke
			if (rounds <= 120) {
				rounds++;
			}

			//Prüfen auf Reihe vollständig (8 Pkt für jeden gesetzten Block)
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
		showPoints(points, Game, rounds);
		printField(Game);

		//Fallgeschwindigkeit
		Sleep(100 - speed);
	}
	gameOver(points, username);
}
