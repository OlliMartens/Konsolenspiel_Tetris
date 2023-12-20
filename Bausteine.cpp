#include <iostream>

void randomForm(char arrayForm[25][18],int status) {

}

//, int positionY

int viereck(char arrayForm[25][18], int a, int b, int c, int d, int e, int f,int positionX) {
	//Löschen des letzten Feldes über der Form
	arrayForm[positionX - 1][8] = ' ';
	arrayForm[positionX - 1][9] = ' ';
	arrayForm[positionX][8] = ' ';
	arrayForm[positionX][9] = ' ';
	//Position der Form
	arrayForm[a][b] = char(254);
	arrayForm[c][d] = char(254);
	arrayForm[e][f] = char(254);
	return 1;
}

void formenRotieren(int& a, int& b, int& c, int& d, int& e, int& f) {

	static int aufrufe = 0;

	switch (aufrufe)
	{
	case 0:
		a++;
		d++;
		e--;
		break;
	case 1:
		b--;
		c++;
		f++;
		break;
	case 2:
		a--;
		d--;
		e++;
		break;
	case 3:
		b++;
		c--;
		f--;
		break;
	}
	if (aufrufe > 3) aufrufe = 0;
	aufrufe++;
}


