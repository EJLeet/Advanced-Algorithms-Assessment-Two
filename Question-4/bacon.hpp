#ifndef Bacon_h
#define Bacon_h

#include <unordered_map>
#include <vector>
#include <string>

class Bacon
{
    // load structures from file
    std::unordered_map<std::string, 
        std::vector<std::string>> actors, movies;

    struct Vertex
    {/*
        This structure holds info about 
        nodes used in the BFS search.
                                            */
        bool is_actor = false;
        std::string actor;
        std::vector<std::string> path;
        Vertex(bool b, std::string s) : is_actor(b), actor(s) {}
    };

public:
    // constructor
    Bacon(std::string filename);

    // string to identify bacon
    std::string kevin_bacon = "Kevin Bacon (I)";

    // returns bacon number between two actors
    int bacon_number(std::string source, std::string target);

    // finds actor with most bacon
    std::tuple<std::string, int> long_bacon();
};

#endif