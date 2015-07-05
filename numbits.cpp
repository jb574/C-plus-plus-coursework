#include "numbits.hpp"
#include <string> 
#include <iostream>
using namespace std;


// simply flip all the bits in the
// parameter and then count the zero bits
unsigned int num0bits(int i)
{
    int numReversedBits = ~i;
    return num1bits(numReversedBits);
}

unsigned int num1bits(int i)
{
    // Convert i to unsigned, because the behaviour of right-shift is
    // implementation-dependent for negative values of signed integer
    // types.  Conversion of plain int to unsigned int is governed by
    // ISO14882:2011 Sec. 4.7 Para 2.
    unsigned int u = i;
    unsigned int ans = 0;
    while (u > 0) {
	ans += (u&1);
	u >>= 1;
    }
    return ans;
}
