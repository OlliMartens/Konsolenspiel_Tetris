#include <iostream>
#include <windows.h>
#include "Bausteine.h"

void randomForm(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aktBlock[i][j] = tempblock.blocks[nextBlock][i][j];
		}
	}
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 5;

}

void rotateBlocks(int(&aktBlock)[3][3], tetris tempBlock, int width, int height) {
	//jede for-Schleife hat ein < 3, da die Blöcke immmer 3x3 groß sind
	
	//temporäres Array
	int a[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			a[j][3 - 1 - i] = aktBlock[i][j];
	}

	//Wenn das temporäre Array keine Kollision hat kann es zum aktuellen werden
	if (isValid(a, tempBlock, width, height)) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				aktBlock[i][j] = a[i][j];
		}
	}
}

void printBlocks(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++) {
			if (aktBlock[i][j] == 1) {
				tempBlock.spielfeld[width + i][height + j] = char(178);
			}
		}
	}
}


bool isValid(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (aktBlock[i][j] == 0) continue;
			if (width + i - 1 < 0 || width + i - 1 > tempBlock.rows - 2 || height + j < 0 || height + j - 1 > tempBlock.cols - 1)
				return false;
			if (tempBlock.spielfeld[width + i][height + j] != ' ')return false;

		}
	}
	return true;
}

void shiftRightLeft(int& width) {

	// Auf Ausrichtung des Blocks achten
	// 
	//shift Right
	if (GetAsyncKeyState(0x27)) {
		width++;
	}

	//shift Left
	if (GetAsyncKeyState(0x25)) {
		width--;
	}
}

void deletePosition(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	//Löschen des alten Blocks vor dem drehen
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (aktBlock[i][j]) {
				tempBlock.spielfeld[width + i][height + j] = ' ';
			}
		}
	}
}
