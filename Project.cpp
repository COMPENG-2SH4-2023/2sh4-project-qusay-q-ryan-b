#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGame; 
Player* myPlayer; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGame = new GameMechs(26,13); 
    myPlayer = new Player(myGame); 

    exitFlag = false;
}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos tempPos; 
    myPlayer.getPlayerPos(tempPos); 
    MacUILib_printf("Board size is: %dn%d, Player Pos: <%d,%d> + %c", myGame->getBoardSizeX(), myGame->getBoardSizeY()
    ,tempPos.x, tempPos.y, tempPos.symbol); 

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
