#include <iostream>
#include<windows.h>
#include <conio.h>	
#include <string>
#include "Bausteine.h"
#include "GUI.h"



using namespace std;

int main() {
	
	//Struct Aufruf
	tetris Game;
	//Cursor ausblenden
	noCursor();

	//Hilfsvariablen
	int ok = 0;
	int width = 11, height = 0, deg = 0;
	//aktueller und nächster Block
	int aktBlock = 0, nextBlock = 0;
	


	//GUI Spielfeld
		//Spielfeld (9 = blau)
	simple_U(30, 1, 27, 18, 9);
	simple_U(29, 1, 29, 18, 9);
	controlsGUI();
	highscoreGUI();
	nextBlockGUI();


	//***Spielfeld in Bunt*** 
	while (true)
	{
		
		//Wenn keine Kollision
		//controlCollision(nextBlock, Game, posA, posB)
		if (true) {
			//Löschen der alten Position
			deletePosition(aktBlock, Game, width, height);

			//if rechts links
			ok = shiftCollision(aktBlock, Game, width, height, deg);
			shiftRightLeft(width, ok);

			//if fast down


			//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (aktBlock != 4 && GetAsyncKeyState(0x52)) {
				
				deg = rotatingStatus(aktBlock, Game, width, height);
			}

		}
		//Wenn Kollision -> setze Block und nicht delete und generiere neuen Block
		else if (false) {
			randomForm(aktBlock);
		}

		go(30, 50);
		cout << "deg: " << deg <<endl;
		cout << "width: " << width << endl;
		cout << "aktBlock: " << aktBlock << endl;
		cout << "ok: " << ok << endl;

		//Spielfeldarry in simple_U printen
		printBlocks(aktBlock, Game, width, height);

		for (int i = 0; i < Game.rows; i++)
		{
			for (int j = 0; j < Game.cols; j++)
			{
				//Game.spielfeld[i][j] = '1';
				color(3);
				go(i + 31, j);
				cout << Game.spielfeld[i][j];
			}
			cout << endl;
		}

		Sleep(50);
		//system("cls");
	}
}
