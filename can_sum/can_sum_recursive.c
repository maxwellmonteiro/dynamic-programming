#include <stdio.h>
#include <stdlib.h>
#include <args_loader.h>
#include "can_sum.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{
    int64_t target_sum;
    uint64_t* list;
    uint64_t size;
    vector_type(uint64_t) args;

    vector_new(args, 20);
    load_uints(args, FILE_NAME);
    target_sum = args[0];
    list = &args[1];
    size = vector_get_size(args) - 1;    
    printf("can sum: %s\n", can_sum(target_sum, list, size) ? "true" : "false");
    vector_free(args);
    return 0;
}