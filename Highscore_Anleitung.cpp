#include <conio.h>
#include "Highscore_Anleitung.h"
#include "GUI.h"

using namespace std;

void podium(vector<Daten>& dataArray)
{
	system("cls");
	int platz = 1;
	const int x = 16;
	const int y = 16;
	char spielfeld[x][y] = { {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} };
	/////   Ausgabe der 1, 2 und 3   /////
	cout << endl;

	color(6);
	cout << setw(78) << " " << " " << char(219) << char(219) << endl
		<< setw(78) << " " << " " << char(219) << char(219) << endl
		<< setw(78) << " " << " " << char(219) << char(219) << endl
		<< setw(78) << " " << " " << char(219) << char(219) << endl
		<< setw(78) << " " << " " << char(219) << char(219) << endl;
	color(7);

	color(8);
	cout << setw(47) << " " << char(219) << char(219) << " " << endl;
	cout << setw(47) << char(219) << " " << " " << char(219);
	color(3);
	cout << setw(61) << char(219) << char(219) << char(219) << char(219) << endl;
	color(8);
	cout << setw(47) << " " << " " << " " << char(219);
	color(3);
	cout << setw(64) << char(219) << endl;
	color(8);
	cout << setw(47) << " " << " " << char(219) << " ";
	color(3);
	cout << setw(61) << char(219) << char(219) << char(219) << char(219) << endl;
	color(8);
	cout << setw(47) << " " << char(219) << " " << " ";
	color(3);
	cout << setw(64) << char(219) << endl;
	color(8);
	cout << setw(47) << char(219) << char(219) << char(219) << char(219);
	color(3);
	cout << setw(61) << char(219) << char(219) << char(219) << char(219) << endl;
	color(7);
	/////   Ausgabe der Highscores   /////
	cout << " " << endl;

	if (dataArray.size() <= 0)
	{
		cout << setw(88) << "Noch nicht belegt" << endl;
	}
	else
	{
		cout << setw(86) << dataArray[0].username << endl;
		cout << setw(80) << dataArray[0].highscore << " Punkte" << endl;
	}
	if (dataArray.size() <= 1)
	{
		cout << setw(57) << "Noch nicht belegt" << endl;
	}
	else
	{
		cout << setw(55) << dataArray[1].username << endl;
		cout << setw(49) << dataArray[1].highscore << " Punkte" << endl;
	}
	if (dataArray.size() <= 2)
	{
		cout << setw(120) << "Noch nicht belegt" << endl;
	}
	else
	{
		cout << setw(118) << dataArray[2].username << endl;
		cout << setw(112) << dataArray[2].highscore << " Punkte" << endl;
	}
	//////    TOP 1    //////
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 1; x++)
		{
			cout << endl;
			cout << "\t\t\t\t";
			for (int y = 0; y < 16; y++)
			{
				cout << spielfeld[x][y] << " ";
			}
			for (int i = 0; i < 32; i++)
			{
				color(6);
				cout << char(219);
			}
			for (int y = 0; y < 16; y++)
			{
				color(7);
				cout << spielfeld[x][y] << " ";
			}
			//Sleep(100);
		}
	}
	//////    TOP 2    //////
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 1; x++)
		{
			cout << endl;
			cout << "\t\t\t\t";
			for (int y = 0; y < 32; y++)
			{
				color(8);
				cout << char(219);
			}
			for (int i = 0; i < 32; i++)
			{
				color(6);
				cout << char(219);
			}
			for (int y = 0; y < 16; y++)
			{
				color(7);
				cout << spielfeld[x][y] << " ";
			}
			//Sleep(100);
		}
	}
	//////    TOP 3    ///////
	for (int i = 0; i < 6; i++)
	{
		for (int x = 0; x < 1; x++)
		{
			cout << endl;
			cout << "\t\t\t\t";
			for (int y = 0; y < 32; y++)
			{
				color(8);
				cout << char(219);
			}
			for (int i = 0; i < 32; i++)
			{
				color(6);
				cout << char(219);
			}
			for (int y = 0; y < 32; y++)
			{
				color(3);
				cout << char(219);
			}
			//Sleep(100);
		}
	}
	color(7);
	/////   Restliche Highscores   /////
	cout << endl << endl;
	cout << setw(33);
	for (int i = 0; i < 49; i++)
	{
		cout << char(219) << " ";
	}
	cout << endl;
	if (dataArray.size() >= 4)
	{
		for (int i = 3; i < dataArray.size(); i++)
		{
			platz = i + 1;
			cout << setw(33) << char(219) << setw(96) << char(219);
			cout << endl << setw(69) << platz << ". Platz: "
				<< dataArray[i].username << " " << dataArray[i].highscore
				<< " Punkte" << endl;
		}
	}
	else
	{
		cout << setw(33) << char(219) << setw(96) << char(219);
		cout << endl << setw(101) << "Noch keine weiteren Highscores vorhanden" << endl;
	}

	cout << setw(33) << char(219) << setw(96) << char(219) << endl;
	cout << setw(33);
	for (int i = 0; i < 49; i++)
	{
		cout << char(219) << " ";
	}
	//Zurück zum Stratmenu
	cout << endl <<"\n\n\t\t\t\tPress Escape to go back to Menu";
	int keyH = 0;
	while (keyH != 27)
	{
		keyH = _getch();
	}
}



