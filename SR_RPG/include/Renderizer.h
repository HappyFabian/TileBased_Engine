#ifndef RENDERIZER_H
#define RENDERIZER_H

#include "Map.h"
#include "Cursor.h"

class Renderizer
{
    public:

        sf::RenderWindow* app;

        sf::Texture texture1; //Floor
        sf::Texture texture2; //Wall
        sf::Texture texture3; //Exit
        sf::Texture texturechar;

        sf::Sprite sprite_floor;
        sf::Sprite sprite_wall;
        sf::Sprite sprite_exit;
        sf::Sprite sprite_char;

        sf::Text mySteps;
        sf::Font font;

        string stepst;
        int steps = 0;

        Map m;
        Cursor cur;

        Renderizer();
        virtual ~Renderizer();
        void load_files();
        bool load_textures();
        void load_sprites();

        void setMap(Map m);
        void drawMap();
        void drawCursor();
        void start_game();
        string refreshSteps(int number);

    protected:
    private:
};

#endif // RENDERIZER_H
