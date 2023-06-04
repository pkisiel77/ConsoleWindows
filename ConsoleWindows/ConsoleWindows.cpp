#include <iostream>

#include <conio.h>
#include <windows.h>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
    COORD coordinate{x,y};
    SetConsoleCursorPosition(hConsole, coordinate);
}


void set_color(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void init_console();

void init_console() {

}

int main()
{
    int x = 10, y = 10;

    set_color(10);

    while (true) {
        if (_kbhit()) {
            char key = _getch();

            if (key == 'a') {
                gotoxy(x, y);
                std::cout << " ";
                gotoxy(--x, y);
                std::cout << "*";
            }
            else if (key == 'd') {
                gotoxy(x, y);
                std::cout << " ";
                gotoxy(++x, y);
                std::cout << "*";
            }
            else if (key == 'w') {
                gotoxy(x, y);
                std::cout << " ";
                gotoxy(x, --y);
                std::cout << "*";
            }
            else if (key == 's') {
                gotoxy(x, y);
                std::cout << " ";
                gotoxy(x, ++y);
                std::cout << "*";
            }
            else if (key == 27) {
                break;
            }
        }
    }

}

