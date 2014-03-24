#include "Renderizer.h"

int main()
{

    Map m;
    m.generateMap();
    Renderizer render;
    render.load_files();
    render.setMap(m);
    render.start_game();


    return EXIT_SUCCESS;
}
