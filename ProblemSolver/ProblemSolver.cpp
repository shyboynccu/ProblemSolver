#include <iostream>

typedef int (*SOLVE_PROBLEM)(void);
int solve_find_connected_set(void);
int solve_create_equation(void);
int solve_complement(void);
int solve_mincoins(void);

int solve_dummy_problem(void)
{
    //dummy functions for testing purpose
    return 0;
}

int main(int argc, char* argv[])
{
    SOLVE_PROBLEM fp = solve_dummy_problem;
    
    //fp = solve_find_connected_set;
    //fp = solve_create_equation;
    //fp = solve_complement;
    //fp = solve_mincoins;
    fp();

	return 0;
}