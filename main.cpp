#include <iostream>
#include<windows.h>
#include <conio.h>	
#include <string>
#include "Bausteine.h"
#include "GUI.h"



using namespace std;

int main() {
	
	tetris Game;
	noCursor();

	int posA = 0, posB = 0;
	int nextBlock = 1;

	//***Spielfeld in Bunt*** 
	while (true)
	{
		U_square(20, 1, 27, 18);
		//simple_square(41, 8, 28, 1);
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
				go(i + 21, j + 1);
				cout << Game.spielfeld[i][j];
			}
			cout << endl;
		}

		Sleep(500);
		system("cls");
	}
	

}
