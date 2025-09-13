#ifndef __WAPPENHEIM_VECTOR__
#define __WAPPENHEIM_VECTOR__

#include <stddef.h>

#ifndef __WAPPENHEIM_VECTOR__DEFAULT_CAPACITY__
#define __WAPPENHEIM_VECTOR__DEFAULT_CAPACITY__ 128
#endif

typedef struct {
    void *data;
    size_t item_size;
    size_t length;
    size_t capacity;
} WappenheimVector;

WappenheimVector *wappenheim_vector_create(size_t itemsize);
int wappenheim_vector_resize(WappenheimVector *, size_t capacity);
int wappenheim_vector_append(WappenheimVector *, void *data);
int wappenheim_vector_pop(WappenheimVector *, void *data);
int wappenheim_vector_insert(WappenheimVector *, size_t index, void *data);
int wappenheim_vector_get(WappenheimVector *, size_t index, void *data);
int wappenheim_vector_swap(WappenheimVector *, size_t index, size_t index2);
int wappenheim_vector_shift(WappenheimVector *, void *item);
int wappenheim_vector_unshift(WappenheimVector *, void *item);
void wappenheim_vector_destroy(WappenheimVector *);

#endif