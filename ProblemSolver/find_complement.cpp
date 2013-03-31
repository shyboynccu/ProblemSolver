
#include <iostream>

using namespace std;
int getIntegerComplement(int n) {
    unsigned int mask = 1;
    
    int int_len = sizeof(int)*4;
    mask <<= (int_len - 1);
    
    for (int i = 32; i > 0;i--)
    {
        if (n & mask)
        {
            break;
        }
        else
        {
            mask >>= 1;
        }
    }
    
    return ~n & ((mask << 1) - 1);
}

int solve_complement(void)
{
    unsigned int n = 100;
    int comp;
    comp = getIntegerComplement(n);
    printf("%u", (unsigned int)comp);
    
    return 0;
}