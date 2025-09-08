#include <stdlib.h>
#include "wappenheim/vector.h"

typedef WappenheimVector Vector;

Vector *
wappenheim_vector_create(size_t itemsize)
{
    Vector *vec;

    vec = malloc(sizeof(Vector));
    if (vec == NULL) {
        return NULL;
    }
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

void
wappenheim_vector_destroy(Vector *vec)
{
    free(vec->data);
    free(vec);
}