#pragma once

struct tetris{

	char spielfeld[20][20] = {
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}

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
		{	//fünfter Block
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
/// Zufällige Auswahl welche Form gerade auf dem Spielfeld erscheint
/// </summary>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="nextBlock"> nächster Block </param>
/// <param name="color"> zufällige Frabe des Blocks </param>
void randomBlock(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock, int& color);

/// <summary>
/// Schreiben der Blöcke in das Spielfeld -> noch ohne Ausgabe (cout)
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
void printBlocks(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// Funktion zum rotieren der Matrix blocks
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
void rotateBlocks(int(&aktBlock)[3][3], tetris tempBlock, int width, int height);

/// <summary>
/// Block nach links und rechts bewegen
/// </summary>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="ok"> Fehlermeldung ist shift möglich </param>
void shiftRightLeft(int& width, int ok);

/// <summary>
/// Löschen des alten Blocks
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
void deletePosition(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// Überprüft, ob eine vertikale Kollision besteht
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
/// <returns> Fehlermeldung für Kollision</returns>
bool isValid(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// Überprüft, ob eine horizontale Kollision besteht
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
/// <returns> Fehlermeldung für Kollision bei Shift </returns>
int isValidShift(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

bool gameOver(tetris& tempBlock);

int rowCompleted(tetris& tempBlock);