#ifndef VECTOR_H_07QQ9GCZ
#define VECTOR_H_07QQ9GCZ

#include "stdlib.h"
#include "stdint.h"

typedef struct {
	void *data;
	size_t length;
	uint8_t reserved;
	uint16_t element_size;
} vector_t;

void vector_init(vector_t *, uint16_t);

void vector_push(vector_t *, void *);
void *vector_get(vector_t *, size_t);
void vector_delete(vector_t *, size_t);

void vector_destroy(vector_t *vector);

#endif /* end of include guard: VECTOR_H_07QQ9GCZ */
