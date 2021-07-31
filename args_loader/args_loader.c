#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "args_loader.h"

#define DELIMITER " "

uint64_t get_file_size(FILE* file)
{
    uint64_t file_size;
    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return file_size;
}

void load_args(vector_type(char*) args, char* buffer, char* delimiter)
{    
    char* token;   
    char* token_buffer; 
    token = strtok(buffer, delimiter);
    while (token != NULL) 
    {
        token_buffer = malloc(sizeof (char) * (strlen(token) + 1));
        strcpy(token_buffer, token);
        vector_push(args, token_buffer);
        token = strtok(NULL, delimiter);
    }     
}

char* get_arg_at(vector_type(char*) args, int64_t pos)
{
    char* arg = NULL;
    vector_type(char*) it;
    for (it = vector_begin(args); it != vector_end(args) && pos >= 0; it++, pos--)
        arg = *it;   
    return arg;
}

uint64_t convert_to_uint(char* arg)
{
    if (arg != NULL)
        return atoi(arg);
    return 0;
}

void convert_to_uints(vector_type(uint64_t) uints, vector_type(char*) args)
{    
    vector_type(char*) it;
    for (it = vector_begin(args); it != vector_end(args); it++)
        vector_push(uints, convert_to_uint(*it));        
}

void load_args_to_vector(vector_type(char*) vector, char *file_name)
{        
    FILE *file;
    char* buffer;
    uint64_t file_size; 

    file = fopen(file_name, "r");
    assert(file);
    file_size = get_file_size(file);
    buffer = malloc(sizeof (char) * file_size);
    fread(buffer, file_size, sizeof (char), file);   
    fclose(file);   
    load_args(vector, buffer, DELIMITER);
    free(buffer);
}

uint64_t load_uint_at(char* file_name, int64_t pos)
{
    uint64_t ret = 0;
    char* arg;
    vector_type(char*) args;

    vector_new(args, 10);
    load_args_to_vector(args, file_name);
    arg = get_arg_at(args, pos);    
    ret = convert_to_uint(arg);   
    vector_free_elements(args, vector_type(char*));
    vector_free(args);

    return ret;
}

void load_uints(vector_type(uint64_t) uints, char* file_name)
{    
    vector_type(char*) args;   

    vector_new(args, 10);
    load_args_to_vector(args, file_name);    
    convert_to_uints(uints, args); 
    vector_free_elements(args, vector_type(char*));
    vector_free(args);
}
