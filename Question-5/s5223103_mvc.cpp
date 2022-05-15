#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

class RandomLocalSearch
{
    int vertices, target;
    std::string graph;

    // creates adj_list from file
    std::unordered_map<int, std::set<int>> generate(std::string filename);
    
    // randomly identifies edges until a cover is found
    std::set<int> minimise_cover(std::unordered_map<int, std::set<int>> adj_list);
    
    // removes edges and their incidents
    void remove_edge(std::unordered_map<int, std::set<int>>& adj_list, int vertex);
   
    // checks if there is valid cover after edge removal
    bool check_cover(std::unordered_map<int, std::set<int>>& adj_list, 
                     std::set<int>& cover, int vertex);

public:
    // constructor takes graph and target
    RandomLocalSearch(std::string g, int t) : graph(g), target(t) {}
    
    // public driver to run the rls aglrithm
    void driver();
};

// uniform random number gen
std::random_device rand_dev;
std::mt19937 generator(rand_dev());

void solve_choice(int graph, int algorithm, int target);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Expected Target Minimum Vertex Cover" << endl;
        exit(1);
    }

    int graph, algorithm;

    cout << "**********************************" << endl
         << "**     Minimum Vertex Cover     **" << endl
         << "**          Ethan Leet          **" << endl
         << "**********************************" << endl << endl
         << "Available Graphs: " << endl
         << "1 \tbrock800_1.clq" << endl
         << "2 \tbrock800_2.clq" << endl
         << "3 \tbrock800_3.clq" << endl
         << "4 \tbrock800_4.clq" << endl
         << "5 \tC2000.9.clq" << endl
         << "6 \tC4000.5.clq" << endl
         << "7 \tMANN_a45.clq" << endl
         << "8 \tp_hat1500-1.clq" << endl
         << "What graph would you like to run? ";
    

    while (!(cin >> graph) || (graph < 1) || (graph > 8))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Enter A Valid Number: ";
    }

    cout << "\nAvailable Algorithms: " << endl
         << "1 \t Randomised Local Search" << endl
         << "What algorithm would you like to run? ";
    
    while (!(cin >> algorithm) || (algorithm < 1) || (algorithm > 1))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Enter A Valid Number: ";
    }

    solve_choice(graph, algorithm, atoi(argv[1]));

    return 0;
}

void solve_choice(int graph, int algorithm, int target)
{/*
    Function will execute appropriate algorithm
    and graph based on user choice.
                                                */
    
    std::string brock800_1 = "brock800_1.clq",
                brock800_2 = "brock800_2.clq",
                brock800_3 = "brock800_3.clq",
                brock800_4 = "brock800_4.clq",
                C2000_9 = "C2000.9.clq",
                C4000_5 = "C4000.5.clq",
                MANN_a45 = "MANN_a45.clq",
                p_hat1500_1 = "p_hat1500-1.clq";
    
    if (graph == 1)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(brock800_1, target);
            rls.driver();
        }
    }

    else if (graph == 2)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(brock800_2, target);
            rls.driver();
        }
    }

    else if (graph == 3)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(brock800_3, target);
            rls.driver();
        }
    }

    else if (graph == 4)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(brock800_4, target);
            rls.driver();
        }
    }

    else if (graph == 5)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(C2000_9, target);
            rls.driver();
        }
    }

    else if (graph == 6)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(C4000_5, target);
            rls.driver();
        }
    }

    else if (graph == 7)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(MANN_a45, target);
            rls.driver();
        }
    }

    else if (graph == 8)
    {
        if (algorithm == 1)
        {
            RandomLocalSearch rls(p_hat1500_1, target);
            rls.driver();
        }
    }

    else
    {
        cout << "Invalid Input -> Exiting!" << endl;
        exit(1);
    }

}

