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


void SortAndPrintData();


void logoManual();


void Anleitung();


void speichernNew(int& points, string& username, vector<Daten> dataArray);