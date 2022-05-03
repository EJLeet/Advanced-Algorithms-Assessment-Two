#include <fstream>

int main()
{
    std::ofstream out;
    out.open("100_10000.txt");

    std::srand(time(NULL));

    // initialise k
    out << 100 << std::endl;

    // get 10k random numbers up to length of long
    for(int i = 0; i < 10000; i++)
        out << rand() % LONG_MAX << std::endl;

    return 0;
}