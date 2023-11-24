#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGame; 
Player* myPlayer; 
char input; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGame->getExitFlagStatus() == false)  
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


}

void GetInput(void)
{
    input = myGame->getInput(); 

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer(); 
    if(input == '\t'){
        myGame->setExitTrue();
    }
    myGame->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos tempPos; 

    myPlayer->getPlayerPos(tempPos); // this get the player pos and assigns it to temp position
    //sets the tempPos into the playerPos x,y and symbo
    int i, j; 
    for ( i =0; i < myGame->getBoardSizeY(); i++) 
    {
        for(j=0; j < myGame->getBoardSizeX(); j++)
        {

            if( i == 0 || j == 0 || i == myGame->getBoardSizeY()-1 || j == myGame->getBoardSizeX() -1) 
            {
                
                MacUILib_printf("%c", '#'); 
            }

            else if ( i == tempPos.y && j == tempPos.x )
            { 
                MacUILib_printf("%c", tempPos.symbol);
            }
            else{
        
                MacUILib_printf("%c", ' '); 
            }
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    delete myGame; 
    delete myPlayer; 
}
