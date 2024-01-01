#include <iostream>
#include <windows.h>
#include "Bausteine.h"

void randomBlock(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock, int& color) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aktBlock[i][j] = tempblock.blocks[nextBlock][i][j];
		}
	}
	
	//zufälliger Block
	srand((unsigned)time(NULL));
	nextBlock = rand() % 6;
	//zufällige Blockfarbe
	color = rand() % 10;
	if (color == 0) color = 1;
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
			if (height + j < 0 || height + j - 1 > tempBlock.cols - 2) return false;
			if (tempBlock.spielfeld[width + i][height + j] != ' ') return false;

		}
	}
	return true;
}

int isValidShift(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	// 0 = shiften in beide Richtungen erlaubt
	// 1 = shiften nur nach rechts erlaubt
	// 2 = shiften nur nach links erlaubt
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (aktBlock[i][j] == 0) continue;
			if (width + i - 1 < 0) {
				return 1;
			}
			if (width + i > tempBlock.rows - 2) {
				return 2;
			}
			if (tempBlock.spielfeld[width + i + 1][height + j] != ' ') {
				return 3;
			}
		}

	}
	return 0;
}

void shiftRightLeft(int& width, int ok) {
	//shift Right
	if (GetAsyncKeyState(0x27) && (ok == 0 || ok == 1 )) {
		width++;
	}

	//shift Left
	if (GetAsyncKeyState(0x25) && (ok == 0 || ok == 2)) {
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

bool gameOver(tetris& tempBlock) {
	static int count = 0;
	for (int i = 0; i < tempBlock.rows; i++)
	{
		for (int j = 0; j < tempBlock.cols; j++)
		{
			if (tempBlock.spielfeld[i][j] != ' ') count++;
			if (count == 20) return true;
			
		}
		count = 0;
	}
	return false;
}

int rowCompleted(tetris& tempBlock) {
	static int count = 0;
	static int points = 0;
	points = 0;
	for (int i = 0; i < tempBlock.cols; i++)
	{
		for (int j = 0; j < tempBlock.rows; j++)
		{
			if (tempBlock.spielfeld[j][i] != ' ') count++;
			if (count == 20) {
				points = points + 80;
				//Punkte anders zählen, wenn mehrere Reihen voll sind
				for (int k = 0; k < tempBlock.rows; k++)
				{
					tempBlock.spielfeld[k][i] = '=';
					Sleep(20);
				}
				for (int k = 0; k < tempBlock.rows; k++)
				{
					tempBlock.spielfeld[k][i] = ' ';
				}
				//Funktion um alle Blöcke nach Unten zu setzen
			}

		}
		count = 0;
	}
	return points;
}


