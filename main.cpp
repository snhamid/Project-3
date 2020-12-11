#include <iostream>

#include "LFUCache.hpp"
#include "LRUCache.hpp"
#include "Cache.hpp"

using namespace std;

int main()
{
    Cache *myLRUCache = new LRUCache(5);
    Cache *myLFUCache = new LFUCache(5);
    Cache *myLFUCache2 = new LFUCache(5);

    cout << "**********************FIRST LRU TEST********************** \n";
    myLRUCache->addItem(5);
    myLRUCache->addItem(4);
    myLRUCache->addItem(3);
    myLRUCache->addItem(2);
    myLRUCache->addItem(1);
    cout << "Before adding the number 6: \n";
    myLRUCache->print();

    myLRUCache->addItem(6);
    cout << "After adding the number 6: \n";
    myLRUCache->print();

    cout << "Adding the number 3: \n";
    myLRUCache->addItem(3);
    myLRUCache->print();

    cout << "**********************SECOND LRU TEST********************** \n";
    myLRUCache->addItem(10);
    myLRUCache->addItem(25);
    myLRUCache->addItem(4);
    myLRUCache->addItem(19);
    myLRUCache->addItem(55);
    cout << "Before adding the number 22: \n";
    myLRUCache->print();

    myLRUCache->addItem(22);
    cout << "After adding the number 22: \n";
    myLRUCache->print();

    cout << "Adding the number 19: \n";
    myLRUCache->addItem(19);
    myLRUCache->print();

    cout << "**********************FIRST LFU TEST********************** \n";
    myLFUCache->addItem(5);
    myLFUCache->addItem(4);
    myLFUCache->addItem(3);
    myLFUCache->addItem(2);
    myLFUCache->addItem(1);
    cout << "Before changing frequencies: \n";
    myLFUCache->print();

    cout << "Increasing frequency of 1,2,3,5: \n";
    myLFUCache->addItem(5);
    myLFUCache->addItem(3);
    myLFUCache->addItem(2);
    myLFUCache->addItem(1);
    cout << "Attempting to replace the number 4 with 10: \n";
    myLFUCache->addItem(10);
    myLFUCache->print();

    cout << "**********************SECOND LFU TEST********************** \n";
    myLFUCache2->addItem(22);
    myLFUCache2->addItem(15);
    myLFUCache2->addItem(17);
    myLFUCache2->addItem(122);
    myLFUCache2->addItem(12);
    cout << "Before changing frequencies: \n";
    myLFUCache2->print();

    cout << "Increasing frequency of 22 and 17: \n";
    myLFUCache2->addItem(22);
    myLFUCache2->addItem(17);

    cout << "Attempting to replace a number with 200: \n";
    myLFUCache2->addItem(200);
    myLFUCache2->print();

    return 0;
}