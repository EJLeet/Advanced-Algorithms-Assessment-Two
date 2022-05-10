#include "bacon.hpp"
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_set>

Bacon::Bacon(std::string filename)
{/*
    This function loads the text files(s) and 
    creates hash tables for movies and actors.  
    The key is the movie or actor and the value
    either the list of movies they appeared in
    or the list of actors who were in that movie.
                                                    */               
    std::ifstream bacon1 (filename);
    std::string actor, movie;

    while (bacon1)
    {
        std::getline(bacon1, actor, '|');
        std::getline(bacon1, movie, '\n');
        movies[movie].push_back(actor);
        actors[actor].push_back(movie);
    }
    bacon1.close();
}

int Bacon::bacon_distance(std::string source, std::string target)
{/*
    This method performs a standard BFS on 
    actors and movies. It starts at the actor
    passed to the method and will traverse actors
    and movies until a link to Bacon is found.
                                                    */
    // initialise start node as source
    Vertex start = Vertex(source);

    // initialise node to reassign
    Vertex node = start;

    // initialise queue of vertices
    std::queue<Vertex> graph;
    graph.emplace(start);

    // visited nodes (actors or movies)
    std::unordered_set<std::string> visited;
    visited.insert(source);
    
    while (!graph.empty())
    {
        // get current node
        auto current = graph.front();
        graph.pop();

        // its an actor
        if (actors.find(current.actor) != actors.end())
        {
            // traverse actors movies
            for (auto movie : actors[current.actor])
            {
                // if not visited update nodes
                if (visited.find(movie) == visited.end())
                {
                    node = Vertex(movie);
                    node.path = current.path;
                    node.path.push_back(current.actor);
                    visited.emplace(movie);
                    graph.emplace(node);
                }
            }
        }

        // its a movie
        else
        {
            // traverse actors in movie
            for (auto actor : movies[current.actor])
            {
                // if not visited update nodes
                if (visited.find(actor) == visited.end())
                {
                    node = Vertex(actor);
                    node.path = current.path;
                    node.path.push_back(current.actor);

                    // goal check
                    if (actor == target)
                    {
                        node.path.push_back(actor);
                        return node.path.size() / 2;
                    }

                    visited.emplace(actor);
                    graph.emplace(node);
                }
            }
        }
    }
    return -1;
}

std::tuple<std::string, int> Bacon::long_bacon()
{/*
    This method performs an exhaustive BFS.
    It then returns the nodes actor with the
    longest path.
                                                */
    // initialise start node as source
    Vertex start = Vertex(kevin_bacon);

    // initialise node to reassign
    Vertex node = start;

    // initialise queue of vertices
    std::queue<Vertex> graph;
    graph.emplace(start);

    // visited nodes (actors or movies)
    std::unordered_set<std::string> visited;
    visited.insert(kevin_bacon);
    
    while (!graph.empty())
    {
        // get current node
        auto current = graph.front();
        graph.pop();

        // its an actor
        if (actors.find(current.actor) != actors.end())
        {
            // traverse actors movies
            for (auto movie : actors[current.actor])
            {
                // if not visited update nodes
                if (visited.find(movie) == visited.end())
                {
                    node = Vertex(movie);
                    node.path = current.path;
                    node.path.push_back(current.actor);
                    visited.emplace(movie);
                    graph.emplace(node);
                }
            }
        }

        // its a movie
        else
        {
            // traverse actors in movie
            for (auto actor : movies[current.actor])
            {
                // if not visited update nodes
                if (visited.find(actor) == visited.end())
                {
                    node = Vertex(actor);
                    node.path = current.path;
                    node.path.push_back(current.actor);
                    visited.emplace(actor);
                    graph.emplace(node);
                }
            }
        }
    }
    return { node.actor, node.path.size() / 2 };
}