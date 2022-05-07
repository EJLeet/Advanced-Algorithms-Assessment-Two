#include "Maze.hpp"
#include "DisjointSets.hpp"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

void Maze::initialise()
{/*
    This method initialise a vector of squares
    and sets up an indestructible walls.        */

    // set index and walls for each node
    for (int i = 0; i < size; i++)
    {
        square.push_back(Square(i));

        // first row -> top wall cant be removed
        if (i < col)
        {
            square[i].top = 2;

            // corner case
            if ((i + 1) % col == 0)
                square[i].right = 2;
        }

        // last row -> bot wall cant be removed
        else if (i > col * (row - 1) - 1)
        {
            square[i].bot = 2;

            // corner case
            if (i % col == 0)
                square[i].left = 2;
        }

        // first col -> left wall cant be removed
        else if (i % col == 0)
            square[i].left = 2;

        // last col -> right wall cant be removed
        else if ((i + 1) % col == 0)
            square[i].right = 2;
    }

    // first node -> left entrance
    square[0].left = 0;
    
    // last node -> right entrance
    square[size - 1].right = 0;
}

void Maze::destroy()
{/*
    This method creates a disjointed set for
    each square on the grid. It then randomly
    knocks down available walls until the
    start node and end goal node are in the
    same disjointed set.                        */

    // create disjoint sets for every node
    DisjointSets nodes(size);

    while (nodes.find(start) != nodes.find(end))
    {
        // choose random square
        int rand_square = rand() % square.size();

        /*  choose random wall
            0 = top
            1 = bot
            2 = left
            3 = right            */
        int rand_wall = rand() % 4;

        // check if wall can be knocked down

        // top
        if (rand_wall == 0 && square[rand_square].top == 1)
        {
            // knock down wall and adjoining
            square[rand_square].top = 0;
            square[rand_square - col].bot = 0;

            // unionise
            nodes.union_set(rand_square, rand_square - col);
        }

        // bot
        else if (rand_wall == 1 && square[rand_square].bot == 1)
        {
            // knock down wall and adjoining
            square[rand_square].bot = 0;
            square[rand_square + col].top = 0;

            // unionise
            nodes.union_set(rand_square, rand_square + col);
        }

        // left
        else if (rand_wall == 2 && square[rand_square].left == 1)
        {
            // knock down wall and adjoining
            square[rand_square].left = 0;
            square[rand_square - 1].right = 0;

            // unionise
            nodes.union_set(rand_square, rand_square - 1);
        }

        // right
        else if (rand_wall == 3 && square[rand_square].right == 1)
        {
            // knock down wall and adjoining
            square[rand_square].right = 0;
            square[rand_square + 1].left = 0;

            // unionise
            nodes.union_set(rand_square, rand_square + 1);
        }
    }
}

void Maze::display()
{/*
    This method outputs the generated
    maze to a .txt file.                */
    
    std::ofstream file;
    file.open("maze.txt");

    // border
    file << "+";
    for(int i = 0; i < col; i++)
        file << "--+";
    file << endl;

    for(int i = 0; i < row; i++)
    {
        // opening cell
        i == 0 ? file << " " : file << "|";

        // internal vertical
        for(int j = 0; j < col; j++)
            square[i * col + j].right != 0 
                ? file << "  |" : file << "   ";

        // border
        file << endl;
        file << "+";

        // internal horizontal
        for(int j = 0; j < col; j++)
            square[i * col + j].bot != 0
                ? file << "--+" : file << "  +";

        file << endl;
    }
}
