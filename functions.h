#pragma once

	const int ROWS = 20; //Anzahl Spalten (waagerecht)
	const int COLS = 20; //Anzahl Zeilen (senkrecht)
	const int numBlock = 6; //Anzahl der Unterschielichen Bl�cke f�r rand()

struct tetris{

	char spielfeld[ROWS][COLS] = {
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

	int blocks[6][3][3]{
		{	//erster Block
		{0,2,0},
		{0,2,0},
		{0,0,0}
		},
		{	//zweiter Block
		{0,8,0},
		{0,8,0},
		{0,8,0}
		},
		{	//dritter Block
		{0,4,0},
		{0,4,0},
		{4,4,0}
		},
		{	//vierter Block
		{0,5,0},
		{5,5,0},
		{5,0,0}
		},
		{	//f�nfter Block
		{6,6,0},
		{6,6,0},
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
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="nextBlock"> n�chster Block </param>
/// <param name="color"> zuf�llige Frabe des Blocks </param>
void randomBlock(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock);

/// <summary>
/// Schreiben der Bl�cke in das Spielfeld -> noch ohne Ausgabe (cout)
/// </summary>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
void writeBlockToField(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// Funktion zum rotieren der Matrix blocks
/// </summary>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
void rotateBlocks(int(&aktBlock)[3][3], tetris tempBlock, int width, int height);

/// <summary>
/// Block nach links und rechts bewegen
/// </summary>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="ok"> Fehlermeldung ist shift m�glich </param>
void shiftRightLeft(int& width, int ok);

/// <summary>
/// L�schen des alten Blocks
/// </summary>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
void deletePosition(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// �berpr�ft, ob eine vertikale Kollision besteht
/// </summary>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
/// <returns> Fehlermeldung f�r Kollision</returns>
bool isValid(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// �berpr�ft, ob eine horizontale Kollision besteht
/// </summary>
/// <param name="aktBlock">aktueller bzw. n�chster Block</param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array H�he ( y-Koordinate)</param>
/// <returns> Fehlermeldung f�r Kollision bei Shift </returns>
int isValidShift(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

/// <summary>
/// Gibt den Status wieder, ob Game Over true oder false ist
/// </summary>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <returns>Status Gamer Over</returns>
bool checkGameOver(tetris& tempBlock);

/// <summary>
/// �berpr�fung, ob eine Reihe Komplett ist und anschlie�ende Punkte ausgabe
/// </summary>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <returns> Wiedergabe der Punkte </returns>
int rowCompleted(tetris& tempBlock);

/// <summary>
/// Alle Elemente auf dem Spielfeld um 1 nach unten verschieben
/// </summary>
/// <param name="spielfeld"> �bergabe des Spielfeld mit c.b.r. </param>
void shiftElementsDown(char(&spielfeld)[ROWS][COLS]);

/// <summary>
/// Ausgabe des Spielfeld auf der Konsole
/// </summary>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
void printField(tetris& tempBlock);

/// <summary>
/// Erh�hen des Spieltempos
/// </summary>
/// <param name="rounds"> gez�hlte Runde </param>
/// <param name="speed"> �nderbares Tempo c.b.r.</param>
void speedUp(int rounds, int& speed);

/// <summary>
///  Spielfeld l�schen, wenn Game Over
/// </summary>
/// <param name="tempBlock"> �bergabe des Spielfeld mit c.b.r. </param>
void clearField(char(&spielfeld)[ROWS][COLS]);