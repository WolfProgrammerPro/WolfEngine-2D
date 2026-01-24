#include <Game.h>

Game game;


void setup() {
    Serial.begin(115200);
    game.start();
    
}

void loop()
{
    game.loop();
}