#pragma once

struct tetris{

	char spielfeld[25][17] = {
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
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
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
		{0,1,0}
		},
		{	//dritter Block
		{0,1,0},
		{0,1,0},
		{1,1,0}
		},
		{	//vierter Block
		{0,1,0},
		{1,1,0},
		{1,0,0}
		},
		{	//f�nfter Block
		{1,1,0},
		{1,1,0},
		{0,0,0}
		},
		{	//sechster Block
		{0,1,0},
		{1,1,0},
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

/// <summary>
/// Schreiben der Bl�cke in das Spielfeld -> noch ohne Ausgabe (cout)
/// </summary>
/// <param name="nextBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
void printBlocks(int nextBlock, tetris& tempBlock, int width, int height);

/// <summary>
/// Funktion zum rotieren der Matrix blocks
/// </summary>
/// <param name="nextBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
void rotateBlocks(int nextBlock, tetris& tempBlock, int width, int height);

bool rotateCollision(int nextBlock, tetris& tempBlock, int width, int height);

bool controlCollision(int nextBlock, tetris& tempBlock, int width, int height);

void shiftRightLeft(int& width);

void deletePosition(int nextBlock, tetris& tempBlock, int width, int height);