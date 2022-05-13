#include "veb.hpp"
#include <set>
#include <iostream> 
#include <chrono>

using std::cout;
using std::endl;

void rbt_test(int elements);
void veb_test(int elements);

int main()
{
    rbt_test(10000);
    rbt_test(100000);
    rbt_test(1000000);
    rbt_test(10000000);
    rbt_test(100000000);

    veb_test(10000);
    veb_test(100000);
    veb_test(1000000);
    veb_test(10000000);
    veb_test(100000000);

    return 0;
} 

void rbt_test(int elements)
{
   /*
     increasing
                */
    cout << "Increasing Order: " << endl;
    std::set<int> rbt;
    // insert
    auto start = std::chrono::high_resolution_clock::now();  
    for (int i = 0; i <= elements; i++)
        rbt.emplace(i);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for (auto it = rbt.begin(); it != rbt.end(); it++)
        continue;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.begin()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.end()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(elements / 2) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    int random = rand() % elements;
    if(rbt.find(random) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find random element " << random << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= elements / 10; i++)
        rbt.insert((rand() % elements) + elements);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    rbt.clear();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "RBT clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;

   /*
     decreasing
                */
    cout << "Decreasing Order: " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    for (int i = elements; i >= 0; i--)
        rbt.emplace(i);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for (auto it = rbt.begin(); it != rbt.end(); it++)
        continue;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.begin()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.end()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(elements / 2) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    random = rand() % elements;
    if(rbt.find(random) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find random element " << random << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for (int i = elements / 10; i <= 0; i--)
        rbt.insert((rand() % elements) + elements);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    rbt.clear();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "RBT clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;

   /*
     random
                */
    cout << "Random Order: " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    for (int i = 0; i <= elements; i++)
        rbt.emplace(rand() % elements);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for (auto it = rbt.begin(); it != rbt.end(); it++)
        continue;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.begin()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.end()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(elements / 2) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    random = rand() % elements;
    if(rbt.find(random) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find random element " << random << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= elements / 10; i++)
        rbt.insert((rand() % elements) + elements);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    rbt.clear();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "RBT clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;

   /*
     first last second second last...
                                        */
    cout << "Alternating Order(1st, last, 2nd, 2nd last...): " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    int count = 0;
    while (count <= elements)
    {
        rbt.emplace(count);
        rbt.emplace(elements - count);
        count++;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for (auto it = rbt.begin(); it != rbt.end(); it++)
        continue;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.begin()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(*rbt.end()) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    if(rbt.find(elements / 2) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    random = rand() % elements;
    if(rbt.find(random) != rbt.end())
        ;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT find random element " << random << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= elements / 10; i++)
        rbt.insert((rand() % elements) + elements);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "RBT insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    rbt.clear();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "RBT clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;
}

/*
    This code is mainly adapted from the
    github linked in the header
                                            */
void veb_test (int elements)
{
    /*
     increasing
                */
    int res;
    TvEB * tree = new TvEB (elements);
    int * numbers = new int [elements];
    cout << "Increasing Order: " << endl;

    // insert
    auto start = std::chrono::high_resolution_clock::now();  
    for ( int i = 0; i <= elements; ++i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, i );
      }
      else
        numbers[i] = 0;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      res = vEB_find ( tree, idx );
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, 0 );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, elements );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    int idx = elements / 2;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    idx = rand() % elements;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find random element " << idx << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements / 10; ++i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, i );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      if ( numbers[idx] )
      {
        res = vEB_delete ( tree, idx );
        numbers[idx] = 0;
      }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "VEB clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;
    delete tree;
    delete[] numbers;

   /*
     decreasing
                */
    tree = new TvEB (elements);
    numbers = new int [elements];
    cout << "Decreasing Order: " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    for ( int i = elements; i >= 0; --i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, i );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for ( int i = elements; i >= 0; --i )
    {
      int idx = i;
      res = vEB_find ( tree, idx );
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, 0 );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, elements );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    idx = elements / 2;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    idx = rand() % elements;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find random element " << idx << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for ( int i = elements / 10; i <= 0; --i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, i );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    for ( int i = elements; i >= 0; --i )
    {
      int idx = i;
      if ( numbers[idx] )
      {
        res = vEB_delete ( tree, idx );
        numbers[idx] = 0;
      }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "VEB clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;
    delete tree;
    delete[] numbers;

   /*
     random
                */
    tree = new TvEB (elements);
    numbers = new int [elements];
    cout << "Random Order: " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    for ( int i = elements; i >= 0; --i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, rand() % elements );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      res = vEB_find ( tree, idx );
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, 0 );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, elements );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    idx = elements / 2;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    idx = rand() % elements;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find random element " << idx << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements / 10; ++i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, (rand() % elements) + elements );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      if ( numbers[idx] )
      {
        res = vEB_delete ( tree, idx );
        numbers[idx] = 0;
      }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "VEB clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;
    delete tree;
    delete[] numbers;

   /*
     first last second second last...
                                        */
    tree = new TvEB (elements);
    numbers = new int [elements];
    cout << "Alternating Order(1st, last, 2nd, 2nd last...): " << endl;
    // insert
    start = std::chrono::high_resolution_clock::now();  
    int count = 0;
    while (count <= elements)
    {
        if (rand() % 8 == 0)
        {
            numbers[count] = 1;
            res = vEB_insert(tree, count);
            numbers[elements - count] = 1;
            res = vEB_insert(tree, elements - count);
            count++;
        }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB inserted " << elements << " elements in " << duration << " seconds" <<  endl;

    // sequential access
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      res = vEB_find ( tree, idx );
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB Sequential access of " << elements << " elements in " << duration << " seconds" <<  endl;

    // find first element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, 0 );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find first element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find last element
    start = std::chrono::high_resolution_clock::now();
    res = vEB_find ( tree, elements );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find last element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find middle element
    start = std::chrono::high_resolution_clock::now();
    idx = elements / 2;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find middle element out of " << elements << " in " << duration << " seconds" <<  endl;    

    // find random element
    start = std::chrono::high_resolution_clock::now();
    idx = rand() % elements;
    res = vEB_find ( tree, idx );
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB find random element " << idx << " out of " << elements << " in " << duration << " seconds" <<  endl;    

    // add 10% more elements
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements / 10; ++i )
    {
      if ( rand() % 8 == 0 )
      {
        numbers[i] = 1;
        res = vEB_insert ( tree, i );
      }
      else
        numbers[i] = 0;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << "VEB insert " << elements / 10 << " random elements " << " in " << duration << " seconds" <<  endl; 

    // empty tree
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i <= elements; ++i )
    {
      int idx = i;
      if ( numbers[idx] )
      {
        res = vEB_delete ( tree, idx );
        numbers[idx] = 0;
      }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::seconds> (stop - start).count();
    cout << std::fixed << "VEB clear " << int(elements * 1.1) << " elements " << " in " << duration << " seconds" <<  endl; 
    
    cout << endl;
}