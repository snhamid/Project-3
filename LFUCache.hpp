#ifndef LFUCACHE_HPP
#define LFUCACHE_HPP
#include <iostream>
#include "Cache.hpp"

class LFUCache : public Cache
{
public:
    LFUCache(int size);
    void addItem(int item);
    int getIndexOfItem(int item);
    void print();
    ~LFUCache();

private:
    int *frequencyList;
};

#endif