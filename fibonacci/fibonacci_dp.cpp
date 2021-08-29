#include <iostream>
#include <args_loader.hpp>
#include "fibonacci.hpp"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{
    uint64_t n;   
    ArgsLoader loader(FILE_NAME);

    n = loader.LoadUintAt(0);
    FibonacciMemoized fibonacci(n);
    cout << "Fibonacci Memoized(" << n << "): " << fibonacci.Calc() << endl;

    return 0;
}