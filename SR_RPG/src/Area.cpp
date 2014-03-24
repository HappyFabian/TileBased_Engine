#include "Area.h"

Area::Area()
{

}

Area::~Area()
{

}

char Area::getTiles(int x, int y)
{
    return tiles[y][x].getTile();
}

void Area::setTiles(string fileplace)
{
    ifstream in;
    in.open(fileplace.c_str());

    for(int y = 0; y < 11; y++)
    {
        for(int x = 0; x < 11; x++)
        {
            char temp;
            in >> temp;
            tiles[y][x].setTile(temp);
            cout << temp;
        }
        cout << endl;
    }
    in.close();

}

void Area::setTile(int x, int y, char tile)
{
    tiles[y][x].setTile(tile);
}
