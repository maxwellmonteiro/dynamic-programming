#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

long get_arg(int argc, char** argv)
{
    if (argc >= 1) 
        return atoi(argv[1]);
    return 1;
}

int main(int argc, char** argv)
{
    long n = get_arg(argc, argv);    
    printf("Fibonacci: %"PRIu64"\n", fibonacci(n));
}