#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "GUI.h"

using namespace std;

void blocksMenu(int count) {

    switch (count)
    {
    case 0:
        //letzten Block löschen 
        for (int i = 7; i < 22; i++)
        {
            for (int j = 0; j < 20; j++) {
                go(j, i);
                cout << " ";
            }
        }
        //Ausgabe des Blockes neben dem Menufeld
        color(3);
        go(44, 7);
        cout << "  " << char(219) << char(219);
        go(44, 8);
        cout << char(219) << char(219) << char(219) << char(219);
        go(44, 9);
        cout << "  " << char(219) << char(219);
        color(0x0f);
        break;
    case 1:
        //letzten Block löschen 
        for (int i = 7; i < 22; i++)
        {
            for (int j = 43; j < 50; j++) {
                go(j, i);
                cout << " ";
            }
        }
        //Ausgabe des Blockes neben dem Menufeld
        color(2);
        go(12, 11);
        cout << char(219) << char(219);
        go(12, 12);
        cout << char(219) << char(219) << char(219) << char(219);
        go(12, 13);
        cout << "  " << char(219) << char(219);
        color(0x0f);

        break;
    case 2:
        //letzten Block löschen 
        for (int i = 7; i < 22; i++)
        {
            for (int j = 0; j < 20; j++) {
                go(j, i);
                cout << " ";
            }
        }
        //Ausgabe des Blockes neben dem Menufeld
        color(6);
        go(44, 15);
        cout << char(219) << char(219) << char(219) << char(219);
        go(44, 16);
        cout << char(219) << char(219);
        go(44, 17);
        cout << char(219) << char(219);
        break;
    case 3:
        //letzten Block löschen 
        for (int i = 7; i < 22; i++)
        {
            for (int j = 43; j < 50; j++) {
                go(j, i);
                cout << " ";
            }
        }
        //Ausgabe des Blockes neben dem Menufeld
        color(4);
        go(12, 20);
        cout << char(219) << char(219) << char(219) << char(219);
        go(12, 21);
        cout << char(219) << char(219) << char(219) << char(219);
        color(0x0f);
        break;

    default:
        break;
    }

}

void auswahlbox(int a, int b, int colorIn, string text) {
    color(0x0f);
    go(a, b);
    cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
        << char(196) << char(196) << char(196) << char(196) << char(191);
    color(colorIn);
    go(a, (b + 1));
    color(0x0f);
    cout << char(179);
    color(colorIn);
    cout << "     " << text << "     ";
    color(0x0f);
    cout << char(179);
    color(0x0f);
    go(a, (b + 2));
    cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
        << char(196) << char(196) << char(196) << char(196) << char(217);
}

void logoTetris() {       //Tetris Logo
    for (int i = 1; i < 47; i++)
    {
        color(1);
        if (i == 1) {
            cout << "\t ";
        }
        else if (i != 1 && i != 10 && i != 18 && i != 27 && i != 34 && i != 35 && i != 38 && i != 46)
            cout << char(219);
        else if (i == 35)
            cout << " ";
        else
            cout << char(187);
    }
    color(5);
    cout << endl << "\t " << char(200) << char(205) << char(205) << char(219) << char(219) << char(201) << char(205) << char(205) << char(188)
        << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205)
        << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << char(219) << char(219) << char(201) << char(205) << char(205)
        << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205)
        << char(205) << char(205) << char(188) << endl;
    color(4);
    cout << "\t    " << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << "     "
        << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188)
        << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << endl;
    color(2);
    cout << "\t    " << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << "     "
        << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187)
        << char(219) << char(219) << char(186) << char(200) << char(205) << char(205) << char(205) << char(205) << char(219) << char(219) << char(186) << endl;
    color(6);
    cout << "\t    " << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << "   "
        << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(186)
        << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
    color(3);
    cout << "\t    " << char(200) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "   "
        << char(200) << char(205) << char(188) << "   " << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188) << char(200) << char(205) << char(188)
        << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
    color(0x0f);
}

void controls() {

    color(1);
    go(65, 8);
    cout << "Controls:";
    for (int i = 0; i < 25; i++)
    {
        color(3);
        go(65 + i, 9);
        cout << char(223);
    }

    //Enter
    color(0x0f);
    go(65, 10);
    cout << "              " << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
    go(65, 11);
    cout << "Selection ->  " << char(179) << "enter" << char(179);
    go(65, 12);
    cout << "              " << char(192) << char(196) << char(191) << "   " << char(179);
    go(65, 13);
    cout << "                " << char(179) << "   " << char(179);
    go(65, 14);
    cout << "                " << char(192) << char(196) << char(196) << char(196) << char(217);
    //Pfeiltasten
    go(65, 16);
    cout << "              " << char(218) << char(196) << char(196) << char(196) << char(196) << char(191) << " " << char(218) << char(196) << char(196) << char(196) << char(196) << char(191);
    go(65, 17);
    wcout << "Up & Down ->  " << char(179) << " /" << char(92) << " " << char(179) << " " << char(179) << " " << char(92) << "/ " << char(179);
    go(65, 18);
    cout << "              " << char(192) << char(196) << char(196) << char(196) << char(196) << char(217) << " " << char(192) << char(196) << char(196) << char(196) << char(196) << char(217);

}

void Menu(int count) {
    //Variablen (initialisiert mit der gewünschten Farbe)
    int AW1 = 20, AW2 = 7, AW3 = 7, AW4 = 7;


    //Ausgabe des Tetris Logos
    logoTetris();

    while (true)
    {
        noCursor();

        auswahlbox(21, 7, AW1, "New Game ");
        auswahlbox(21, 11, AW2, "Highscore");
        auswahlbox(21, 15, AW3, "   Help  ");
        auswahlbox(21, 19, AW4, "   Exit  ");
        blocksMenu(count);
        controls();

        //einlesen der aktuell gedrückten Taste
        int key = _getch();

        //////////////////////////////////////////////////////////////////////////////
        if (key == 80 && count < 3) count++;
        else if (key == 72 && count > 0) count--;

        switch (count)
        {
        case 0:
            AW1 = 20;
            AW2 = 0x0f;
            AW3 = 0x0f;
            AW4 = 0x0f;
            break;
        case 1:
            AW1 = 0x0f;
            AW2 = 20;
            AW3 = 0x0f;
            AW4 = 0x0f;
            break;
        case 2:
            AW1 = 0x0f;
            AW2 = 0x0f;
            AW3 = 20;
            AW4 = 0x0f;
            break;
        case 3:
            AW1 = 0x0f;
            AW2 = 0x0f;
            AW3 = 0x0f;
            AW4 = 20;
            break;
        default:
            AW1 = 0x0f;
            AW2 = 0x0f;
            AW3 = 0x0f;
            break;
        }

        Sleep(50);
    }
}