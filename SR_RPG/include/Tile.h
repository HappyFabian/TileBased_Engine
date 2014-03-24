#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sstream>

class Tile
{
    public:

        char thisTile;
        char getTile();
        void setTile(char tiletype);

        Tile();
        virtual ~Tile();
    protected:
    private:
};

#endif // TILE_H
