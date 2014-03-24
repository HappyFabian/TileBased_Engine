#include "Renderizer.h"

Renderizer::Renderizer()
{
    this->app = new sf::RenderWindow(sf::VideoMode(352, 352), "SFML window");
}

void Renderizer::setMap(Map m)
{
    this->m=m;
}

Renderizer::~Renderizer()
{
    //dtor
}

void Renderizer::load_files()
{
    load_textures();
    load_sprites();
}

void Renderizer::load_sprites()
{
    this->sprite_floor = sf::Sprite(texture1);
    this->sprite_wall =  sf::Sprite(texture2);
    this->sprite_exit =  sf::Sprite(texture3);
    this->sprite_char =  sf::Sprite(texturechar);
}

bool Renderizer::load_textures()
{

    if (!(this->texture1.loadFromFile("Grass.png")))
        return EXIT_FAILURE;

    if (!(this->texture2.loadFromFile("Wall.png")))
        return EXIT_FAILURE;

    if (!(this->texture3.loadFromFile("Exit.png")))
        return EXIT_FAILURE;

    if (!(this->texturechar.loadFromFile("Char.png")))
    return EXIT_FAILURE;

}

void Renderizer::start_game()
{
    sf::Keyboard keybo;


    cur.setMap(&m);
    cur.setActiveArea(m.getActiveArea());
    cur.setCharacter(5,5);

    font.loadFromFile("arial.ttf");

    mySteps.setFont(font);
    mySteps.setPosition(4,4);
    mySteps.setCharacterSize(16);

    int speed = 155;
    int tempo = 0;


    while (this->app->isOpen())
    {
        stepst = refreshSteps(steps);
        mySteps.setString(stepst);
        sf::Event event;
        while (app->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app->close();
        }

        // Clear screen
        app->clear();

        if(keybo.isKeyPressed(keybo.J) && tempo > 1000)
        {
            m.substractX();
            tempo=0;
        }
        if(keybo.isKeyPressed(keybo.L) && tempo > 1000)
        {
            m.addX();
            tempo = 0;

        }
        if(keybo.isKeyPressed(keybo.I) && tempo > 1000)
        {
            m.substractY();
            tempo = 0;

        }
        if(keybo.isKeyPressed(keybo.K) && tempo > 1000)
        {
            m.addY();
            tempo = 0;
        }

        // Movement
        if(keybo.isKeyPressed(keybo.Left) && tempo > speed)
        {
            if(cur.moveCursor(-1,0))
            {
                tempo = 0;
                steps++;
            }

        }
        if(keybo.isKeyPressed(keybo.Right) && tempo > speed)
        {
            if(cur.moveCursor(1,0))
            {
                tempo = 0;
                steps++;
            }

        }
        if(keybo.isKeyPressed(keybo.Up) && tempo > speed)
        {
            if(cur.moveCursor(0,-1))
            {
                tempo = 0;
                steps++;
            }
        }
        if(keybo.isKeyPressed(keybo.Down) && tempo > speed)
        {
            if(cur.moveCursor(0,1))
            {
                tempo = 0;
                steps++;
            }
        }

        m.refreshActiveArea();
        drawMap();

        drawCursor();

        app->draw(mySteps);

        // Update the window
        app->display();
        tempo++;
    }
    cout << m.AX << m.AY << endl;
    cout << "Steps: " << steps << endl;
}

void Renderizer::drawMap()
{
    for(int y = 0; y < 11; y++)
        {
            for(int x = 0; x < 11; x++)
            {
                char tile = m.getActiveArea().tiles[y][x].getTile();
                if( tile == 'W')
                {
                    sprite_wall.setPosition(x*32,y*32);
                    app->draw(sprite_wall);
                }
                if( tile == 'T')
                {
                    sprite_floor.setPosition(x*32,y*32);
                    app->draw(sprite_floor);
                }
                if( tile ==  'E')
                {
                    sprite_exit.setPosition(x*32,y*32);
                    app->draw(sprite_exit);
                }
            }
        }
}

void Renderizer::drawCursor()
{
    for(int y = 0; y < 11; y++)
    {
        for(int x = 0; x < 11; x++)
        {
            char tile = cur.activeArea.getTiles(x,y);
            if(tile == 'P')
            {
                sprite_char.setPosition(x*32,y*32);
                app->draw(sprite_char);
            }
        }
    }
}

string Renderizer::refreshSteps(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}
