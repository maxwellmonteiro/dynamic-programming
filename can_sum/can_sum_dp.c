#include <stdio.h>
#include <stdlib.h>
#include <args_loader.h>
#include "can_sum.h"

#define FILE_NAME "params.txt"
#define DIRECT_SEARCH

int main(int argc, char** argv)
{               
    int64_t target_sum;
    uint64_t* list;
    uint64_t size;
    vector_type(uint64_t) args;
    #ifdef DIRECT_SEARCH
    vector_type(bool) memo;
    #else
    vector_type(uint64_t) memo;
    #endif

    vector_new(args, 20);
    load_uints(args, FILE_NAME);
    target_sum = args[0];
    list = &args[1];    
    size = vector_get_size(args) - 1;
    #ifdef DIRECT_SEARCH
    memo = create_memo(target_sum);
    printf("can sum: %s\n", can_sum_memoized(target_sum, list, size, memo) ? "true" : "false");
    #else
    vector_new(memo, 100);
    printf("can sum: %s\n", can_sum_memoized_findable(target_sum, list, size, &memo) ? "true" : "false");
    #endif
    vector_free(args);
    vector_free(memo);
    return 0;
}