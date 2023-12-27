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


	int posA = 0, posB = 0;
	int nextBlock = 1;

	//***Spielfeld in Bunt*** 
	while (true)
	{
		//GUI Spielfeld
		//Spielfeld (9 = blau)
		simple_U(30, 1, 27, 18, 9);
		simple_U(29, 1, 27, 18, 9);
		controlsGUI();
		highscoreGUI();
		nextBlockGUI();


		//Spielfeldarry in dem U_square printen
		if (true) {
			rotateBlocks(nextBlock,Game, posA, posB);
		}
		printBlocks(nextBlock, Game, posA, posB);

		for (int i = 0; i < Game.rows; i++)
		{
			for (int j = 0; j < Game.cols; j++)
			{
				//Game.spielfeld[i][j] = '1';
				color(3);
				go(i + 31, j + 1);
				cout << Game.spielfeld[i][j];
			}
			cout << endl;
		}

		Sleep(500);
		system("cls");
	}
}
