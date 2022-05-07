#include "Maze.hpp"
#include "DisjointSets.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Maze::initialise()
{
    // set index and walls for each node
    for (int i = 0; i < size; i++)
    {
        square.push_back(i);

        // first row -> top wall cant be removed
        if (i < col - 1)
            square[i].top = 2;

        // last row -> bot wall cant be removed
        else if (i > col * (row - 1))
            square[i].bot = 2;

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
{
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
            // knock down wall
            square[rand_square].top = 0;

            // unionise
            nodes.union_set(rand_square, rand_square - col);
        }

        // bot
        else if (rand_wall == 1 && square[rand_square].bot == 1)
        {
            // knock down wall
            square[rand_square].bot = 0;

            // unionise
            nodes.union_set(rand_square, rand_square + col);
        }

        // left
        else if (rand_wall == 2 && square[rand_square].left == 1)
        {
            // knock down wall
            square[rand_square].left = 0;

            // unionise
            nodes.union_set(rand_square, rand_square - 1);
        }

        // right
        else if (rand_wall == 3 && square[rand_square].right == 1)
        {
            // knock down wall
            square[rand_square].right = 0;

            // unionise
            nodes.union_set(rand_square, rand_square + 1);
        }
    }
}

void Maze::display()
{
    // border
    cout << "+";
    for(int i = 0; i < col; i++)
        cout << "--+";
    cout << endl;

    for(int i = 0; i < row; i++)
    {
        // opening cell
        i == 0 ? cout << " " : cout << "|";

        // internal vertical
        for(int j = 0; j < col; j++)
            square[i * col + j].right != 0 
                ? cout << "  |" : cout << "   ";

        // border
        cout << endl;
        cout << "+";

        // internal horizontal
        for(int j = 0; j < col; j++)
            square[i * col + j].bot != 0
                ? cout << "--+" : cout << "  +";

        cout << endl;
    }
}
