#include <iostream>
#include "Bausteine.h"

void randomForm(int& nextBlock) {
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 6;
}

void rotateBlocks() {

}

void printBlocks(int nextBlock, tetris& tempBlock,int pos1, int pos2) {
	for (int pos1 = 0; pos1 < 2; pos1++)
	{
		for (int pos2 = 0; pos2 < 2; pos2++) {
			if (tempBlock.blocks[nextBlock][pos1][pos2] == 1) {
				tempBlock.spielfeld[12 + pos2][pos1] = char(219);
			}
			//else {
			//	tempBlock.spielfeld[pos1][8 + pos2] = ' ';
			//}
		}
	}
}


