#ifndef MAP_H
#define MAP_H

#include "Area.h"

class Map
{
    public:

        int AX = 1;
        int AY = 1;
        Area area[3][3];
        Area activeArea;
        string areas[10];


        Map();
        virtual ~Map();
        void generateMap();
        Area getActiveArea();
        void setActiveArea(int x, int y);
        void refreshActiveArea();
        void addX();
        void addY();
        void substractX();
        void substractY();


    protected:
    private:
};

#endif // MAP_H
