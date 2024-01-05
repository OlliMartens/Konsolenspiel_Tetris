#include <iostream>
#include <windows.h>
#include "functions.h"
#include "GUI.h"

using namespace std;

void randomBlock(tetris& tempblock, int(&aktBlock)[3][3], int& nextBlock) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aktBlock[i][j] = tempblock.blocks[nextBlock][i][j];
		}
	}
	
	//zufälliger Block
	srand((unsigned)time(NULL));
	nextBlock = rand() % numBlock;
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

void writeBlockToField(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++) {
			if (aktBlock[i][j] != 0) {
				tempBlock.spielfeld[width + i][height + j] = aktBlock[i][j];
			}
		}
	}
}

bool isValid(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (aktBlock[i][j] == 0) continue;
			if (height + j < 0 || height + j - 1 > COLS - 2) return false;
			if (tempBlock.spielfeld[width + i][height + j] != ' ') return false;

		}
	}
	return true;
}

int isValidShift(int(&aktBlock)[3][3], tetris& tempBlock, int width, int height) {
	// 0 = shiften in beide Richtungen erlaubt
	// 1 = shiften nur nach rechts erlaubt (Spielfeldrand links)
	// 2 = shiften nur nach links erlaubt (Spielfeldrand rechts)
	// 3 = shiften nur nach links erlaubt (anderer Block rechts)
	// 4 = shiften nur nach rechts erlaubt (anderer Block links)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (aktBlock[i][j] == 0) continue;
			if (width + i - 1 < 0) {
				return 1;
			}
			if (width + i > ROWS - 2) {
				return 2;
			}
			if (tempBlock.spielfeld[width + i + 1][height + j] != ' ') {
				return 3;
			}
			if (tempBlock.spielfeld[width + i - 1][height + j] != ' ') {
				return 4;
			}
		}

	}
	return 0;
}

void shiftRightLeft(int& width, int ok) {
	//shift Right
	if (GetAsyncKeyState(0x27) && (ok == 0 || ok == 1 || ok == 4)) {
		width++;
	}

	//shift Left
	if (GetAsyncKeyState(0x25) && (ok == 0 || ok == 2 || ok == 3)) {
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
	//Wenn in der letzten Reihe ein Block plaziert wurde = Game over
	for (int i = 0; i < ROWS; i++)
	{
			if (tempBlock.spielfeld[i][0] != ' ') return true;
	}
	return false;
}

int rowCompleted(tetris& tempBlock) {
	static int count = 0;
	static int points = 0;
	static int lineCount = 0;
	//zurücksetzen der Punkte
	points = 0;
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (tempBlock.spielfeld[j][i] != ' ') count++;
			if (count == 20) {
				//Punkte anders zählen, wenn mehrere Reihen voll sind
				for (int k = 0; k < ROWS; k++)
				{
					tempBlock.spielfeld[k][i] = '=';
				}
				printField(tempBlock);
				Sleep(500);
				shiftElementsDown(tempBlock.spielfeld);
				lineCount++;
			}

		}
		count = 0;
	}
	//Punktezählsystem
	switch (lineCount)
	{
	case 0:
		points = 0;
		break;
	case 1:
		points = 40;
		break;
	case 2:
		points = 100;
		break;
	case 3:
		points = 300;
		break;
	}
	//zurücksetzen von lineCount
	lineCount = 0;
	return points;
}

void shiftElementsDown(char (&spielfeld)[ROWS][COLS]) {
	for (int i = 0; i < COLS; ++i)
	{
		for (int j = ROWS - 1; j >= 1; --j)
		{
			spielfeld[i][j] = spielfeld[i][j - 1];
		}
	}
}

void printField(tetris& tempBlock){

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			go(i + 31, j + 1);
			if(tempBlock.spielfeld[i][j] == ' ')
			{
				cout << tempBlock.spielfeld[i][j];
				continue;
			}
			else if (tempBlock.spielfeld[i][j] == '=') {
				color(7);
				cout << tempBlock.spielfeld[i][j];
				continue;
			}
			else {
				color(tempBlock.spielfeld[i][j]);
				cout << char(178);
			}
		}
		cout << endl;
	}
}

void speedUp(int rounds, int& speed) {
	if (rounds <= 30) speed = 0;
	else if(rounds>30)speed = 40;
	else if(rounds>60)speed = 60;
	else if(rounds>90)speed = 95;

}

void clearField(char(&spielfeld)[ROWS][COLS]) {
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			spielfeld[j][i] = ' ';

		}
	}
}