#pragma once


/// <summary>
/// Diese Funktion sorgt dafür, dass der Cursor ausgeblendet wird
/// </summary>
void noCursor();

/// <summary>
/// Cursor an Position (X/Y) setzen
/// </summary>
/// <param name="a"> X-Koordinate </param>
/// <param name="b"> Y-Koordinate </param>
void go(int a, int b);

/// <summary>
/// Verändern der Text- oder Hintergrundfarbe
/// </summary>
/// <param name="y"> Farbcode </param>
void color(int y);

//Funktion definieren
void simple_square(int X, int Y, int width, int height);
void U_square(int X, int Y, int width, int height);
