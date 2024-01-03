#pragma once
#include <string>

using namespace std;


/// <summary>
/// Game Over Logo bunt
/// </summary>
void logoGameOver();

/// <summary>
/// Bewegender Totenschädel
/// </summary>
void movingSkull();

/// <summary>
/// Ausgabe des Totenkopfs und einer Box für die Eingabe
/// </summary>
void inputBox();

/// <summary>
/// Eingabe Benutzername
/// </summary>
/// <param name="score"> Übergabe des Scores </param>
/// <returns> Rückgabe des eingegeben Nutzernamen</returns>
string typeUsername(int score);


/// <summary>
/// Aufruf des Game Over Screens
/// </summary>
/// <param name="score">Übergabe des Scores</param>
/// <param name="username">Übergabe des Nutzernamens</param>
void gameOver(int score, string username);