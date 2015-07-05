#include <iostream>
#include "numbits.hpp"
using namespace std;


/**
 * the main program
 * it reads in numbers from the console and 
 * prints out how many 1 and 0 bits there are
 */
int main()
{
    int userData = 0;
    while (cin >> userData)
    {
        cout << " number of 1 bits is " <<  num1bits(userData) << endl ;
        cout << "number of 0 bits is " <<  num0bits(userData) << endl;
    }
    return 0;
}
