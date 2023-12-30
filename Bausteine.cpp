#include <iostream>
#include <windows.h>
#include "Bausteine.h"

void randomForm(int& nextBlock) {
	
	srand((unsigned)time(NULL));
	nextBlock = rand() % 5;
}

void rotateBlocks(int aktBlock, tetris& tempBlock, int width, int height) {
	//jede for-Schleife hat ein < 3, da die Blöcke immmer 3x3 groß sind
	
	//temporäres Array
	int a[1][3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			a[0][j][3 - 1 - i] = tempBlock.blocks[aktBlock][i][j];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			tempBlock.blocks[aktBlock][i][j] = a[0][i][j];
	}
	
}

int rotatingStatus(int aktBlock, tetris& tempBlock, int width, int height) {
	static int  deg = 0;
	//Die Variable Degree wird bei jedem Aufruf um 1 erhöht (deg + 1 entspricht + 90°)
	deg++;

	switch (deg) {
	case 0:
		break;
	case 1:
		rotateBlocks(aktBlock, tempBlock, width, height);
		break;
	case 2:
		rotateBlocks(aktBlock, tempBlock, width, height);
		break;
	case 3:
		rotateBlocks(aktBlock, tempBlock, width, height);
		break;
	case 4:
		rotateBlocks(aktBlock, tempBlock, width, height);
		deg = 0;
		break;
	}

	return deg;
}

void printBlocks(int aktBlock, tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++) {
			if (tempBlock.blocks[aktBlock][i][j] == 1) {
				tempBlock.spielfeld[width + j][height + i] = char(178);
			}
		}
	}
}

int shiftCollision(int aktBlock, tetris& tempBlock, int width, int height, int deg) {
	//Status ok:
	// 0 = alles erlaubt
	// 1 = nur shift right
	// 2 = nur shift left
	static int ok = 0;

	switch (aktBlock)
	{
		case 0:	//erster Block
			switch (deg)
			{
				case 0: // 0° bzw. 360°
					if (width == -1) ok = 1;
					else if (width == 23) ok = 2;
					else ok = 0;
					break;
				case 1: // 90°
					if (width == -1) ok = 1;
					else if (width == 22) ok = 2;
					else ok = 0;
					break;
				case 2: // 180°
					if (width == -1) ok = 1;
					else if (width == 23) ok = 2;
					else ok = 0;
					break;
				case 3: // 270°
					if (width == 0) ok = 1;
					else if (width == 23) ok = 2;
					else ok = 0;
					break;
			}
			break;
		case 1:	//zweiter Block

			break;
		case 2:	//dritter Block

			break;
		case 3:	//vierter Block
		
			break;
		case 4: //fünfter Block

			break;
		case 5: //sechster Block

			break;

	}

	return ok;
}

bool controlCollision(int aktBlock, tetris& tempBlock, int width, int height) {
	bool ok = true;
	
	return ok;
}

void shiftRightLeft(int& width, int ok) {

	// Auf Ausrichtung des Blocks achten
	// 
	//shift Right
	if (GetAsyncKeyState(0x27) && (ok == 0 || ok == 1)) {
		width++;
	}

	//shift Left
	if (GetAsyncKeyState(0x25) && (ok == 0 || ok == 2)) {
		width--;
	}
}

void deletePosition(int aktBlock, tetris& tempBlock, int width, int height) {
	//Löschen des alten Blocks vor dem drehen
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (tempBlock.blocks[aktBlock][i][j] == 1) {
				tempBlock.spielfeld[width + j][height + i] = ' ';
			}
		}
	}
}