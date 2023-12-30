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
	
	//Hilfsvariablen
	bool noCollision = true;
	int ok = 0;
	int width = 11, height = 0, deg = 0;
	//aktueller und nächster Block
	int nextBlock = 0;

	//Array Übergabe
	int aktBlock[3][3];


	//GUI Spielfeld
		//Spielfeld (9 = blau)
	simple_U(30, 1, 27, 18, 9);
	simple_U(29, 1, 29, 18, 9);
	controlsGUI();
	highscoreGUI();
	nextBlockGUI();

	//Erzeugen des Startblocks
	nextBlock = rand() % 5;
	randomForm(Game, aktBlock, nextBlock);

	//***Spielfeld in Bunt*** 
	while (true)
	{
		//
		//Wenn keine Kollision
		noCollision =  isValid(aktBlock, Game, width, height);

		if (noCollision) {
			//Löschen der alten Position
			deletePosition(aktBlock, Game, width, height);

			//if rechts links
			ok = isValidShift(aktBlock, Game, width, height);
			shiftRightLeft(width, ok);


			//if fast down


			//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (GetAsyncKeyState(0x52)) {
				rotateBlocks(aktBlock, Game, width, height);
			}

		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (false) {
			
		}

		go(30, 50);
		cout << "deg: " << deg <<endl;
		cout << "width: " << width << endl;
		cout << "ok: " << ok << endl;

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

		Sleep(50);
		//system("cls");
	}
}
