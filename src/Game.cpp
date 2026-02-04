#include <Game.h>




Game::Game() : player(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, Vector2{PLAYER_SIZE_X, PLAYER_SIZE_Y}){}


void Game::start()
{
    renderer.init();
    renderer.setScreenColor(ST7735_BLACK);
    mapsManager.init(renderer);
}

void Game::loop()
{
    renderer.renderPlayer(player.getGameObject());
    player.update(renderer, mapsManager);

}






Game::~Game()
{
    
}
