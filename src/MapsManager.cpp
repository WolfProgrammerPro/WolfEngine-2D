#include <MapsManager.h>

MapsManager::MapsManager()
{
    for (int i = 0; i < LEVEL_COUNT; i++)
    {
        maps_lengths[i] = 0;
    }
    loadMaps();
    
}


void MapsManager::init(Renderer& renderer)
{
    renderCurrentMap(renderer);
}

void MapsManager::nextMap(Renderer& renderer)
{
    if (currentMap + 1 <= LEVEL_COUNT)
    {
        currentMap++;
    }
    else
    {
        currentMap = 1;
        loadMaps();
    }
    renderCurrentMap(renderer);
}


void MapsManager::loadMaps()
{
    maps[0][0] = GameObject(Vector2{10,7},FINISH);
    maps_lengths[0] = 1;

    maps[1][0] = GameObject(Vector2{6,0});
    maps[1][1] = GameObject(Vector2{6,1});
    maps[1][2] = GameObject(Vector2{6,2});
    maps[1][3] = GameObject(Vector2{6,3});
    maps[1][4] = GameObject(Vector2{6,4});
    maps[1][5] = GameObject(Vector2{6,5});
    maps[1][6] = GameObject(Vector2{6,8});
    maps[1][7] = GameObject(Vector2{6,9});
    maps[1][8] = GameObject(Vector2{6,10});
    maps[1][9] = GameObject(Vector2{6,11});
    maps[1][10] = GameObject(Vector2{6,12});
    maps[1][11] = GameObject(Vector2{6,13});
    maps[1][12] = GameObject(Vector2{6,14});
    maps[1][13] = GameObject(Vector2{6,15});
    maps[1][14] = GameObject(Vector2{10,5},FINISH);
    maps_lengths[1] = 15;

    maps[2][0] = GameObject(Vector2{10,0});
    maps[2][1] = GameObject(Vector2{10,1});
    maps[2][2] = GameObject(Vector2{10,2});
    maps[2][3] = GameObject(Vector2{10,3});
    maps[2][4] = GameObject(Vector2{10,4});
    maps[2][5] = GameObject(Vector2{10,5});
    maps[2][6] = GameObject(Vector2{10,8});
    maps[2][7] = GameObject(Vector2{10,9});
    maps[2][8] = GameObject(Vector2{10,10});
    maps[2][9] = GameObject(Vector2{10,11});
    maps[2][10] = GameObject(Vector2{10,12});
    maps[2][11] = GameObject(Vector2{10,13});
    maps[2][12] = GameObject(Vector2{10,14});
    maps[2][13] = GameObject(Vector2{10,15});
    maps[2][14] = GameObject(Vector2{15,9},FINISH);
    maps[2][15] = GameObject(Vector2{11,7},DOOR, 1);
    maps[2][16] = GameObject(Vector2{11,6},DOOR, 1);
    maps[2][17] = GameObject(Vector2{5,2},KEY, 1);
    maps[2][18] = GameObject(Vector2{11,5});
    maps[2][19] = GameObject(Vector2{11,8});
    maps_lengths[2] = 20;

}

void MapsManager::renderCurrentMap(Renderer& renderer)
{
    renderer.setScreenColor(ST7735_BLACK);
    renderer.render(getCurrentMap(), maps_lengths[getCurrentMapNumber()-1]);
}