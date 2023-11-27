#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGame; 
Player* myPlayer; 
Food* myFood; 
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
    myFood = new Food(myGame); 
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); //since tempPos in generateFood is the blockoff so that the food does not generate at the same place
    myFood->generateFood(tempPos); 


}

void GetInput(void)
{
    input = myGame->getInput(); 

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer(); 
    objPos tempPos; 
    myPlayer->getPlayerPos(tempPos); 
    objPos tempFoodPos; 
    myFood->getFoodPos(tempFoodPos); 
    if(input == '\t'){
        myGame->setExitTrue();
    }
    myGame->clearInput();


    if (tempPos.x == tempFoodPos.x && tempPos.y == tempFoodPos.y)
    {   
        myFood->generateFood(tempPos);     
        myGame->incrementScore(); 
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos tempPos; 
    objPos tempFoodPos; 
    myPlayer->getPlayerPos(tempPos); // this get the player pos and assigns it to temp position
    //sets the tempPos into the playerPos x,y and symbol
    myFood->getFoodPos(tempFoodPos);
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
            else if ( i == tempFoodPos.y && j == tempFoodPos.x)
            {
                MacUILib_printf("%c", tempFoodPos.symbol); 
            }
            else{
        
                MacUILib_printf("%c", ' '); 
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Your Current Score is: %d", myGame->getScore()); 

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
