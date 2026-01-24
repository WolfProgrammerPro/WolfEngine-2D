#include <Renderer.h>

Renderer::Renderer() : display(TFT_CS, TFT_DC, TFT_RST) , oldPlayerPosition(Vector2{-1,-1})
{
    
}

void Renderer::init()
{
    display.initR(INITR_BLACKTAB);
    display.setRotation(1);
}

void Renderer::setScreenColor(uint16_t color)
{
    display.fillScreen(color);
}




void Renderer::render(const GameObject* const& gameObjects, size_t size)
{

    for (size_t i = 0; i < size; i++)
    {
        const GameObject& object = gameObjects[i];
        
        renderObject(object);
        
    }
    for (size_t i = 0; i < size; i++)
    {
        const GameObject& object = gameObjects[i];
        
        if (object.getType() != DOOR)
        {
            renderObject(object);
        }
        
    }
    
}


void Renderer::renderPlayer(GameObject player)
{
    Vector2 playerPosition = player.getPosition();
    if (playerPosition != oldPlayerPosition)
    {
        int playerPositionX = playerPosition.x * SIZE_MULTIPLIER;
        int playerPositionY = REAL_HEIGHT - (playerPosition.y+1) * SIZE_MULTIPLIER;

        if (oldPlayerPosition.x != -1)
        {
            int oldPlayerPositionX = oldPlayerPosition.x * SIZE_MULTIPLIER;
            int oldPlayerPositionY = REAL_HEIGHT - (oldPlayerPosition.y+1) * SIZE_MULTIPLIER;
            
            display.fillRect(oldPlayerPositionX, oldPlayerPositionY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, ST7735_BLACK);
        }

        oldPlayerPosition = playerPosition;
        display.fillRect(playerPositionX, playerPositionY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, getGameObjectColor(PLAYER));
    }
}


void Renderer::renderObject(const GameObject& gameObject)
{
    GameObjectType type = gameObject.getType();
    if (type != NONE)
    {
        uint16_t color = getGameObjectColor(type);
        Vector2 pos = gameObject.getPosition();
        int screenX = pos.x * SIZE_MULTIPLIER;
        int screenY = REAL_HEIGHT - (pos.y+1) * SIZE_MULTIPLIER;
        if (gameObject.isActive())
        {
            if (type == DOOR)
            {
                display.fillRect(screenX, screenY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, ST7735_BLACK);
                display.drawRect(screenX, screenY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, color);
            }
            else if (type == WALL)
            {
                display.fillRect(screenX, screenY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, color);
            }
            else
            {
                display.fillRect(screenX, screenY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, color);
            }
        }
        else
        {
            display.fillRect(screenX, screenY, SIZE_MULTIPLIER, SIZE_MULTIPLIER, ST7735_BLACK);
        }  
    }  
}

uint16_t Renderer::getGameObjectColor(GameObjectType type)
{
    switch (type)
    {
        case NONE: return 0; break;
        case WALL: return ST77XX_WHITE; break;
        case PLAYER: return ST77XX_BLUE; break;
        case KEY: return ST7735_YELLOW; break;
        case DOOR: return ST7735_ORANGE; break;
        case FINISH: return ST7735_GREEN; break;
    }
    return 0;
}
