#include <stdio.h>
#include <stdlib.h>
#include <args_loader.h>
#include "fibonacci.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{
    uint64_t n;
    vector_type(uint64_t) memo;

    n = load_uint_at(FILE_NAME, 0);
    memo = create_memo(n);
    printf("Fibonacci(%"PRIu64"): %"PRIu64"\n", n, fibonacci_memoized(n, memo));
    vector_free(memo);
    return 0;
}