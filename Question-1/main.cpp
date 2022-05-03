#include <iostream>
#include "kSmallest.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    if (argc < 2)
    { // ensure file passed
        cout << "ERROR! Expected List " << endl;
        exit(1);
    }

    // create structure with filename passed
    kSmallest lst = kSmallest(argv[1]);

    // print k smallest
    cout << "List after initial construction: " << endl;
    lst.print();
    cout << endl;
    
    // test add into smallest
    cout << "List after add 3: " << endl;
    lst.add(3);
    lst.print();
    cout << endl;

    // test add into largest
    cout << "List after add 560: " << endl;
    lst.add(560);
    lst.print();
    cout << endl;

    // test delete from smallest
    cout << "List after delete 2: " << endl;
    lst.remove(2);
    lst.print();
    cout << endl;

    // test delete from largest
    cout << "List after delete 89: " << endl;
    lst.remove(89);
    lst.print();

    // find function

    // test delete does not exist

    // print should return a list, then print it

    // add sequential which returns total list



    return 0;
}