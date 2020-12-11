#ifndef CACHE_HPP
#define CACHE_HPP

#include <iostream>

class Cache
{
protected:
    int size;
    int numItem;
    int *dataCache;
    void setSize(int someSize);

public:
    virtual void addItem(int item) = 0;
    virtual int getIndexOfItem(int item) = 0;
    virtual void print() = 0;
    int getItemAtFront();
};

#endif