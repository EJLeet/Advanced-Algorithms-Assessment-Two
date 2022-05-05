#include <iostream>
#include "SplitList.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    if (argc < 2)
    { // ensure file passed
        cout << "ERROR! Expected List" << endl;
        exit(1);
    }

    // create structure with filename passed
    SplitList lst = SplitList(argv[1]);
    
    // used for testing methods
    std::multiset<long> test;

    // initial k smallest list
    test = lst.k_smallest();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    // initial sequential list
    test = lst.sequential();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;
    
    // test add into smallest
    cout << endl;
    lst.add(3);

    test = lst.k_smallest();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    test = lst.sequential();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    // test add into largest
    cout << endl;
    lst.add(88);
    test = lst.k_smallest();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    test = lst.sequential();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    // test delete from smallest
    cout << endl;
    lst.remove(2);
    test = lst.k_smallest();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    test = lst.sequential();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    // test delete from largest
    cout << endl;
    lst.remove(67);
    test = lst.k_smallest();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    test = lst.sequential();
    for (auto i : test)
        cout << i << " ";
    test.clear();
    cout << endl;

    // test delete non exist
    cout << endl;
    lst.remove(500);

    // test search
    cout << endl << "List Contains 500: ";
    lst.search(500) ? cout << "True" << endl :
                      cout << "False" << endl;
    cout << "List Contains 78: ";
    lst.search(78) ? cout << "True" << endl :
                     cout << "False" << endl;

    return 0;
}