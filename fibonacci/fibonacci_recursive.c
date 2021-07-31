#include <stdio.h>
#include <stdlib.h>
#include <args_loader.h>
#include "fibonacci.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{
    uint64_t n;   
    n = load_uint_at(FILE_NAME, 0);
    printf("Fibonacci(%"PRIu64"): %"PRIu64"\n", n, fibonacci(n));
}