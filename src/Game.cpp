#include <Game.h>




Game::Game() : player(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}), playerMovement(player), playerCollider(player){}


void Game::start()
{
    renderer.init();
    renderer.setScreenColor(ST7735_BLACK);
    mapsManager.init(renderer);
}

void Game::loop()
{
    renderer.renderPlayer(player);
    playerMovement.move(mapsManager);
    playerCollider.checkCollisions(renderer, mapsManager, playerMovement);

}






Game::~Game()
{
    
}
