#include "DisjointSets.hpp"
#include <iostream>

DisjointSets::DisjointSets(int size)
{/*
    This method sets the size of parent and 
    depth vectors to be the amount of nodes 
    passed to the constructor. It then adds 
    all nodes to parent and depth vectors.
                                            */
    nodes = size;

    for (int i = 0; i < nodes; i++)
    {
        parent.push_back(i);
        depth.push_back(i);
    }
}

int DisjointSets::find(int node)
{/* 
    This method finds a node and performs
    path compression
                                            */
    if (node != parent[node])
        parent[node] = find(parent[node]); 
    return parent[node];
}

void DisjointSets::union_set(int u1, int u2)
{/*
    This method finds the union of two representatives.
    If they are already unionised it returns. Otherwise
    it unionises them and increases the depth of the
    smallest node.  
                                                        */
    int p1 = find(u1), p2 = find(u2);

    // items are in same set
    if (p1 == p2)
        return;
    
    // increase depth of p2
    if (depth[p1] > depth[p2])
    {    
        parent[p2] = p1;
        depth[p2] += depth[p1];
    }

    // increase depth of p1
    else
    {
        parent[p1] = p2;
        depth[p1] += depth[p2];
    }
}
