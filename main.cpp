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
	int posA = 0, posB = 0;
	int nextBlock = 0;

	//***Spielfeld in Bunt*** 
	while (true)
	{
		//GUI Spielfeld
		//Spielfeld (9 = blau)
		simple_U(30, 1, 27, 18, 9);
		simple_U(29, 1, 29, 18, 9);
		controlsGUI();
		highscoreGUI();
		nextBlockGUI();

		//Wenn keine Kollision
		if (controlCollision(nextBlock, Game, posA, posB)) {
		//if rechts links
		//if fast down


		//Wenn 'R' (0x52) gedrückt dann rotieren -> Block 5 muss nicht rotiert werden, da Viereck
		if (nextBlock != 4 && rotateCollision(nextBlock, Game, posA, posB) && GetAsyncKeyState(0x52)) {
			rotateBlocks(nextBlock, Game, posA, posB);
		}



		}



		//Spielfeldarry in dem U_square printen
		printBlocks(nextBlock, Game, posA, posB);

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

		Sleep(500);
		system("cls");
	}
}
