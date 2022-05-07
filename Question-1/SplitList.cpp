#include "SplitList.hpp"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

SplitList::SplitList(char* filename)
{/*
    This function firstly extracts k from the text file.
    It then adds all integers in the file to a multiset
    and constructs multisets containing the k smallest
    and n - k largest elements of the list.
                                                            */
   
    // initialise file stream and temp variables
    std::multiset<long> all;
    std::ifstream file(filename);
    long x;

    // get k
    file >> k;

    // add all integers to multiset
    while (file >> x)
        all.emplace(x);
    
    int count = 0;
    for (auto it : all)
        count++ < k ? smallest.emplace(it) 
            : largest.emplace(it);
}

void SplitList::add(long element)
{/*
    This function will add element to the appropriate multiset
    and will handle reshuffling of smallest if necessary.
                                                                    */
    cout << "Attempting To Add Element " << element << endl;   

    // element belongs in largest
    if (element >= *largest.begin())
        largest.emplace(element);

    // element belongs to smallest
    else
    {
        smallest.emplace(element);

        // add largest in smallest to largest
        largest.emplace(*--smallest.end());

        // remove last element in order to keep k smallest
        smallest.erase(smallest.lower_bound(*--smallest.end()));
    }
}

void SplitList::remove(long element)
{/*
    This function removes an element from the appropriate
    multiset and then reshuffles in order to maintain the 
    k smallest if necessary.
                                                            */
    cout << "Attempting To Remove Element " << element << endl; 

    if (!search(element))
        cout << "Element Does Not Exist!" << endl;

    // element belongs to largest
    else if (element >= *smallest.end() - 1)
        largest.erase(largest.lower_bound(element));
    
    // element belongs to smallest
    else
    {
        smallest.erase(smallest.lower_bound(element));

        // get smallest element from largest
        smallest.emplace(*largest.begin());

        // remove smallest element from largest
        largest.erase(largest.lower_bound(*largest.begin()));
    }     
}

std::multiset<long> SplitList::k_smallest() 
{// This function returns the smallest multiset
    cout << "K Smallest List: ";
    return smallest; 
}

std::multiset<long> SplitList::sequential()
{/* This function creates and returns a multiset 
    which contains the whole datastructure
                                                    */
    cout << "Sequential List: ";
    std::multiset<long> all = largest;
    all.insert(smallest.begin(), smallest.end());
    return all;
}

bool SplitList::search(long element)
{// This function search the data structure for an element
    return (largest.find(element) != largest.end() || 
            smallest.find(element) != smallest.end()) ?
            true : false;
}