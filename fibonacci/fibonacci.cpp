
#include "fibonacci.hpp"

Fibonacci::Fibonacci(uint32_t n)
{
    this->n = n;
}


uint64_t Fibonacci::Calc()
{
    return Calc(n);
}

uint64_t Fibonacci::Calc(uint32_t n)
{
    if (n <= 2) 
        return 1;
    return Calc(n - 1) + Calc(n - 2);
}

FibonacciMemoized::FibonacciMemoized(uint32_t n):Fibonacci(n)
{
    CreateMemo();
}

FibonacciMemoized::~FibonacciMemoized()
{
    delete memo;
}

void FibonacciMemoized::CreateMemo()
{
    memo = new uint64_t[n + 1];
    for(uint32_t i = 0; i <= n; i++)
        memo[i] = 0;
}

uint64_t FibonacciMemoized::Calc(uint32_t n)
{
    if (memo[n] != 0)
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = Calc(n - 1) + Calc(n - 2);
    return memo[n];
}

