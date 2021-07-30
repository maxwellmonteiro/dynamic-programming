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
    (vector) ? ((size_t*) (vector))[CAPACITY_INDEX] : 0

#define vector_get_size(vector) \
    (vector) ? ((size_t*) (vector))[SIZE_INDEX] : 0

#define vector_empty(vector) \
    (vector_get_size(vector) == 0)

#define vector_new(vector, element_count) \
    do { \
        if (element_count > 0) \
        { \
            size_t new_capacity = 2 * sizeof (size_t) + element_count * sizeof (*(vector)); \
            size_t* ptr = malloc(new_capacity); \
            assert (ptr); \
            (vector) = (void*) &ptr[BEGIN_INDEX]; \
            vector_set_capacity((vector), element_count); \
            vector_set_size((vector), 0); \
        } else { \
            vector = NULL; \
        } \
    } while (0)

#define vector_realloc(vector, element_count) \
    do { \
        size_t new_capacity = 2 * sizeof (size_t) + element_count * sizeof (*(vector)); \
        if ((vector) == NULL) \
        { \
            size_t* ptr = malloc(new_capacity); \
            assert (ptr); \
            (vector) = (void*) &ptr[BEGIN_INDEX]; \
            vector_set_capacity((vector), element_count); \
            vector_set_size((vector), 0); \
        } else { \
            size_t* ptr = &((size_t*) (vector))[SIZE_INDEX]; \
            ptr = realloc(ptr, new_capacity); \
            assert (ptr); \
            (vector) = (void *) &ptr[BEGIN_INDEX]; \
            vector_set_capacity((vector), element_count); \
        } \
    } while (0)

#define vector_push(vector, value) \
    do { \
        size_t capacity = vector_get_capacity(vector); \
        size_t size = vector_get_size(vector); \
        if (size >= capacity) \
            vector_realloc((vector), capacity + 10); \
        (vector)[size] = value; \
        vector_set_size((vector), size + 1); \
    } while (0) \

#define vector_pop(vector) \
    do { \
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
            size_t* ptr = &(((size_t*) (vector))[CAPACITY_INDEX]); \
            free(ptr); \
        } \
    } while (0)
    
#endif