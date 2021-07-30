#include "grid_traveler.h"
#include <inttypes.h>
#include <stdbool.h>

uint64_t calc_paths(uint32_t rows, uint32_t cols)
{       
    if (rows == 0 || cols == 0) // invalid grid
        return 0;
    if (rows == 1 && cols == 1) // minimun grid
        return 1;    
    return 
        calc_paths(rows, cols - 1) // move right
        + 
        calc_paths(rows - 1, cols); // move down
}

uint64_t calc_paths_memoized(uint32_t rows, uint32_t cols, uint64_t* memo)
{     
    if (memo[cols] != 0)
    {
        return memo[cols];
    }
    if (memo[rows] != 0)
    {
        return memo[rows];
    }
    if (rows == 0 || cols == 0) // invalid grid
        return 0;
    if (rows == 1 && cols == 1) // minimun grid
        return 1;    
    memo[cols] = // since the answer to a grid m x n is the same of m x n just an array of size m is enought to memo the result
        calc_paths(rows, cols - 1) // move right
        + 
        calc_paths(rows - 1, cols); // move down
    return memo[cols];
}