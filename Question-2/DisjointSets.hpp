#ifndef DisjointSets_h
#define DisjointSets_h

#include <vector>

class DisjointSets
{
    // initialise parent nodes and their depths (ranks)
    std::vector<int> parent, depth;

    // total nodes present
    int nodes = 0;

public:

    // constructor
    DisjointSets(int size);

    // performs path compression and returns node
    int find(int node);

    // performs set unionisation
    void union_set(int u1, int u2);
};

#endif
