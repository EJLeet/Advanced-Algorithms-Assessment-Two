#include "bacon.hpp"
#include <iostream>
#include <chrono>

using std::cout;
using std::endl;

int main()
{
    std::string b1 = "Bacon1.txt", b2 = "Bacon2.txt", b3 = "Bacon3.txt";
    /*
        Testing Bacon 1
                            */
    cout << endl;
    auto start = std::chrono::high_resolution_clock::now();                       
    cout << "Testing " << b1 <<  endl;
    Bacon bacon1(b1);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast
                    <std::chrono::milliseconds> (stop - start).count();
    cout << b1 << " took " << duration << "ms to load" << endl;

    // find an actors bacon number
    start = std::chrono::high_resolution_clock::now(); 
    std::string actor = "Dinah Shore";

    int distance = bacon1.bacon_distance(actor, bacon1.kevin_bacon);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                <std::chrono::milliseconds> (stop - start).count();

    distance == -1 ? cout << "No Solution! " << endl :
                     cout << actor << " has a bacon number of " 
                     << distance << " and took " << duration << "ms" << endl;

    // find longest bacon number
    start = std::chrono::high_resolution_clock::now(); 
    std::string result;
    int res;
    std::tie(result, res) = bacon1.long_bacon();

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                <std::chrono::milliseconds> (stop - start).count();

    cout << result << " has the longest Bacon number of " 
         << res << " and took " << duration << "ms" << endl;
    cout << endl;

    /*
        Testing Bacon 2
                            */

    start = std::chrono::high_resolution_clock::now();                       
    cout << "Testing " << b2 <<  endl;
    Bacon bacon2(b2);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::milliseconds> (stop - start).count();
    cout << b2 << " took " << duration << "ms to load" << endl;

    // find an actors bacon number
    start = std::chrono::high_resolution_clock::now(); 
    actor = "Ernest Abuba";

    distance = bacon2.bacon_distance(actor, bacon2.kevin_bacon);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                <std::chrono::milliseconds> (stop - start).count();

    distance == -1 ? cout << "No Solution! " << endl :
                     cout << actor << " has a bacon number of " 
                     << distance << " and took " << duration << "ms" << endl;

    // find longest bacon number
    start = std::chrono::high_resolution_clock::now(); 
    std::tie(result, res) = bacon2.long_bacon();

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                <std::chrono::milliseconds> (stop - start).count();

    cout << result << " has the longest Bacon number of " 
         << res << " and took " << duration << "ms" << endl;
    cout << endl;

    /*
        Testing Bacon 3
                            */

    start = std::chrono::high_resolution_clock::now();                       
    cout << "Testing " << b3 <<  endl;
    Bacon bacon3(b3);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                    <std::chrono::milliseconds> (stop - start).count();
    cout << b3 << " took " << duration << "ms to load" << endl;
    
    // find links between two actors
    start = std::chrono::high_resolution_clock::now();
    std::string actor2 = "Grandon Rhodes";
    std::string actor3 = "John Vosburgh";

    distance = bacon3.bacon_distance(actor2, actor3);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast
                <std::chrono::milliseconds> (stop - start).count();

    distance == -1 ? cout << "No Solution! " << endl :
                     cout << actor2 << " has a link of " << distance << 
                     " with " << actor3 << " and took " << duration << "ms" << endl;
    cout << endl;
    
    return 0;
}