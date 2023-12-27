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

		//Controls (5 = violett)
		color(7);
		go(1, 1);
		cout << "Controls" << endl;
		simple_square(1, 2, 25, 17, 5);
		//Spielfeld (9 = blau)
		simple_U(30, 1, 27, 18, 9);
		simple_U(29, 1, 27, 18, 9);
		//Nächster Block (6 = gelb)
		go(60,1);
		cout << "Next Block" << endl;
		simple_square(60, 2, 20, 8, 6);
		//Dein Highscore (4 = rot)
		go(60, 10);
		cout << "Highscore" << endl;
		simple_square(60, 11, 20, 8, 4);


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
