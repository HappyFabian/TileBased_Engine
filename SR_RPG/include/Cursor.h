#ifndef CURSOR_H
#define CURSOR_H

#include "Map.h"


class Cursor
{
    public:

        Map *m;
        Area activeArea;
        int IMX;
        int IMY;
        int IWX;
        int IWY;

        Cursor();
        virtual ~Cursor();
        void setActiveArea(Area activeArea);
        void setMap(Map *m);
        void setCharacter(int x, int y);
        void setIM(int x, int y);
        void cleanIW();
        bool moveCursor(int vx, int vy);
    protected:
    private:
};

#endif // CURSOR_H
