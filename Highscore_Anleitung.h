#pragma once
/*
	Funktionsbibliothek f�r Highscoreliste und Anleitung
	- Ausgabe des Podiums mit der Bestenliste
	- Ausgabe der Anleitung
	- Sortieren und Einlesen der Benutzernamen und Punkte
	Autor: Oliver Martens & Tom Strassburg
	Letzte �nderung: 09.01.2023
*/
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Daten
{
	int highscore = -1;
	string username;
};

/// <summary>
/// Ausgeben des Podiums mit Platz 1-3
/// </summary>
/// <param name="dataArray"> �bergabe des Datenarrays c.b.r. </param>
void podium(vector<Daten>& dataArray);

/// <summary>
/// Sortieren der Benutzer nach dem Highscore
/// </summary>
/// <param name="dataArray">�bergabe des Datenarrays c.b.r.</param>
void sortierVektor(vector<Daten>& dataArray);

/// <summary>
/// Sortieren und Ausgeben des Highscore-Liste
/// </summary>
void SortAndPrintData();

/// <summary>
/// Logo f�r die Anleitung
/// </summary>
void logoManual();

/// <summary>
/// Ausgabe und schreiben der Anleitung
/// </summary>
void Anleitung();

/// <summary>
///	Einf�gen & Speichern des Benutzernamens und des Punktestands
/// </summary>
/// <param name="points"> �bergabe des Punktestands </param>
/// <param name="username"> �bergabe des Nutzernamens </param>
/// <param name="dataArray"> �bergabe des Datenarrays c.b.r. </param>
void speichernNew(int& points, string& username, vector<Daten>& dataArray);