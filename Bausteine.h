#pragma once


/// <summary>
/// Zufällige Auswahl welche Form gerade auf dem Spielfeld erscheint 
/// </summary>
/// <param name="arrayForm">Übergabe des Spielfeld-Arrays</param>
/// <param name="status">Status gibt Information darüber, welche Form gerade ausgewählt wurde</param>
void randomForm(char arrayForm[25][18], int status);

/// <summary>
/// Funktion für die Wiedergabe eines Vierecks
/// </summary>
/// <param name="arrayForm">Übergabe des Spielfeld-Arrays</param>
/// <param name="position"></param>
/// <returns> Rückgabe des Status 1 = Viereck </returns>
int viereck(char arrayForm[25][18], int a , int b, int c, int d, int e, int f, int positionX);

/// <summary>/// /// </summary>/// <param name="status"></param>/// <param name="cols"></param>/// <param name="rows"></param>
void formenRotieren(int& a, int& b, int& c, int& d, int& e, int& f);