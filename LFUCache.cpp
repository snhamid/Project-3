#include <iostream>
#include "LFUCache.hpp"

LFUCache::LFUCache(int size)
{
    setSize(size);
    frequencyList = new int[size];

    for (int i = 0; i < size; i++)
    {
        frequencyList[i] = 0;
    }
}

int LFUCache::getIndexOfItem(int item)
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

void LFUCache::addItem(int item)
{
    int index = getIndexOfItem(item);

    //Increase frequency by 1 if item is in cache
    if (index != -1)
    {
        int freq = frequencyList[index];
        freq++;
        frequencyList[index] = freq;
    }

    else
    {

        if (numItem >= size)
        {
            //Removing the item with the lowest frequency
            int minIndex = frequencyList[0];
            for (int i = 0; i < numItem; ++i)
            {
                if (frequencyList[i] < frequencyList[minIndex])
                {
                    minIndex = i;
                }
            }

            //Reordering items
            for (int i = minIndex; i > 0; i--)
            {
                dataCache[i] = dataCache[i - 1];
                frequencyList[i] = frequencyList[i - 1];
            }
            dataCache[0] = item;
            frequencyList[0] = 1;
        }

        else
        {
            for (int i = numItem; i > 0; i--)
            {
                dataCache[i] = dataCache[i - 1];
                frequencyList[i] = frequencyList[i - 1];
            }
            dataCache[0] = item;
            frequencyList[0] = 1;

            numItem++;
        }
    }
}

void LFUCache::print()
{
    for (int i = 0; i < numItem; i++)
    {
        std::cout << dataCache[i] << "\n";
    }
}
