
#include "LRUCache.hpp"

LRUCache::LRUCache()
{
}

LRUCache::LRUCache(int size)
{
    setSize(size);
}

//Returns the index of the item in the cache, returns -1 if it does not exist in cache
int LRUCache::getIndexOfItem(int item)
{
    for (int i = 0; i < numItem; i++)
    {
        if (item == dataCache[i])
        {
            return i;
        }
    }
    return -1;
}

//Adds item to beginning of cache, checks if it exists in cache
void LRUCache::addItem(int item)
{
    int index = getIndexOfItem(item);

    //Adds item to the front of the list an increases numItem by 1 if it does not exist in cache
    if (index != -1)
    {
        for (int i = index; i > 0; i--)
        {
            dataCache[i] = dataCache[i - 1];
        }
        dataCache[0] = item;
    }

    //Moves item to front of cache if it already exists in the cache
    else
    {
        for (int i = numItem; i > 0; i--)
        {
            dataCache[i] = dataCache[i - 1];
        }
        dataCache[0] = item;
        numItem++;
    }

    if (numItem >= size)
    {
        numItem = size;
    }
}

//Prints the cache line by line
void LRUCache::print()
{
    for (int i = 0; i < numItem; i++)
    {
        std::cout << dataCache[i] << "\n";
    }
}

LRUCache::~LRUCache()
{
    delete[] dataCache;
}