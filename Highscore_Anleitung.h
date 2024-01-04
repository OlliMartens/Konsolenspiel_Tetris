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


void podium(vector<Daten>& dataArray);


void sortierVektor(vector<Daten>& dataArray);


void speichern(int points, string username, vector<Daten>& dataArray);


void SortAndPrintData(vector<Daten>& dataArray);


void Anleitung();


//void highscore(int& score, string& username, vector<Daten> &dataArray);