#pragma once
/// <summary>
/// Diese Funktion sorgt daf�r, dass der Cursor ausgeblendet wird
/// </summary>
void noCursor();

/// <summary>
/// Cursor an Position (X/Y) setzen
/// </summary>
/// <param name="a"> X-Koordinate </param>
/// <param name="b"> Y-Koordinate </param>
void go(int a, int b);

/// <summary>
/// Ver�ndern der Text- oder Hintergrundfarbe
/// </summary>
/// <param name="y"> Farbcode </param>
void color(int y);

/// <summary>
/// Einfaches Quadrat aus char(219)
/// </summary>
/// <param name="X"> X-Koordinate f�r go </param>
/// <param name="Y"> Y-Koordinate f�r go </param>
/// <param name="width"> Breite </param>
/// <param name="height"> H�he </param>
/// <param name="paint"> Farbe des Quadrats</param>
void simple_square(int X, int Y, int width, int height, int paint);

/// <summary>
/// Einfaches U bzw. Spielfeld aus char(219)
/// </summary>
/// <param name="X"> X-Koordinate f�r go </param>
/// <param name="Y"> Y-Koordinate f�r go </param>
/// <param name="width"> Breite </param>
/// <param name="height"> H�he </param>
/// <param name="paint"> Farbe des Quadrats</param>
void simple_U(int X, int Y, int width, int height, int paint);

/// <summary>
/// Einblenden des Highscore-Fensters
/// </summary>
void highscoreGUI();

/// <summary>
/// Einblenden des Next-Block-Fensters 
/// </summary>
void nextBlockGUI();

/// <summary>
/// Einblenden des Controls-Fensters
/// </summary>
void controlsGUI();

/// <summary>
/// Anzeige des n�chsten erscheinenden Blocks
/// </summary>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="nextBlock"> n�chster Block </param>
void showNextBlock(int nextBlock, tetris& tempBlock);

/// <summary>
/// Anzeige der aktuellen Punkte
/// </summary>
/// <param name="points"> �bergabe der Punkte </param>
/// <param name="tempBlock">�bergabe des structs mit c.b.r.</param>
/// <param name="numBlocks"> numBlocks entspricht der Anzahl an Plaziertes Bl�cken </param>
void showPoints(int points, tetris& tempBlock, int numBlocks);