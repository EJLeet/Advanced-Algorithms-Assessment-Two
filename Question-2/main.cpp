#include "Maze.hpp"
#include <iostream>

using std::cout;
using std::endl;

void generate(char* r, char* c);

int main(int argc, char** argv)
{
    if (argc < 3)
    { // ensure file passed
        cout << "ERROR! Expected Maze Dimensions Row and Col" << endl;
        exit(1);
    }

    generate(argv[1], argv[2]);

    return 0;
}

void generate(char* r, char* c)
{
    int row = atoi(r), col = atoi(c);
    int size = row * col;

    // create maze
    Maze maze (row, col);

    // initialise maze with all walls in tact
    maze.initialise();
    
    // destroy until solution
    maze.destroy();

    // display final maze
    maze.display();

}

