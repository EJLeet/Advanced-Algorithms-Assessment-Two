#include "Maze.hpp"
#include "DisjointSets.hpp"
#include <iostream>

using std::cout;
using std::endl;

void generate(int r, int c);

int main(int argc, char** argv)
{
    if (argc < 3)
    { // ensure file passed

        cout << "ERROR! Expected Maze Dimensions Row and Col" << endl;
        exit(1);
    }

    int r = atoi(argv[1]), c = atoi(argv[2]);

    if (r < 2 || c < 2)
    {// ensure valid maze dimensions passed

        cout << "ERROR! Minimum Size 2 x 2" << endl;
        exit(1);
    }

    generate(r, c);

    return 0;
}

void generate(int r, int c)
{
    int size = r * c;

    // create maze
    Maze maze (r, c);

    // initialise maze with all walls in tact
    maze.initialise();
    
    // destroy until solution
    maze.destroy();

    // output final maze
    maze.display();
}

