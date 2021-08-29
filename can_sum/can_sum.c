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

vector_type(bool) create_memo(uint32_t size)
{
    vector_type(bool) memo;
    
    vector_new(memo, size + 1);    
    for (int i = 0; i <= size; i++)
        memo[i] = true;
    return memo;
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

bool memo_find(vector_type(uint64_t) memo, uint64_t target_sum)
{
    vector_type(uint64_t) it;
    
    for (it = vector_begin(memo); it != vector_end(memo); it++)
        if (target_sum == *it)
            return true;

    return false;
}

bool can_sum_memoized_findable(int64_t target_sum, uint64_t* list, uint32_t size, vector_type(uint64_t)* memo)
{   
    if (target_sum > 0 && memo_find(*memo, target_sum))
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
        found = can_sum_memoized_findable(remainder, list, size, memo);
        if (remainder > 0 && !found)
            vector_push(*memo, remainder);
        i++;
    }
    return found;
}