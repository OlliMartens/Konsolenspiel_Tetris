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
	int width = 12, height = 0;
	int nextBlock = 0;

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
			deletePosition(nextBlock, Game, width, height);

			//if rechts links
			shiftRightLeft(width);
			//if fast down


			//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
			if (nextBlock != 4 && rotateCollision(nextBlock, Game, width, height) && GetAsyncKeyState(0x52)) {
				rotateBlocks(nextBlock, Game, width, height);
			}



		}



		//Spielfeldarry in dem U_square printen
		printBlocks(nextBlock, Game, width, height);

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
