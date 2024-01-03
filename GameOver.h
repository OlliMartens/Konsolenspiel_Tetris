#pragma once
#include <string>

using namespace std;


/// <summary>
/// Game Over Logo bunt
/// </summary>
void logoGameOver();

/// <summary>
/// Bewegender Totensch�del
/// </summary>
void movingSkull();

/// <summary>
/// Ausgabe des Totenkopfs und einer Box f�r die Eingabe
/// </summary>
void inputBox();

/// <summary>
/// Eingabe Benutzername
/// </summary>
/// <param name="score"> �bergabe des Scores </param>
/// <returns> R�ckgabe des eingegeben Nutzernamen</returns>
string typeUsername(int score);


/// <summary>
/// Aufruf des Game Over Screens
/// </summary>
/// <param name="score">�bergabe des Scores</param>
/// <param name="username">�bergabe des Nutzernamens</param>
void gameOver(int score, string username);