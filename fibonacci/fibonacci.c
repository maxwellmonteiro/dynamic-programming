#include "fibonacci.h"
#include <stdlib.h>

uint64_t fibonacci(long n)
{
    if (n <= 2) 
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

uint64_t* create_memo(long n)
{
    uint64_t* memo = malloc(sizeof(uint64_t) * (n + 1));

    for(int i = 0; i <= n; i++)
        memo[i] = 0;

    return memo;
}

void destroy_memo(uint64_t* memo)
{
    free(memo);
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
