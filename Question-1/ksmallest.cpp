#include "kSmallest.hpp"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

kSmallest::kSmallest(char* filename)
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
    
    // create smallest and largest multisets based on k
    auto it = *std::next(all.begin(), k);
    smallest.insert(all.begin(), all.lower_bound(it));
    largest.insert(all.lower_bound(it), all.end());
}

void kSmallest::print()
{/*
    This function prints the contents of the k smallest multiset
                                                                    */
    cout << "The " << k << "(k) smallest elements are: ";
    for (auto i : smallest)
        cout << i << " ";
    cout << endl;
}

void kSmallest::add(long element)
{/*
    This function will add element to the appropriate multiset
    and will handle reshuffling of smallest if necessary.
                                                                    */
    // element belongs in largest
    if (element > *largest.begin())
        largest.emplace(element);

    // element belongs to smallest
    else
    {
        smallest.emplace(element);

        // add largest in smallest to largest
        largest.emplace(*--smallest.end());

        // remove last element in order to keep k smallest
        smallest.erase(--smallest.end());
    }
}

void kSmallest::remove(long element)
{/*
    This function removes an element from the appropriate
    multiset and then reshuffles in order to maintain the 
    k smallest if necessary.
                                                            */
    // element belongs to largest
    if (element > *largest.begin())
        largest.erase(element);
    
    // element belongs to smallest
    else
    {
        smallest.erase(element);

        // get smallest element from largest
        smallest.emplace(*largest.begin());

        // remove smallest element from largest
        largest.erase(*largest.begin());
    }     
}