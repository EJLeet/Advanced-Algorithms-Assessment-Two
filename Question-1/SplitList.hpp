#ifndef SplitList_h
#define SplitList_h

#include <set>

class SplitList
{
    // k smallest is passed from file
    long k = 0;

    // initialise multiset of all integers and k smallest
    std::multiset<long> smallest, largest;

public:
    
    // construct from file
    SplitList(char* filename);

    // add integer
    void add(long element);

    // delete integer
    void remove(long element);

    // return k smallest
    std::multiset<long> k_smallest();

    // return entire structure
    std::multiset<long> sequential();

    // returns true if element is present in either list
    bool search(long element);
};

#endif