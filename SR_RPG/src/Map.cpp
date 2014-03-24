#include "Map.h"

Map::Map()
{
    areas[0] = "area_closed.txt" ;
    areas[1] = "area_c.txt";
    areas[2] = "area_r.txt";
    areas[3] = "area_ur.txt";
    areas[4] = "area_u.txt";
    areas[5] = "area_ul.txt";
    areas[6] = "area_l.txt";
    areas[7] = "area_dl.txt";
    areas[8] = "area_d.txt";
    areas[9] = "area_dr.txt";

}

Map::~Map()
{
    //dtor
}

void Map::generateMap()
{
    for(int y = 0; y < 3; y++)
    {
        for(int x = 0; x <3; x++)
        {
            if(x == 0 && y == 0)
            {
               area[y][x].setTiles(areas[5]);
            }
            if(x == 1 && y == 0)
            {
               area[y][x].setTiles(areas[4]);
            }
            if(x == 2 && y == 0)
            {
               area[y][x].setTiles(areas[3]);
            }
            if(x == 0 && y == 1)
            {
               area[y][x].setTiles(areas[6]);
            }
            if(x == 1 && y == 1)
            {
               area[y][x].setTiles(areas[1]);
            }
            if(x == 2 && y == 1)
            {
               area[y][x].setTiles(areas[2]);
            }
            if(x == 0 && y == 2)
            {
               area[y][x].setTiles(areas[7]);
            }
            if(x == 1 && y == 2)
            {
               area[y][x].setTiles(areas[8]);
            }
            if(x == 2 && y == 2)
            {
               area[y][x].setTiles(areas[9]);
            }

            cout << y << x << endl;
        }
    }
    setActiveArea(AX,AY);
}

Area Map::getActiveArea()
{
    return activeArea;
}

void Map::setActiveArea(int x, int y)
{
    activeArea = area[y][x];
}

void Map::addX()
{
    if(AX<2)
    {
        AX++;
    }
}

void Map::addY()
{
    if(AY<2)
    {
        AY++;
    }
}

void Map::substractX()
{
    if(AX > 0)
    {
        AX--;
    }
}

void Map::substractY()
{
    if(AY > 0)
    {
        AY--;
    }
}

void Map::refreshActiveArea()
{
    setActiveArea(AX,AY);
}
