//
//  fibonacci.cpp
//  ProblemSolver
//
//  Copyright (c) 2014 shyboynccu. All rights reserved.
//

#include <iostream>
int fibonacci_dp(int n)
{
    int* fib = new int[n+1];
    int result = 0;
    
    fib[0]=0;
    fib[1]=1; //first fib number
    for (int i=2; i<=n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    result = fib[n];
    delete [] fib;
    
    return result;
}

int fibonacci_iterative(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;
    
    for (int i=2; i<=n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}

int fibonacci_recursive(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int solve_fibonacci(void)
{
    std::cout << fibonacci_dp(15) << "\n";
    std::cout << fibonacci_recursive(15) << "\n";
    std::cout << fibonacci_iterative(15) << "\n";
    return 0;
}