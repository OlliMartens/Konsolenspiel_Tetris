#include <iostream>
#include <windows.h>
#include "Bausteine.h"

void randomForm(int& nextBlock) {
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 6;
}

void rotateBlocks(int nextBlock, tetris& tempBlock, int width, int height) {
	//jede for-Schleife hat ein < 3, da die Blöcke immmer 3x3 groß sind
	
	//temporäres Array
	int a[1][3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			a[0][j][3 - 1 - i] = tempBlock.blocks[nextBlock][i][j];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			tempBlock.blocks[nextBlock][i][j] = a[0][i][j];
	}
	
}

void printBlocks(int nextBlock, tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++) {
			if (tempBlock.blocks[nextBlock][i][j] == 1) {
				tempBlock.spielfeld[width + j][height + i] = char(178);
			}
		}
	}
}

bool rotateCollision(int nextBlock, tetris& tempBlock, int width, int height) {
	bool ok = true;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (tempBlock.spielfeld[width + j][height + i] != ' ') {
				ok = false;
			}
			else {
				ok = true;
			}
		}
	}

	//Drehen am rand nicht möglich
	if (width == 23 || width == 0) ok = false;

	return ok;
}

bool controlCollision(int nextBlock, tetris& tempBlock, int width, int height) {
	bool ok = true;
	
	return ok;
}

void shiftRightLeft(int& width) {
	
	//shift Right
	if (GetAsyncKeyState(0x27) && width < 23 ) {
		width++;
	}

	//shift Left
	if (GetAsyncKeyState(0x25) && width > -1) {
		width--;
	}
}

void deletePosition(int nextBlock, tetris& tempBlock, int width, int height) {
	//Löschen des alten Blocks vor dem drehen
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (tempBlock.blocks[nextBlock][i][j] == 1) {
				tempBlock.spielfeld[width + j][height + i] = ' ';
			}
		}
	}
}