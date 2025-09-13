#include <stdlib.h>
#include <string.h>
#include "wappenheim/vector.h"

typedef WappenheimVector Vector;

Vector *
wappenheim_vector_create(size_t itemsize)
{
    Vector *vec;

    vec = malloc(sizeof(Vector));
    if (vec == NULL) return NULL;
    vec->capacity = __WAPPENHEIM_VECTOR__DEFAULT_CAPACITY__;
    vec->data = calloc(itemsize, vec->capacity);
    if (vec->data == NULL) {
        free(vec);
        return NULL;
    }
    vec->item_size = itemsize;
    vec->length = 0;
    return vec;
}

int
wappenheim_vector_resize(Vector *vec, size_t capacity)
{
    void *temp;

    temp = realloc(vec->data, capacity * vec->item_size);
    if (temp == NULL) return -1;
    vec->data = temp;
    if (capacity < vec->length) vec->length = capacity;
    vec->capacity = capacity;
    return 0;
}

int
wappenheim_vector_append(Vector *vec, void *data)
{
    if (
        vec->capacity <= (vec->length + 1) &&
        wappenheim_vector_resize(vec, vec->capacity * 2) != 0
    ) return -1;
    memcpy(
        (void *)((size_t)(vec->data) + vec->length++ * vec->item_size),
        data,
        vec->item_size
    );
    return 0;
}

int
wappenheim_vector_pop(Vector *vec, void *data)
{
    if (vec->length == 0) return -1;
    memcpy(
        data,
        (void *)((size_t)(vec->data) + --vec->length * vec->item_size),
        vec->item_size
    );
    return 0;
}

int
wappenheim_vector_insert(Vector *vec, size_t index, void *data)
{
    if (
        vec->capacity <= (index + 1) &&
        wappenheim_vector_resize(vec, index * 2) != 0
    ) return -1;
    if (vec->length <= index) vec->length = index + 1;
    memcpy(
        (void *)((size_t)(vec->data) + index * vec->item_size),
        data,
        vec->item_size
    );
    return 0;
}

int
wappenheim_vector_get(Vector *vec, size_t index, void *data)
{
    if (vec->length <= index) return -1;
    memcpy(
        data,
        (void *)((size_t)(vec->data) + index * vec->item_size),
        vec->item_size
    );
    return 0;
}

int
wappenheim_vector_swap(WappenheimVector *vec, size_t index, size_t index2)
{
    void *item;

    if (index == index2) return 0;
    if (vec->length <= index || vec->length <= index2) return -1;
    item = malloc(vec->item_size);
    if (item == NULL) return -1;
    memcpy(
        item,
        (void *)((size_t)(vec->data) + index * vec->item_size),
        vec->item_size
    );
    memcpy(
        (void *)((size_t)(vec->data) + index * vec->item_size),
        (void *)((size_t)(vec->data) + index2 * vec->item_size),
        vec->item_size
    );
    memcpy(
        (void *)((size_t)(vec->data) + index2 * vec->item_size),
        item,
        vec->item_size
    );
    free(item);
    return 0;
}

int
wappenheim_vector_shift(Vector *vec, void *item)
{
    if (vec->length == 0) return -1;
    memcpy(
        item,
        vec->data,
        vec->item_size
    );
    memmove(
        vec->data,
        (void *)((size_t)vec->data + vec->item_size),
        vec->capacity * vec->item_size
    );
    --vec->length;
    return 0;
}

int
wappenheim_vector_unshift(Vector *vec, void *item)
{
    if (vec->length == 0) return -1;
    if (
        vec->capacity <= (vec->length + 1) &&
        wappenheim_vector_resize(vec, vec->capacity * 2) != 0
    ) return -1;
    memmove(
        (void *)((size_t)vec->data + vec->item_size),
        vec->data,
        vec->capacity * vec->item_size
    );
    ++vec->length;
    memcpy(
        vec->data,
        item,
        vec->item_size
    );
    return 0;
}

void
wappenheim_vector_destroy(Vector *vec)
{
    free(vec->data);
    free(vec);
}