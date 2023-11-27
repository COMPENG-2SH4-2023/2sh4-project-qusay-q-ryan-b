#ifndef FOOD_H
#define FOOD_H

#include<stdlib.h>
#include <time.h> 

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


using namespace std; 

class Food{

    private: 
        objPos foodPos; 
        GameMechs* mainGameMechsRef;

    public: 
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood (objPos blockoff); 
        void getFoodPos ( objPos &objPos); 


};

#endif