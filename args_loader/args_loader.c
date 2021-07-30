#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <vector.h>

#include "args_loader.h"

#define BUFFER_SIZE 128

typedef struct buffer_infor
{
    char *buffer;
    size_t capacity;
    size_t size;
} BufferInfo;

BufferInfo *buffer_alloc()
{
    BufferInfo *buffer_info = malloc(sizeof(BufferInfo));
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    assert(buffer);
    buffer_info->buffer = buffer;
    buffer_info->capacity = BUFFER_SIZE;
    buffer_info->size = 0;
    return buffer_info;
}

void buffer_realloc(BufferInfo *buffer_info)
{
    size_t capacity = buffer_info->capacity + BUFFER_SIZE;
    char *buffer = realloc(buffer, sizeof(char) * capacity);
    assert(buffer);
    buffer_info->buffer = buffer;
    buffer_info->capacity = capacity;
}

void buffer_free(BufferInfo *buffer_infor)
{
    free(buffer_infor->buffer);
    free(buffer_infor);
}

void buffer_addc(BufferInfo *buffer_info, char ch)
{
    if (buffer_info->size >= buffer_info->capacity)
        buffer_realloc(buffer_info);
    buffer_info->buffer[buffer_info->size] = ch;
    buffer_info->size++;
}

void load_args(FILE *file, vector_type(char*) args)
{
    unsigned char* buffer;
    uint64_t file_size;
    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    buffer = malloc(sizeof (unsigned char) * file_size);
    fread(buffer, file_size, sizeof (unsigned char), file);   

    char* token;
    char* token_buffer;
    token = strtok(buffer, " ");
    while (token != NULL) 
    {        
        token_buffer = malloc(sizeof(char) * strlen(token));
        strcpy(token_buffer, token);
        vector_push(args, token_buffer);
        token = strtok(NULL, " ");
    } 
    free(buffer);
}

uint64_t load_uint_at(char *file_name, int32_t pos)
{
    uint64_t ret = 0;
    char* arg;
    vector_type(char*) args;
    vector_new(args, 10);
    FILE *file = fopen(file_name, "r");    
    load_args(file, args);
    fclose(file);
    for (vector_type(char*) it = vector_begin(args); it != vector_end(args) && pos >= 0; it++, pos--)
        arg = *it;    
    
    if (arg != NULL)
        ret = atoi(arg);

    for (vector_type(char*) it = vector_begin(args); it != vector_end(args); it++)
        free(*it);

    vector_free(args);

    return ret;
}
