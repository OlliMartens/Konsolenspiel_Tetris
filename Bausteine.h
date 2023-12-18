#pragma once


/// <summary>
/// Zuf�llige Auswahl welche Form gerade auf dem Spielfeld erscheint 
/// </summary>
/// <param name="arrayForm">�bergabe des Spielfeld-Arrays</param>
/// <param name="status">Status gibt Information dar�ber, welche Form gerade ausgew�hlt wurde</param>
void randomForm(char arrayForm[25][18], int status);

/// <summary>
/// Funktion f�r die Wiedergabe eines Vierecks
/// </summary>
/// <param name="arrayForm">�bergabe des Spielfeld-Arrays</param>
/// <param name="position"></param>
/// <returns> R�ckgabe des Status 1 = Viereck </returns>
int viereck(char arrayForm[25][18], int a , int b, int c, int d, int e, int f, int positionX);

/// <summary>/// /// </summary>/// <param name="status"></param>/// <param name="cols"></param>/// <param name="rows"></param>
void formenRotieren(int& a, int& b, int& c, int& d, int& e, int& f);