#include <iostream>
#include <cmath>
#include "Bausteine.h"

void randomForm(int& nextBlock) {
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 6;
}

void rotateBlocks(int nextBlock, tetris& tempBlock, int pos1, int pos2) {
	//L�schen des alten Blocks vor dem drehen
	for (int pos1 = 0; pos1 < 2; pos1++)
	{
		for (int pos2 = 0; pos2 < 2; pos2++) {
			if (tempBlock.blocks[nextBlock][pos1][pos2] == 1) {
				tempBlock.spielfeld[12 + pos2][pos1] = ' ';
			}
		}
	}

	//jede for-Schleife hat ein < 3, da die Bl�cke immmer 3x3 gro� sind

	//Rotate the matrix about the main diagonal
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < i; j++)
			swap(tempBlock.blocks[nextBlock][i][j], tempBlock.blocks[nextBlock][j][i]);
	}

	//Rotate the matrix about middle column
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			swap(tempBlock.blocks[nextBlock][i][j], tempBlock.blocks[nextBlock][j][2 - j - 1]);
		}
	}
}

void printBlocks(int nextBlock, tetris& tempBlock,int pos1, int pos2) {
	for (int pos1 = 0; pos1 < 2; pos1++)
	{
		for (int pos2 = 0; pos2 < 2; pos2++) {
			if (tempBlock.blocks[nextBlock][pos1][pos2] == 1) {
				tempBlock.spielfeld[12 + pos2][pos1] = char(178);
			}
		}
	}
}


