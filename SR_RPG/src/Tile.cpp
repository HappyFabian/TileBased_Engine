#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

char Tile::getTile()
{
    return thisTile;
}

void Tile::setTile(char TileType)
{
    this->thisTile=TileType;
}
