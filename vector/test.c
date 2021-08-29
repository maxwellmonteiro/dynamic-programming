#include <stdio.h>
#include <inttypes.h>
#include "vector.h"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{ 
    vector_type(char) teste;
   /*  vector_new(teste, 10);
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'a');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'b');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'c');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'd');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'x');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'y');    
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'z');    
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));    
    vector_pop(teste);
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_pop(teste);
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    vector_pop(teste);   
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));    
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    vector_push(teste, 'm');    
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste), vector_get_capacity(teste));
    printf("teste: ");
    for (vector_type(char) it = vector_begin(teste); it != vector_end(teste); it++)
        printf("%c ", *it);
    printf("\n"); */

    vector_type(int) teste2;
    vector_new(teste2, 2);
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste2), vector_get_capacity(teste2));
    for (int i = 10000; i >= 0; i--)
        vector_push(teste2, i);
    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste2), vector_get_capacity(teste2));  
    printf("teste2: ");  
    /*for (vector_type(int) it = vector_begin(teste2); it != vector_end(teste2); it++)
        printf("%d ", *it);
    printf("\n");*/

    
    for (int i = 9999; i >= 0; i--)
        vector_pop(teste2);

    printf("teste size: %"PRIu64" capacity: %"PRIu64"\n", vector_get_size(teste2), vector_get_capacity(teste2));  
    printf("teste2: ");  
    for (vector_type(int) it = vector_begin(teste2); it != vector_end(teste2); it++)
        printf("%d ", *it);
    printf("\n");   

    vector_free(teste);
    vector_free(teste2);

    return 0;
}