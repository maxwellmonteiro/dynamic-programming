#include <stdio.h>
#include <stdlib.h>
#include <args_loader.h>
#include "grid_traveler.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{    
    vector_type (uint64_t) args;

    vector_new(args, 2);
    load_uints(args, FILE_NAME);
    uint32_t rows = (uint32_t) args[0];
    uint32_t cols = (uint32_t) args[1];
    printf("grid traveler(%"PRIu32", %"PRIu32"): %"PRIu64"\n", rows, cols, calc_paths(rows, cols));    
}