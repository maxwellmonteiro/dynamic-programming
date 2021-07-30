#include <stdio.h>
#include <stdlib.h>
#include "grid_traveler.h"

uint32_t get_arg(int argc, char** argv, int i)
{
    if (argc >= (i + 1))             
        return atoi(argv[i]);    
    return 1;
}

int main(int argc, char** argv)
{    
    uint32_t rows = get_arg(argc, argv, 1);
    uint32_t cols = get_arg(argc, argv, 2);    
    printf("[%"PRIu32", %"PRIu32"] #paths: %"PRIu64"\n", rows, cols, calc_paths(rows, cols));    
}