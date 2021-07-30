#include <stdio.h>
#include <stdlib.h>
#include "can_sum.h"

int64_t get_arg(int argc, char** argv, int i)
{
    if (argc >= (i + 1))             
        return atoi(argv[i]);    
    return 1;
}

uint64_t* create_list(int size, char** argv)
{   
    uint64_t* list = NULL;
    if (size > 0)
        list = malloc(sizeof(uint64_t) * size);
    for (int i = 0; i < size; i++)
    {
        list[i] = atoi(argv[i + 2]);        
    }

    return list;
}

int main(int argc, char** argv)
{   
    bool found = false;
    uint32_t size = argc - 2;        
    int64_t target_sum = get_arg(argc, argv, 1);    
    uint64_t* list = create_list(size, argv);    
    if (list != NULL)
        found = can_sum(target_sum, list, size);
    printf("can sum: %s\n", found ? "true" : "false");
    free(list);
}