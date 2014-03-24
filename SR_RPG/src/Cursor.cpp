#include "Cursor.h"

Cursor::Cursor()
{
    //ctor
}

Cursor::~Cursor()
{
    //dtor
}

void Cursor::setActiveArea(Area activeArea)
{
    this->activeArea=activeArea;
}

void Cursor::setMap(Map *m)
{
    this->m=m;
}

void Cursor::setCharacter(int x, int y)
{
    activeArea.setTile(x,y,'P');
    setIM(x,y);
}

void Cursor::setIM(int x, int y)
{
    IWX = IMX;
    IMX = x;
    IWY = IMY;
    IMY = y;
}

void Cursor::cleanIW()
{
    activeArea.setTile(IWX,IWY,'T');
}

//send number of spaces
bool Cursor::moveCursor(int vx, int vy)
{
    int NX = IMX+vx;
    int NY = IMY+vy;

    if((NX >=0 && NX <= 10)&&(NY >= 0 && NY <= 10))
    {
        if((NX == 5 && NY == 0) && activeArea.getTiles(NX,NY) == 'E')
        {
            m->substractY();
            setActiveArea(m->getActiveArea());
            setCharacter(5,9);
            cleanIW();
            return true;
        }
        else if(NX == 5 && NY == 10 && activeArea.getTiles(NX,NY) == 'E')
        {
            m->addY();
            setActiveArea(m->getActiveArea());
            setCharacter(5,1);
            cleanIW();
            return true;
        }
        else if(NX == 0 && NY == 5 && activeArea.getTiles(NX,NY) == 'E')
        {
            m->substractX();
            setActiveArea(m->getActiveArea());
            setCharacter(9,5);
            cleanIW();
            return true;
        }
        else if(NX == 10 && NY == 5 && activeArea.getTiles(NX,NY) == 'E')
        {
            m->addX();
            setActiveArea(m->getActiveArea());
            setCharacter(1,5);
            cleanIW();
            return true;
        }
        else if(activeArea.getTiles(NX,NY) == 'T')
        {
            setActiveArea(m->getActiveArea());
            setCharacter(NX,NY);
            cleanIW();
            return true;
        }
    }
    return false;
}
