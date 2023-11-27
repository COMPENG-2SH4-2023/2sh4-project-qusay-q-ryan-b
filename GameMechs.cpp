#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    boardSizeX = 30; 
    boardSizeY = 15;
    gameBoard = new int*[boardSizeX]; 
    for(int i=0; i < boardSizeX; i++)
        gameBoard[i] = new int[boardSizeY]; 


}

GameMechs::GameMechs(int boardX, int boardY) //2-D Array
{
    input = 0;
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    boardSizeX = boardX; 
    boardSizeY = boardY; 
    // does this need to save guards? 
    if( boardSizeX <= 0)
        boardSizeX = 30;
    if(boardSizeY <= 0)
        boardSizeY = 15; 
    gameBoard = new int*[boardSizeX]; 
    for(int i=0; i < boardSizeX; i++)
        gameBoard[i] = new int[boardSizeY]; 

}

// do you need a destructor? --> nothing on the heap? 
//does GameMech require to create a board for the game? 
GameMechs::~GameMechs()
{
    for(int i=0; i < boardSizeX; i++)
        delete[] gameBoard[i]; 
    delete[] gameBoard; 
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag; 
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag; 
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar() == 1) 
    {
        input = MacUILib_getChar(); 
    }
    return input; 
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX; 
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY; 
}
int GameMechs::getScore()
{
    return score; 
}
void GameMechs::setExitTrue()
{
    exitFlag = true; 
}
void GameMechs::setLoseFlag()
{
    loseFlag = true; 
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{
    input = 0; 

}

void GameMechs::incrementScore()
{
    score++; 
}
// this needs to be implemented later on in the game
//when there is food on the board
//so that the score can be incremented everytime there is a collosion with a food
// and make sure that colliding with itself does not increment that score either