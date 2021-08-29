#include <iostream>
#include <args_loader.hpp>
#include "fibonacci.hpp"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{
    uint64_t n;   
    ArgsLoader loader(FILE_NAME);

    n = loader.LoadUintAt(0);    
    Fibonacci fibonacci(n);
    cout << "Fibonacci(" << n << "): " << fibonacci.Calc() << endl;

    return 0;
}