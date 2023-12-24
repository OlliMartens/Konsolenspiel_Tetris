#include <iostream>

void randomForm(char arrayForm[24][16],int status) {
	
	srand((unsigned)time(NULL));
	status = rand() % 6;
}



void blocks() {

	char blocks[6][3][3]{
		{	//erster Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//zweiter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//dritter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//vierter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//fünfter Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		},
		{	//sechster Block
		{0,1,0},
		{0,1,0},
		{0,0,0}
		}
	};
	
}

void rotateBlocks() {

}

void printBlocks(char feld[24][16]) {

}


