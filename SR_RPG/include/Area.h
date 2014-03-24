#ifndef AREA_H
#define AREA_H

#include "Tile.h"

using namespace std;

// T - Floor
// # - Wall
// E - Exits
// S - Switchs
// V - Event Region
//

class Area
{
    public:

        Tile tiles[11][11];

        Area();
        virtual ~Area();

        void setTiles(string fileplace);
        void setTile(int x, int y, char Tile);
        char getTiles(int x, int y);

    protected:
    private:
};

#endif // AREA_H
