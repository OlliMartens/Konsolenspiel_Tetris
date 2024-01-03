#include <iostream>  
#include <Windows.h>  
#include "Bausteine.h"

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void go(int a, int b) { //Cursor an eine bestimmte Position 
    COORD cord;
    cord.X = a;
    cord.Y = b;
    SetConsoleCursorPosition(out, cord);
}

void color(int y) { //Farbe der Schrift/Hintergrund �ndern 
    SetConsoleTextAttribute(out, y);
}

void noCursor()
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
         //Frabe auf den Ursprung zur�cksetzen
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
         //Frabe auf den Ursprung zur�cksetzen
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
     //N�chster Block (6 = gelb)
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
             color(0x0f);
             go(i + 70, j + 7);
             if (tempBlock.blocks[nextBlock][i][j] == 1) {
                 cout << char(178);
             }
             else {
                 //l�schen der Char
                 cout << " ";
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

 //Quellen:
 // https://mycodecollection.blogspot.com/2015/01/c-console-basic-graphic-techniques.html
 // https://mycodecollection.blogspot.com/2014/12/console-fun-colors.html
 // ASCII-Tabelle erweitert
 // https://theasciicode.com.ar/extended-ascii-code/black-square-ascii-code-254.html
 //https://gist.github.com/eazybit/20dac48b2cd83c960afe


 