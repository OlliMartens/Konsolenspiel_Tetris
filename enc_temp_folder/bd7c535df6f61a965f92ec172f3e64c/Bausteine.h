#pragma once

struct tetris{

	char spielfeld[24][17] = {
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};

	int rows = sizeof(spielfeld) / sizeof(spielfeld[0]);	//Anzahl Spalten (waagerecht)
	int cols = sizeof(spielfeld[0]) / sizeof(spielfeld[0][0]);	//Anzahl Zeilen (senkrecht)

	int blocks[6][3][3]{
		{	//erster Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//zweiter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//dritter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//vierter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//f�nfter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//sechster Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		}
	};

};


/// <summary>
/// Zuf�llige Auswahl welche Form gerade auf dem Spielfeld erscheint 
/// </summary>
/// <param name="arrayForm">�bergabe des Spielfeld-Arrays</param>
/// <param name="status">Status gibt Information dar�ber, welche Form gerade ausgew�hlt wurde</param>
void randomForm(int& nextBlock);

void printBlocks(int nextBlock, tetris& tempBlock, int pos1, int pos2);

void rotateBlocks(int nextBlock, tetris& tempBlock);

template <class T> void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}
