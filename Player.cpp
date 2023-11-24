#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y,playerPos.symbol); 
 
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 
    // PPA3 input processing logic
    switch(input)
    {                      
        case 'w':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){
                myDir = UP;
            }
            break;
        
        case 's':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){
                myDir = DOWN;
            }
            break;
                     
        case 'a':
            if (myDir == UP || myDir == DOWN || myDir == STOP){
                myDir = LEFT;
            }
            break;
        
        case 'd':
            if (myDir == UP || myDir == DOWN || myDir == STOP){
                myDir = RIGHT;
            }
            break;
        
        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir){
        case UP:
            playerPos.y--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            break;
    }
    if (playerPos.y == 0){
            playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
        }
    if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1){
        playerPos.y = 1;
    }
    if (playerPos.x == 0){
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1){
        playerPos.x = 1;
    }
}

