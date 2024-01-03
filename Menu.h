#pragma once
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
/// <param name="count"></param>
void Menu(int count);

