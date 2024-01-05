#pragma once

	const int ROWS = 20; //Anzahl Spalten (waagerecht)
	const int COLS = 20; //Anzahl Zeilen (senkrecht)
	const int numBlock = 6; //Anzahl der Unterschielichen Blöcke für rand()

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
		{	//fünfter Block
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
/// Zufällige Auswahl welche Form gerade auf dem Spielfeld erscheint
/// </summary>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="nextBlock"> nächster Block </param>
/// <param name="color"> zufällige Frabe des Blocks </param>
void randomBlock(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock);

/// <summary>
/// Schreiben der Blöcke in das Spielfeld -> noch ohne Ausgabe (cout)
/// </summary>
/// <param name="aktBlock">aktueller bzw. nächster Block</param>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <param name="width">Array Breite ( x-Koordinate)</param>
/// <param name="height">Array Höhe ( y-Koordinate)</param>
void writeBlockToField(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height);

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

/// <summary>
/// Gibt den Status wieder, ob Game Over true oder false ist
/// </summary>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <returns>Status Gamer Over</returns>
bool checkGameOver(tetris& tempBlock);

/// <summary>
/// Überprüfung, ob eine Reihe Komplett ist und anschließende Punkte ausgabe
/// </summary>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
/// <returns> Wiedergabe der Punkte </returns>
int rowCompleted(tetris& tempBlock);

/// <summary>
/// Alle Elemente auf dem Spielfeld um 1 nach unten verschieben
/// </summary>
/// <param name="spielfeld"> Übergabe des Spielfeld mit c.b.r. </param>
void shiftElementsDown(char(&spielfeld)[ROWS][COLS]);

/// <summary>
/// Ausgabe des Spielfeld auf der Konsole
/// </summary>
/// <param name="tempBlock">Übergabe des structs mit c.b.r.</param>
void printField(tetris& tempBlock);

/// <summary>
/// Erhöhen des Spieltempos
/// </summary>
/// <param name="rounds"> gezählte Runde </param>
/// <param name="speed"> änderbares Tempo c.b.r.</param>
void speedUp(int rounds, int& speed);

/// <summary>
///  Spielfeld löschen, wenn Game Over
/// </summary>
/// <param name="tempBlock"> Übergabe des Spielfeld mit c.b.r. </param>
void clearField(char(&spielfeld)[ROWS][COLS]);