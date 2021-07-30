#include <stdio.h>

#include "args_loader.h"

int main()
{
    uint64_t arg;   

    printf("arg: %"PRIu64"\n", load_uint_at("parametros.txt", 0));
    printf("arg: %"PRIu64"\n", load_uint_at("parametros.txt", 1));
    printf("arg: %"PRIu64"\n", load_uint_at("parametros.txt", 2));
    printf("arg: %"PRIu64"\n", load_uint_at("parametros.txt", 3));
    printf("arg: %"PRIu64"\n", load_uint_at("parametros.txt", 4));

    return 0;
}