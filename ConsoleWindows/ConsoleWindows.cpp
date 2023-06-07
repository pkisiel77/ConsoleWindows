#include <conio.h>


#include "ConsoleApi.cpp"

int main()
{
    CursorPosition cp{ 10,10 };

    ConsoleApi consoleApi{};
    consoleApi.InitConsole();

    consoleApi.CursorSetColor(10);

    while (true) {
        if (_kbhit()) {
	        const char key = _getch();

            if (key == 'a') {
                consoleApi.CursorLeft(cp);
            }
            else if (key == 'd') {
                consoleApi.CursorRight(cp);
            }
            else if (key == 'w') {
                consoleApi.CursorUp(cp);
            }
            else if (key == 's') {
                consoleApi.CursorDown(cp);
            }
            else if (key == 27) {
                break;
            }
        }
    }

}


