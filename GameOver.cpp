#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>
#include "GUI.h"

using namespace std;

void logoGameOver() {
    cout << "\n\n\n\n\n";
    for (int i = 0; i < 73; i++)
    {
        if (i == 0) {
            cout << "\t";
        }
        if (i == 0 || i == 8 || i == 9 || i == 16 || (i >= 21 && i <= 23) || (i >= 36 && i <= 40) || i == 48 || (i >= 52 && i <= 54)) {
            color(5);
            cout << " ";
        }
        else if (i == 7 || i == 15 || i == 20 || i == 27 || i == 35 || i == 47 || i == 51 || i == 57 || i == 65 || i == 72) {
            color(5);
            cout << char(187);
        }
        else {
            color(4);
            cout << char(219);
        }
    }
    color(4);
    cout << "\n\t" << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << " ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(187);
    color(4);
    cout << char(219) << char(219) << char(219) << char(219);
    color(5);
    cout << char(187) << " ";
    color(4);
    cout << char(219) << char(219) << char(219) << char(219);
    color(5);
    cout << char(186);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << "    ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(205);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(187);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186) << "   ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(188);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(187) << endl;

    for (int i = 0; i < 74; i++) {
        if (i == 0) {
            cout << "\t";
        }
        if (i == 2 || i == 16 || i == 27 || i == 42 || i == 48 || i == 51 || i == 57) {
            color(5);
            cout << char(186);
        }
        else if (i == 3 || i == 4 || (i >= 34 && i <= 39) || (i >= 43 && i <= 45) || (i >= 52 && i <= 54) || i == 64 || i == 65) {
            color(5);
            cout << " ";
        }
        else if (i == 8 || i == 33 || i == 63) {
            color(5);
            cout << char(187);
        }
        else if (i == 19 || i == 24 || i == 72) {
            color(5);
            cout << char(201);
        }
        else if (i == 73) {
            color(5);
            cout << char(188);
        }
        else {
            color(4);
            cout << char(219);
        }
    }
    color(4);
    cout << "\n\t" << char(219) << char(219);
    color(5);
    cout << char(186) << "   ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186) << char(200);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(188);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(188) << "      ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186) << "   ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(186) << char(200);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(187) << " ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(188);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205) << char(188) << "  ";
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(201) << char(205) << char(205);
    color(4);
    cout << char(219) << char(219);
    color(5);
    cout << char(187) << endl;

    for (int i = 0; i < 74; i++) {
        if (i == 0) {
            cout << "\t";
        }
        if (i == 0 || i == 21 || i == 40 || i == 50) {
            color(5);
            cout << char(200);
        }
        else if (i == 12 || i == 13 || i == 20 || i == 24 || (i >= 36 && i <= 39) || i == 49 || i == 57 || i == 69 || i == 70) {
            color(5);
            cout << " ";
        }
        else if (i == 11 || i == 16 || i == 19 || i == 27 || i == 68 || i == 73) {
            color(5);
            cout << char(186);
        }
        else if (i == 7 || i == 47 || i == 55) {
            color(5);
            cout << char(201);
        }
        else if (i == 8 || i == 23 || i == 48 || i == 56) {
            color(5);
            cout << char(188);
        }
        else if (i == 22) {
            color(5);
            cout << char(205);
        }
        else if (i == 35 || i == 65) {
            color(5);
            cout << char(187);
        }
        else {
            color(4);
            cout << char(219);
        }
    }
    color(5);
    cout << "\n\t " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188)
        << char(200) << char(205) << char(188) << "     " << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)
        << "     " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(205) << char(188) << "  "
        << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188) << endl;
    color(0x0f);
}

void movingSkull() {
    static int count = 0;
    static int posX = 0;
    static int num = 0;
    //Zurücksetzen der Variablen
    count = 0; posX = 0; num = 0;
    while (true) {

        if (num == 3)break;
        if (count > 53) {
            count = 0;
            posX = 0;
        }
        if (count == 0)num++;
        if (count <= 23) {
            posX++;
            if (count > 3) {
                for (int i = 0; i < 7; i++)
                {
                    go(28 + posX, 20 + i);
                    cout << " ";
                }

            }
        }

        else if (count > 22 && count <= 46) {
            posX--;
            if (count > 25) {
                for (int i = 0; i < 7; i++)
                {
                    go(28 + posX, 20 + i);
                    cout << " ";
                }

            }
        }

        go(28 + posX, 20);
        color(1);
        cout << "   _____ ";
        go(28 + posX, 21);
        cout << "  /     " << char(92) << " ";
        go(28 + posX, 22);
        cout << " /       " << char(92) << " ";
        go(28 + posX, 23);
        cout << " | () () | ";
        go(28 + posX, 24);
        cout << "  " << char(92) << "  ^  /  ";
        go(28 + posX, 25);
        cout << "   |||||  ";
        go(28 + posX, 26);
        cout << "   |||||  ";
        count++;
        Sleep(15);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 30; j++)
        {
            go(26 + j, 20 + i);
            cout << " ";
        }
    }
}

void inputBox() {

    go(26, 14);
    color(6);
    cout << "Type in your username (max. 10 letters):" << endl;
    go(36, 15);
    cout << "Select with Enter!";
    go(34, 17);
    color(5);
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
    go(34, 18);
    cout << char(186) << "                    " << char(186);
    go(34, 19);
    cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);

    movingSkull();
}

string typeUsername(int score) {

    string username;
    char ch;

    inputBox();

    color(6);
    go(35, 21);
    cout << "Your score is: " << score << endl;

    char var[10];
    bool valid = false;

    //Input Buffer Löschen um unnötige Eingabe während des Spiels nicht angezeigt zu bekommen
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

    color(1);
    go(35, 18);

    while (true) {


        if (username.size() > 10) break;

        //ch = cin.get();
        ch = _getch();
        // Überprüfen, ob Enter-Taste (ch = 10) gedrückt wurde
        if (ch == '\r' && !username.empty()) {
            break;
        }   //Wenn als erstes Enter und der string noch leer ist lese weiter ein
        else if (ch == '\r') {
            go(35, 18);
            ch = _getch();
        }


        // Überprüfen, ob Backspace-Taste(ch = 8) gedrückt wurde
        if (ch == '\b') {
            if (!username.empty()) {
                // Lösche das letzte Zeichen aus der Eingabe
                username.pop_back();
                cout << "\b \b";
                cout.flush();  // Erzwingt die Ausgabe sofort
            }
        }
        else {
            // Füge das eingegebene Zeichen zur Eingabe hinzu
            username += ch;
            cout << ch;
        }


    }

    color(0x0f);
    return username;
}

void gameOver(int& score, string& username){
    noCursor();
    logoGameOver();
    username = typeUsername(score);
}