void sortierVektor(vector<Daten>& dataArray)
{
	int best = 0;
	string beste;
	for (int i = 0; i < dataArray.size(); i++)
	{
		for (int j = i + 1; j < dataArray.size(); j++)
		{
			if (dataArray[i].highscore < dataArray[j].highscore)
			{
				best = dataArray[i].highscore;
				dataArray[i].highscore = dataArray[j].highscore;
				dataArray[j].highscore = best;

				beste = dataArray[i].username;
				dataArray[i].username = dataArray[j].username;
				dataArray[j].username = beste;
			}
		}
	}
}



void speichern(vector<Daten>& dataArray)
{
	ofstream myfile("Liste.txt", ios::app);
	//myfile.open("Liste.txt"); //verursacht, dass alte daten wieder überschrieben werden
	string text;

	if (myfile.is_open())
	{
		sortierVektor(dataArray);
		//// Einfügen des Benutzernamen und des Highscores ////
		for (int i = 0; i < dataArray.size(); i++)
		{
			myfile << dataArray[i].highscore;
			//myfile.width(1);
			myfile << " ";
			myfile << dataArray[i].username;
			myfile << endl;
		}
	}
	else
	{
		cout << "\n\n FEHLER BEIM OEFFNEN DER DATEI!";
	}
	myfile.close();
}



void SortAndPrintData()
{
	vector<Daten> dataArray;
	ifstream myfile;
	myfile.open("Liste.txt");
	string text;


	if (myfile.is_open())
	{
		while (getline(myfile, text))
		{
			if (text.length() != 0)
			{
				Daten hs;
				hs.highscore = stoi(text.substr(0, text.find(" ")));  //substr wird genutzt um nur bestimmte stellen eines strings zu kopieren
				hs.username = text.substr(text.find(" ") + 1);        //In deisem Fall sucht substr nach einem Leerzeichen und übernimmt die
				dataArray.push_back(hs);
			}                                                         //Stellen nach bzw vor dem Leerzeichen!                                    
		}
		//// SORTIEREN DER HIGHSCORES ////
		sortierVektor(dataArray);
		podium(dataArray);
	}
	else cout << "FEHLER BEIM OEFFNEN DER DATEI!" << endl;

	myfile.close();
}



void Anleitung()
{
	bool success = false;
	string anleitung;
	ofstream file("Anleitung.txt", ios::app);
	//file.open("Anleitung.txt");
	if (file.is_open())
	{
		if (anleitung.length() == 0)
		{
			ofstream file;
			file.open("Anleitung.txt");
			if (file.is_open())
			{
				file << endl;
				file << "Anleitung fuer Tetris:" << endl << endl;
				file << "1. Spielziel: " << endl;
				file << "- Ziel ist es, die herabfallenden Figuren so zu platzieren, " << endl;
				file << "  dass komplette waagerechte Reihen gebildet werden. Komplette Reihen verschwinden dann und bringen Punkte ein." << endl << endl;
				file << "2. Steuerung : " << endl;
				file << "- Bewege die Figuren nach links oder rechts mit den Pfeiltasten." << endl;
				file << "- Drehe die Figuren mit der Drehungstaste oder der Pfeiltaste nach oben." << endl;
				file << "- Beschleunige den Fall einer Figur mit der Pfeiltaste nach unten." << endl << endl;
				file << "3. Punkte : " << endl;
				file << "- Fuer jede abgeschlossene Reihe erhaeltst du Punkte." << endl;
				file << "- 1 platzierter Block bringt 8 Punkte." << endl;
				file << "- 1 abgeschlossene Reihe bringt 40 Punkte." << endl;
				file << "- 2 abgeschlossene Reihen bringen 100 Punkte." << endl;
				file << "- 3 abgeschlossene reihen bringen 300 Punkte." << endl;
				file << "- 4 abgeschlossene Reihen bringen 1200 Punkte." << endl;
				file << "- Deine Punkte werden spaeter in der Highscoreliste gezeigt. Schaffst du es in die Top 3 zu kommen?" << endl;
				file << "  TIPP: Schau dir die Highscoreliste im Vollbildmodus an!" << endl << endl;
				file << "4. Spielende : " << endl;
				file << "- Wenn die Figuren bis zum oberen Rand des Spielfelds stapeln, endet das Spiel." << endl << endl;
				file << "Viel Spass beim Spielen!" << endl;
				file.close();
				success = true;
			}
			else cout << "FEHLER BEIM OEFFNEN DER ANLEITUNG!" << endl;
		}
	}
	if (success = true || anleitung.length() != 0)
	{
		ifstream file;
		file.open("Anleitung.txt");
		if (file.is_open())
		{
			while (getline(file, anleitung))
			{
				cout << anleitung << endl;
			}
			file.close();
		}
		else cout << "FEHLER BEIM OEFFNEN DER ANLEITUNG! " << endl;
	}
	color(4);
	//Zurück zum Stratmenu
	cout << endl << "Press Escape to go back to Menu";
	int keyA = 0;
	while (keyA != 27)
	{
		keyA = _getch();
	}
}


void highscore(int& score, string& username, vector<Daten> &dataArray)
{
	Daten zwischenspeicher;

		zwischenspeicher.highscore = score;
		zwischenspeicher.username = username;
		dataArray.push_back(zwischenspeicher);

		speichern(dataArray);
		SortAndPrintData();

}