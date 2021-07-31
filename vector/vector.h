#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <assert.h>

#define vector_type(type) type*

#define CAPACITY_INDEX -2
#define SIZE_INDEX -1
#define BEGIN_INDEX 2

#define vector_set_capacity(vector, capacity) \
    do { \
        if (vector) \
            ((size_t*) (vector))[CAPACITY_INDEX] = capacity; \
    } while (0) \

#define vector_set_size(vector, size) \
    do { \
        if (vector) \
            ((size_t*) (vector))[SIZE_INDEX] = size; \
    } while (0) \

#define vector_get_capacity(vector) \
    ((vector) ? ((size_t*) (vector))[CAPACITY_INDEX] : 0)

#define vector_get_size(vector) \
    ((vector) ? ((size_t*) (vector))[SIZE_INDEX] : 0)

#define vector_empty(vector) \
    (vector_get_size(vector) == 0)

#define vector_new(vector, element_count) \
    do { \
        if (element_count > 0) \
        { \
            vector = NULL; \
            vector_realloc(vector, element_count); \
        } else { \
            vector = NULL; \
        } \
    } while (0)

#define vector_realloc(vector, element_count) \
    do { \
        size_t new_capacity = 2 * sizeof (size_t) + ((size_t) element_count) * sizeof (*(vector)); \
        if ((vector) == NULL) \
        { \
            size_t* ptr = malloc(new_capacity); \
            assert (ptr); \
            (vector) = (void*) &ptr[BEGIN_INDEX]; \
            vector_set_capacity((vector), element_count); \
            vector_set_size((vector), 0); \
        } else { \
            size_t* new_ptr; \
            size_t* ptr = &((size_t*) (vector))[CAPACITY_INDEX]; \
            new_ptr = realloc(ptr, new_capacity); \
            assert (new_ptr); \
            (vector) = (void *) &new_ptr[BEGIN_INDEX]; \
            vector_set_capacity((vector), element_count); \
        } \
    } while (0)

#define vector_push(vector, value) \
    do { \
        size_t capacity = vector_get_capacity(vector); \
        size_t size = vector_get_size(vector); \
        if (size >= capacity) \
        { \
            size_t increment = (size_t) (capacity * 0.5); \
            increment = increment ? increment : 1; \
            vector_realloc((vector), capacity + increment); \
        } \
        (vector)[size] = value; \
        vector_set_size((vector), size + 1); \
    } while (0) \

#define vector_pop(vector) \
    do { \
        if (vector && vector_get_size(vector) > 0) \
            vector_set_size((vector), vector_get_size(vector) - 1); \
    } while (0)

#define vector_begin(vector) \
    (vector)

#define vector_end(vector) \
    ((vector) ? &(vector)[vector_get_size(vector)] : NULL)
    
#define vector_free(vector) \
    do { \
        if (vector) \
        { \
            size_t* ptr = &((size_t*) (vector))[CAPACITY_INDEX]; \
            free(ptr); \
        } \
    } while (0)

// Use this for a vector of pointers
#define vector_free_elements(vector, type) \
    do { \
        if (vector) \
        { \
            type it; \
            for (it = vector_begin(vector); it != vector_end(vector); it++) \
                free(*it); \
        } \
    } while (0)
    
#endif