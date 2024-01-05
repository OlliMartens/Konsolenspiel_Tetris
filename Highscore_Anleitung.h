#pragma once
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
/// <param name="dataArray"> Übergabe des Datenarrays c.b.r. </param>
void podium(vector<Daten>& dataArray);

/// <summary>
/// Sortieren der Benutzer nach dem Highscore
/// </summary>
/// <param name="dataArray">Übergabe des Datenarrays c.b.r.</param>
void sortierVektor(vector<Daten>& dataArray);

/// <summary>
/// Sortieren und Ausgeben des Highscore-Liste
/// </summary>
void SortAndPrintData();

/// <summary>
/// Logo für die Anleitung
/// </summary>
void logoManual();

/// <summary>
/// Ausgabe und schreiben der Anleitung
/// </summary>
void Anleitung();

/// <summary>
///
/// </summary>
/// <param name="points"> Übergabe des Punktestands </param>
/// <param name="username"> Übergabe des Nutzernamens </param>
/// <param name="dataArray"> Übergabe des Datenarrays c.b.r. </param>
void speichernNew(int points, string username, vector<Daten>& dataArray);