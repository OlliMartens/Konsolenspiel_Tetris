#pragma once
/*
	Funktionsbibliothek für das Menu
	- Ausgabe des Tetris-Schriftzugs
	- Auswählen der Menupunkte -> New Game, Highscore, ...
	Autor: Oliver Martens & Tom Strassburg
	Letzte Änderung: 09.01.2023
*/
#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Blöcke neben dem Auswahlmenu einfügen
/// </summary>
/// <param name="count"> Menupunkt </param>
void blocksMenu(int count);

/// <summary>
/// Ausgabe der Auswahlbox
/// </summary>
/// <param name="a"> Position x der Box</param>
/// <param name="b"> Position y der Box</param>
/// <param name="colorIn"> Einfärben der Box</param>
/// <param name="text"> Text in der Box </param>
void auswahlbox(int a, int b, int colorIn, string text);

/// <summary>
/// Ausgabe Tetris Logo
/// </summary>
void logoTetris();

/// <summary>
/// Ausgabe der Controls
/// </summary>
void controls();

/// <summary>
/// Menusteuerung
/// </summary>
/// <returns> Status Count </returns>
int Menu();

