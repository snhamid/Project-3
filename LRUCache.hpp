#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#include "Cache.hpp"

class LRUCache : public Cache
{
public:
    LRUCache();
    LRUCache(int size);
    void addItem(int item);
    int getIndexOfItem(int item);
    void print();
    ~LRUCache();
};

#endif