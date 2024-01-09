/*
    Grafische Elemente einbelenden
    Autor: Oliver Martens & Tom Strassburg
    Letzte Änderung: 09.01.2023
*/
#include <iostream>  
#include <Windows.h>  
#include "functions.h"

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void go(int a, int b) { //Cursor an eine bestimmte Position 
    COORD cord;
    cord.X = a;
    cord.Y = b;
    SetConsoleCursorPosition(out, cord);
}

void color(int y) { //Farbe der Schrift/Hintergrund ändern 
    SetConsoleTextAttribute(out, y);
}

void noCursor() // Cursor ausblenden
{
    CONSOLE_CURSOR_INFO info;
    HANDLE  out;

    info.bVisible = 0;
    info.dwSize = 1;

    out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(out, &info);
}

 void simple_square(int X, int Y, int width, int height, int paint){
     for (int set1 = 0; set1 < height; set1++, Y++)
     {
         go(X, Y);
         if (set1 == 0) {
             for (int i = 0; i < width; i++)
             {
                 color(paint);
                 cout << char(223);
                 continue;
             }
         }
         go(X, Y);
         color(paint);
         cout << char(219);
         go(X + (width - 1), Y);
         color(paint);
         cout << char(219);
         go(X, Y);
         if (set1 == height - 1) {
             for (int set2 = 0; set2 < width; set2++) {
                 color(paint);
                 cout << char(223);
                 continue;
             }
         }
         //Frabe auf den Ursprung zurücksetzen
         color(7);
     }
  }

 void simple_U(int X, int Y, int width, int height, int paint)
 {
     for (int set1 = 0; set1 < height; set1++, Y++)
     {
         go(X, Y);
         color(paint);
         cout << char(219); 
         go(X + (width -1), Y); 
         color(paint);
         cout << char(219);
         go(X, Y);
         if (set1 == height -1) {
             for (int set2 = 0; set2 < width; set2++) {
                 color(paint);
                 cout << char(219);
                 continue;
             }
         }
         //Frabe auf den Ursprung zurücksetzen
         color(7);
     }
 }

 void highscoreGUI() {
     //Dein Highscore (4 = rot)
     color(0x0c);
     go(61, 13);
     cout << "Highscore" << endl;
     simple_square(61, 14, 20, 8, 4);
 }

 void nextBlockGUI() {
     //Nächster Block (6 = gelb)
     color(0x0e);
     go(61, 4);
     cout << "Next Block" << endl;
     simple_square(61, 5, 20, 8, 6);
 }

 void controlsGUI() {
     //Controls (5 = violett)
     color(0x0d);
     go(1, 4);
     cout << "Controls" << endl;
     simple_square(1, 5, 25, 17, 5);

     //Pfeile rechts und links
     go(3, 6);
     cout << "Move left & right: " << endl;
     go(3, 7);
     cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(191) << " " << char(218) << char(196) << char(196) << char(196) << char(196) << char(191);
     go(3, 8);
     cout << char(179) << " <- " << char(179) << " " << char(179) << " -> " << char(179);
     go(3, 9);
     cout  << char(192) << char(196) << char(196) << char(196) << char(196) << char(217) << " " << char(192) << char(196) << char(196) << char(196) << char(196) << char(217);

     //Schnell nach unten
     go(3, 10);
     cout << "Move down faster: " << endl;
     go(3, 11);
     cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(191);
     go(3, 12);
     cout << char(179) << " " << char(92) << "/ " << char(179);
     go(3, 13);
     cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(217);

     //Bauteil drehen
     go(3, 14);
     cout << "Rotate component: " << endl;
     go(3, 15);
     cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(191);
     go(3, 16);
     cout << char(179) << " R  " << char(179);
     go(3, 17);
     cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(217);
 }

 void showNextBlock(int nextBlock, tetris& tempBlock) {

     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             go(i + 70, j + 7);
             if (tempBlock.blocks[nextBlock][i][j] == 0)
             {
                 //löschen der Char des alten Blocks
                 cout << " ";
                 continue;
             }
             else {
                 color(tempBlock.blocks[nextBlock][i][j]);
                 cout << char(178);
             }
         }
         cout << endl;
     }
 }

 void showPoints(int points, tetris& tempBlock, int numBlocks) {
     color(1);
     go(65, 15);
     cout << "Your current";
     go(65, 16);
     cout << " Highscore: ";
     go(70, 17);
     cout << points;
     color(0x0d);
     go(64, 18);
     cout << "Placed Blocks:";
     go(70, 19);
     cout << numBlocks;
     color(0x0f);
 }

 void blockFormIntro() {    //Außenumrandung des Blocks
     for (int i = 0; i < 91; i++)
     {
         go(20 + i, 5);
         cout << char(219);
     }
     for (int i = 0; i < 10; i++)
     {
         go(20, 5 + i);
         cout << char(219);
         go(111, 5 + i);
         cout << char(219);
     }
     for (int i = 0; i < 31; i++)
     {
         go(20 + i, 15);
         cout << char(219);
         go(81 + i, 15);
         cout << char(219);
     }
     for (int i = 0; i < 10; i++)
     {
         go(50, 15 + i);
         cout << char(219);
         go(81, 15 + i);
         cout << char(219);
     }
     for (int i = 0; i < 32; i++)
     {
         go(50 + i, 25);
         cout << char(219);
     }
 }


void intro() { // Ablauf Intro
     Sleep(1000);
     color(9);
     blockFormIntro();
     //Füllen des Blocks
     for (int i = 0; i < 30; i++) {
         for (int j = 0; j < 9; j++) {
             color(4);
             go(21 + i, 6 + j);
             cout << char(219);
             color(2);
             go(110 - i, 6 + j);
             cout << char(219);
             Sleep(15);
         }
     }
     Sleep(200);
     for (int i = 0; i < 30; i++) {
         for (int j = 0; j < 9; j++) {
             color(6);
             go(51 + i, 6 + j);
             cout << char(219);
             color(2);
             Sleep(10);
         }
     }
     Sleep(200);
     for (int i = 0; i < 30; i++) {
         for (int j = 0; j < 10; j++) {
             color(5);
             go(51 + i, 15 + j);
             cout << char(219);
             color(2);
             Sleep(2);
         }
     }
     //Blinken des Blocks
     for (int i = 0; i < 8; i++)
     {
         if (i == 0 || i == 2 || i == 4 || i == 6) {
             color(15);
             blockFormIntro();
         }
         if (i == 1 || i == 3 || i == 5 || i == 7) {
             color(9);
             blockFormIntro();
         }
         Sleep(200);
     }
     Sleep(2000);
     color(0x0f);
     go(1, 40);

 }

 //Quellen:
 // https://mycodecollection.blogspot.com/2015/01/c-console-basic-graphic-techniques.html
 // https://mycodecollection.blogspot.com/2014/12/console-fun-colors.html
 // ASCII-Tabelle erweitert
 // https://theasciicode.com.ar/extended-ascii-code/black-square-ascii-code-254.html
 // https://gist.github.com/eazybit/20dac48b2cd83c960afe
 // https://stackoverflow.com/questions/8468514/getasynckeystate-creating-problems-with-cin
 // https://patorjk.com/software/taag/#p=display&h=0&v=0&f=ANSI%20Shadow&t=game%20over%0A
 // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
 // https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes


 