void RandomLocalSearch::driver()
{/*
    Driver function to perform random local search.
                                                    */
    // populate adjacency list
    std::unordered_map<int, std::set<int>> adj_list = generate(graph);

    std::vector<double> trial_time;
    std::vector<int> total_cover;
    int successful = 0;

    // loop for every trial
    for (int i = 0; i < 100; i++) 
    {
        auto start = std::chrono::high_resolution_clock::now(); 

        int current_size = vertices;
        std::set<int> cover;

        // get a minimum
        std::set<int> minimise = minimise_cover(adj_list);

        // ensure its a cover
        for (int v = 1; v <= adj_list.size(); v++)
            if (check_cover(adj_list, minimise, v))
                minimise.erase(v);

        // if size is better than current -> update
        if (minimise.size() < current_size) 
        {
            cover = minimise;
            current_size = minimise.size();
        }

        // get trial time
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast
                        <std::chrono::milliseconds> (stop - start).count() / 1000.;

        // add times to accumulate for every trial
        trial_time.push_back(duration);
        total_cover.push_back(cover.size());

        // report trial statistics
        cout << "Trial " << i + 1 << "   Cover: " << cover.size() 
             << "   CPU TIme(ms): " << duration << endl;
        
        if (cover.size() <= target)
            successful++;
    }

    // get averages across all trials
    auto average_time = std::accumulate(trial_time.begin(), trial_time.end(), 0.) 
                        / trial_time.size();
    auto average_cover = std::accumulate(total_cover.begin(), total_cover.end(), 0.0) 
                        / total_cover.size();

    // report average statistics
    cout << "\nGraph: "<< graph << "\nMinimum Vertex Cover Target: " 
         << target << "\nSuccessful Trials: " << successful 
         << "\nAverage Cover: " << average_cover 
         << "\nAverage Time(ms): " << average_time << endl;

}

std::unordered_map<int, std::set<int>> RandomLocalSearch::generate(std::string filename)
{/*
    Populate the adjacency list with file
                                            */
    std::unordered_map<int, std::set<int>> adj_list;
    std::ifstream file (filename);
    file >> vertices;
    int v, u;
    while (file >> v >> u)
    {
        adj_list[v].emplace(u);
        adj_list[u].emplace(v);
    }
    return adj_list;
}

std::set<int> RandomLocalSearch::minimise_cover(std::unordered_map<int, 
                                                std::set<int>> adj_list)
{/*
    Delete random edges in order to find a 
    better cover
                                            */
    std::set<int> cover;

    while (!adj_list.empty())
    {
        // get a random vertex
        std::uniform_int_distribution<int> gen(0, adj_list.size() - 1);
        int random = gen(generator);
        auto it = adj_list.begin();
        std::advance(it, random);

        // get a random edge
        std::uniform_int_distribution<int> gen_(0, it->second.size() - 1);
        random = gen_(generator);
        auto ij = it->second.begin();
        std::advance(ij, random);

        // remove edge
        remove_edge(adj_list, it->first);
        remove_edge(adj_list, *ij);

        // update vertex cover
        cover.emplace(it->first);
        cover.emplace(*ij);
    }
    return cover;
}

void RandomLocalSearch::remove_edge(std::unordered_map<int, 
                                    std::set<int>>& adj_list, int vertex)
{/*
    Remove all edges that are incident on some vertex.
    Also remove any empty vertices that are present.
                                                        */
    std::set<int> empty;

    for (auto& i : adj_list)
    {
        i.second.erase(vertex);

        if (i.second.empty())
            empty.emplace(i.first);
    }

    for (int i : empty)
        adj_list.erase(i);

    adj_list.erase(vertex);

}

bool RandomLocalSearch::check_cover(std::unordered_map<int, std::set<int>>& adj_list, 
                                    std::set<int>& cover, int vertex)
{/*
    Method checks if a vertex cover is present 
    after removing an edge.                         */
    for (auto i : adj_list[vertex])
        if (cover.find(i) == cover.end())
            return false;
    return true;
}