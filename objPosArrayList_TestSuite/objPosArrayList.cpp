#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; 
    listSize = 0; 
    arrayCapacity =  ARRAY_MAX_CAP; 
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

int objPosArrayList::getSize()
{
    return listSize; 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for(int i = listSize; i>0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize>0){
        for(int i = 0; i < listSize-1; i++){
            aList[i] = aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if(listSize > 0){
        listSize--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    aList[0].getObjPos(returnPos);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    aList[listSize - 1].getObjPos(returnPos);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    aList[index].getObjPos(returnPos);
}