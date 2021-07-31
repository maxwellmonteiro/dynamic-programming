#include <stdio.h>

#include "args_loader.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{ 
    vector_type (uint64_t) args;

    vector_new(args, 10);
    load_uints(args, FILE_NAME);
 
    vector_type (uint64_t) it;
    printf("args: ");
    for (it = vector_begin(args); it != vector_end(args); it++)
        printf("%"PRIu64" ", *it);
    printf("\n");
    printf("arg: %"PRIu64"\n", load_uint_at(FILE_NAME, 0));    

    return 0;
}