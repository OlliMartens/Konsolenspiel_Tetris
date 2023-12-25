#include <iostream>
#include <cmath>
#include "Bausteine.h"

void randomForm(int& nextBlock) {
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 6;
}

void rotateBlocks(int nextBlock, tetris& tempBlock, int pos1, int pos2) {
	//Löschen des alten Blocks vor dem drehen
	for (int pos1 = 0; pos1 < 3; pos1++)
	{
		for (int pos2 = 0; pos2 < 3; pos2++) {
			if (tempBlock.blocks[nextBlock][pos1][pos2] == 1) {
				tempBlock.spielfeld[12 + pos2][pos1] = ' ';
			}
		}
	}

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

void printBlocks(int nextBlock, tetris& tempBlock ,int pos1, int pos2) {
	for (int pos1 = 0; pos1 < 3; pos1++)
	{
		for (int pos2 = 0; pos2 < 3; pos2++) {
			if (tempBlock.blocks[nextBlock][pos1][pos2] == 1) {
				tempBlock.spielfeld[12 + pos2][pos1] = char(178);
			}
		}
	}
}


