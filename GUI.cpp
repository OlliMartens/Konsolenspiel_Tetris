#include <iostream>  
#include <Windows.h>  

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void go(int a, int b) {
    COORD cord;
    cord.X = a;
    cord.Y = b;
    SetConsoleCursorPosition(out, cord);
}

void Color(int y) {
    SetConsoleTextAttribute(out, y);
}

 void simple_square(int X, int Y, int width, int height){
  for (int set1 = 0; set1<height; set1++)
  {
  go(X, Y); Y++;
  for (int set2 = 0; set2<width; set2++){ cout << char(219); }cout << endl;
  }
  }


 void U_square(int X, int Y, int width, int height)
 {
     for (int set1 = 0; set1 < height; set1++, Y++)
     {
         go(X, Y);
         Color(9);
         cout << char(219); 
         go(X + (width -1), Y); 
         Color(9);
         cout << char(219);
         go(X, Y);
         if (set1 == height -1) {
             for (int set2 = 0; set2 < width; set2++) {
                 Color(9);
                 cout << char(223);
                 continue;
             }
         }
         //Frabe auf den Ursprung zurücksetzen
         Color(7);
     }
 }



 