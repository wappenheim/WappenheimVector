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
void wappenheim_vector_destroy(WappenheimVector *);

#endif