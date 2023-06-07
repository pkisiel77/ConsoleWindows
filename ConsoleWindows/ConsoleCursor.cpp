



class ConsoleCursor {



    ConsoleCursor() = default;

    bool operator==(const ConsoleCursor& other) const
    {
        return false;
    }
};

class CursorAction {
public:
    void cur_up(CursorPosition &cp) {
        gotxy(cp.x.cp.y);
        gotoxy(cp.x, cp.y);

    }

    void cur_down() {

    }

    void cur_left() {

    }

    void cur_right() {

    }

    CursorAction() = default;

    bool operator==(const CursorAction& other) const
    {
        return false;
    }
};