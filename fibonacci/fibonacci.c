#include <stdlib.h>
#include <vector.h>
#include "fibonacci.h"

uint64_t fibonacci(long n)
{
    if (n <= 2) 
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector_type(uint64_t) create_memo(long n)
{
    vector_type(uint64_t) memo;
    
    vector_new(memo, n + 1);
    for(int i = 0; i <= n; i++)
        memo[i] = 0;

    return memo;
}

uint64_t fibonacci_memoized(long n, uint64_t* memo)
{    
    if (memo[n] != 0)
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fibonacci_memoized(n - 1, memo) + fibonacci_memoized(n - 2, memo);
    return memo[n];
}
