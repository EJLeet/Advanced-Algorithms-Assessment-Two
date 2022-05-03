#ifndef kSmallest_h
#define kSmallest_h

#include <set>

class kSmallest
{
    // k smallest is passed from file
    long k = 0;

    // initialise multiset of all integers and k smallest
    std::multiset<long> smallest, largest;

public:
    
    // construct from file
    kSmallest(char* filename);

    // add integer
    void add(long element);

    // delete integer
    void remove(long element);

    // print k smallest
    void print();
};

#endif