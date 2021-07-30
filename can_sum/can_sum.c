#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "can_sum.h"

void print_list(uint64_t* list, int64_t total, uint32_t size)
{    
    char value[21];    
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        itoa(list[i], value, 10);       
        printf("%s ", value); 
    }
    printf("] = %"PRId64"\n", total);
}

bool can_sum(int64_t target_sum, uint64_t* list, uint32_t size)
{                
    if (target_sum == 0)
        return true;
    if (target_sum < 0)
        return false;

    int64_t remainder;
    bool found = false;
    int i = 0;    
    while (i < size && !found)
    {        
        remainder = target_sum - list[i];
        //print_list(list, remainder, size);
        found = can_sum(remainder, list, size);
        i++;
    }
    return found;
}

bool can_sum_memoized(int64_t target_sum, uint64_t* list, uint32_t size, bool* memo)
{   
    if (target_sum > 0 && memo[target_sum] == false)
        return false;
    if (target_sum == 0)
        return true;
    if (target_sum < 0)
        return false;    

    int64_t remainder;
    bool found = false;
    int i = 0;    
    while (i < size && !found)
    {        
        remainder = target_sum - list[i];
        //print_list(list, remainder, size);
        found = can_sum_memoized(remainder, list, size, memo);
        if (remainder > 0)
            memo[remainder] = found;
        i++;
    }
    return found;
}