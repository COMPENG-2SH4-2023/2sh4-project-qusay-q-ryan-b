#include "Food.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include <iostream> 
#include <cstdlib> // Include the necessary library for srand/rand
#include <ctime>

using namespace std; 

Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(5,5,'0'); 
    mainGameMechsRef = thisGMRef;
    srand(time(NULL)); 


}

Food::~Food()
{
    //nothing to be deleteed
}

void Food::generateFood(objPosArrayList *blockoff)
{
    int randX = 0, randY = 0;
    objPos temp;
    bool flag = false;

    // change for all elements of player
    while (!flag)
    {
        randX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2)) + 1;
        randY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2)) + 1;
        foodPos.setObjPos(randX, randY, 'o');

        flag = true;  

        for (int i = 0; i < blockoff->getSize(); i++)
        {
            blockoff->getElement(temp, i);
            if (temp.x == randX && temp.y == randY)
            {
                flag = false;  
                break;
            }
        }
    }
}


void Food::getFoodPos(objPos &returnPos){

    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol); 
}


