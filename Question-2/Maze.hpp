#ifndef Maze_h
#define Maze_h

#include <vector>

class Maze
{
    // initialise size (L x W)
    int row, col; 
    int size = row * col;
    int start = 0, end = size - 1;

    class Square
    {/*
        Position = position in the maze (row * col)
        Walls: 0 = no wall
        Walls: 1 = wall
        Walls: 2 = border (indestructible)
                                                */    
    public:                                                                              
        int position, top = 1, bot = 1, left = 1, right = 1;
        Square(int p) : position(p) {};
    };

    // initialise square for every node in maze
    std::vector<Square> square;
    
public:
    Maze(int r, int c) : row(r), col(c) {};

    // initial setup of maze via command line dimensions
    void initialise();

    // destroys a random wall
    void destroy();

    // outputs maze to .txt
    void display();
};

#endif