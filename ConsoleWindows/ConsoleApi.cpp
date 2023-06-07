#include <iostream>
#include <windows.h>


struct CursorPosition {
    int x, y;

    CursorPosition(const int x, const int y)
        : x(x), y(y)
    {
    }

    CursorPosition() = default;

    bool operator==(const CursorPosition& other) const
    {
        return false;
    }
};


class ConsoleApi {
private:
    HANDLE hConsole;

public:
    HANDLE InitConsole() {
        try {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            return hConsole;
        }
        catch (...) {
            return nullptr;
        }
    }

    void CursorUp(CursorPosition& cp) {
        cleanLastPosition(cp);
        ++cp.y;
        gotoxy(cp);
        std::cout << "*";
    }

    void CursorDown(CursorPosition& cp) {
        cleanLastPosition(cp);
        --cp.y;
        gotoxy(cp);
        std::cout << "*";
    }

    void CursorLeft(CursorPosition& cp) {
        cleanLastPosition(cp);
        --cp.x;
        gotoxy(cp);
        std::cout << "*";
    }

    void CursorRight(CursorPosition& cp) {
        cleanLastPosition(cp);
        ++cp.x;
        gotoxy(cp);
        std::cout << "*";
    }

    auto CursorSetColor(const int color) const -> void
    {
        SetConsoleTextAttribute(hConsole, color);
    }

private:
    void cleanLastPosition(const CursorPosition& cp) const
    {
        gotoxy(cp);
        std::cout << " ";
    }

    void gotoxy(const CursorPosition& cp) const
    {
        COORD coordinate;
        coordinate.X = cp.x;
        coordinate.Y = cp.y;
        SetConsoleCursorPosition(hConsole, coordinate);
    }

public:
    ConsoleApi() = default;

    bool operator==(const ConsoleApi& other) const
    {
        return false;
    }

    ConsoleApi(const HANDLE& hConsole)
        : hConsole(hConsole)
    {
    }
};
