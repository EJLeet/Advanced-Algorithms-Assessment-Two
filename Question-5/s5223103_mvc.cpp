#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

class MVC
{
    // variables used by every algorithm
    int vertices, target, algorithm = -1;
    std::string graph;
/*
    Algorithm: 1 -> Random Local Search
    Algorithm: 2 -> Greedy Local Search
    Algorithm: 3 -> Simmulated Annealing
                                            */
public:
    // constructor initialises class for every algorithm
    MVC(std::string g, int t, int a) : graph(g), target(t), algorithm(a) {}
    
    // public driver to run the algorithms
    void driver();

/****************************************************
*    Next private and public declerations are for   *
*    Random and Greedy Local Search algorithms   *
****************************************************/
private:
    // creates adj_list from file
    std::tuple<std::unordered_map<int, 
            std::set<int>>, int> generate(std::string filename);

    // randomly identifies edges until a cover is found
    std::set<int> ls_minimise_cover(std::unordered_map<int, std::set<int>> adj_list);
    
    // removes edges and their incidents
    void ls_remove_edge(std::unordered_map<int, std::set<int>>& adj_list, int vertex);
   
    // checks if there is valid cover after edge removal
    bool ls_check_cover(std::unordered_map<int, std::set<int>>& adj_list, 
                     std::set<int>& cover, int vertex);

/****************************************************
*    Next private and public declerations are for   *
*        the Simmulated Annealing Algorithm         *
****************************************************/
    
    
};

// uniform random number gen
std::random_device rand_dev;
std::mt19937 generator(rand_dev());

// user choice solver
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
         << "2 \t Greedy Local Search" << endl
         << "3 \t Simmulated Annealing" << endl
         << "What algorithm would you like to run? ";
    
    while (!(cin >> algorithm) || (algorithm < 1) || (algorithm > 3))
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
    
    switch(graph)
    {
        case 1:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_1, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(brock800_1, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_1, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 2:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_2, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(brock800_2, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_2, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }      
        case 3:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_3, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(brock800_3, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_3, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 4:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_4, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(brock800_4, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_4, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 5:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(C2000_9, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(C2000_9, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(C2000_9, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 6:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(C4000_5, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(C4000_5, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(C4000_5, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 7:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(MANN_a45, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(MANN_a45, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(MANN_a45, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 8:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(p_hat1500_1, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC hls(p_hat1500_1, target, 2);
                    hls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(p_hat1500_1, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        default:
        {
            cout << "Invalid Input -> Exiting!" << endl;
            exit(1);
        }
    }

}

std::tuple<std::unordered_map<int, 
           std::set<int>>, int> MVC::generate(std::string filename)
{/*
    Populate the adjacency list with file
                                            */
    std::unordered_map<int, std::set<int>> adj_list;
    std::ifstream file (filename);
    int vertices;
    file >> vertices;
    int v, u;
    while (file >> v >> u)
    {
        adj_list[v].emplace(u);
        adj_list[u].emplace(v);
    }
    return {adj_list, vertices};
}

void MVC::driver()
{/*
    Driver function to perform algorithms trial
    amount of times.
                                                        */

    if (algorithm == 1)
        cout << "Performing Random Local Search on " 
             << graph << ". Please wait...." << endl;
    else if (algorithm == 2)
        cout << "Performing Greedy Local Search on " 
             << graph << ". Please wait...." << endl;
    else
        cout << "Performing Simmulated Annealing on " 
             << graph << ". Please wait...." << endl;

    std::vector<double> trial_time;
    std::vector<int> total_cover;
    int successful = 0;

    // loop for every trial
    for (int i = 0; i < 100; i++) 
    {
        auto start = std::chrono::high_resolution_clock::now(); 

        int current_size = vertices;
        std::set<int> cover;

        // randomised/greedy local search
        if (algorithm == 1 || algorithm == 2)
        {
            // populate adjacency list
            int v;
            std::unordered_map<int, std::set<int>> adj_list;
            std::tie(adj_list, v) = generate(graph);
            vertices = v;

            // get a minimum
            std::set<int> minimise = ls_minimise_cover(adj_list);

            // ensure its a cover
            for (int v = 1; v <= adj_list.size(); v++)
                if (ls_check_cover(adj_list, minimise, v))
                    minimise.erase(v);

            // if size is better than current -> update
            if (minimise.size() < current_size) 
            {
                cover = minimise;
                current_size = minimise.size();
            }
        }

        // simmulated annealing
        else if (algorithm == 3)
        {

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
             << "   CPU Time(sec): " << duration << endl;
        
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
         << "\nBest Cover: " << *std::min_element(total_cover.begin(), total_cover.end())
         << "\nAverage Cover: " << average_cover 
         << "\nAverage Time(sec): " << average_time << endl;

}

std::set<int> MVC::ls_minimise_cover(std::unordered_map<int, std::set<int>> adj_list)
{/*
    Delete random edges in order to find a 
    better cover
                                            */
    std::set<int> cover;
    
    while (!adj_list.empty())
    {
        auto it = adj_list.begin();
        
        // get max degree vertex
        if (algorithm == 2)
        {
            auto it = std::max_element(std::begin(adj_list), std::end(adj_list),
            [] (const std::pair<int, std::set<int>> & p1, 
                const std::pair<int, std::set<int>> & p2) 
            { return p1.second.size() < p2.second.size(); } ); 
        }

        // get a random vertex
        else
        {
            std::uniform_int_distribution<int> gen(0, adj_list.size() - 1);
            int random = gen(generator);
            it = adj_list.begin();
            std::advance(it, random);
        }

        // get a random edge
        std::uniform_int_distribution<int> gen_(0, it->second.size() - 1);
        int random = gen_(generator);
        auto ij = it->second.begin();
        std::advance(ij, random);

        // remove edge
        ls_remove_edge(adj_list, it->first);
        ls_remove_edge(adj_list, *ij);

        // update vertex cover
        cover.emplace(it->first);
        cover.emplace(*ij);
    }
    return cover;
}

void MVC::ls_remove_edge(std::unordered_map<int, 
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

bool MVC::ls_check_cover(std::unordered_map<int, std::set<int>>& adj_list, 
                              std::set<int>& cover, int vertex)
{/*
    Method checks if a vertex cover is present 
    after removing an edge.                         */
    for (auto i : adj_list[vertex])
        if (cover.find(i) == cover.end())
            return false;
    return true;
}