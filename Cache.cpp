#include "Cache.hpp"

//Returns the item at the front of the cache
int Cache::getItemAtFront()
{
    return dataCache[0];
}

//Sets the size of the cache
void Cache::setSize(int someSize)
{
    size = someSize;
    dataCache = new int[size];
    numItem = 0;
}