#pragma once

#include <Utils.h>
#include <GameObject.h>
#include <Renderer.h>

class MapsManager
{
    public:
        MapsManager();
        void nextMap(Renderer& renderer);
        void init(Renderer& renderer);
        GameObject* getCurrentMap() {return maps[currentMap -1];}
        size_t getCurrentMapNumber() {return currentMap;}
        void renderCurrentMap(Renderer& renderer);
        size_t getCurrentMapSize() {return maps_lengths[currentMap -1];}
    private:
        GameObject maps[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL];
        size_t maps_lengths[LEVEL_COUNT] = {0};
        size_t currentMap = 1;
        void loadMaps();
        
};