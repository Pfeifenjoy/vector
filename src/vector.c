#include "vector/vector.h"
#include "vector/memory.h"

#include "assert.h"
#include "string.h"

void vector_init(vector_t *vector, uint16_t element_size) {
	vector->data = callocate(1, element_size);
	vector->element_size = element_size;
	vector->reserved = 0;
	vector->length = 0;
}

void vector_push(vector_t *vector, void *element) {
	vector->length++;
	if(vector->length > 1ul << vector->reserved) {
		vector->reserved++;
		vector->data =
			reallocate(vector->data, 1ul << vector->reserved, vector->element_size);
	}

	memcpy(vector_get(vector, vector->length - 1), element, vector->element_size);
}

void *vector_get(vector_t *vector, size_t i) {
	assert(i < vector->length);
	return vector->data + i * vector->element_size;
}

void vector_delete(vector_t *vector, size_t i) {
	assert(i < vector->length);
	memmove(
		vector_get(vector, i),
		vector->data + vector->element_size * (i + 1),
		(vector->length - i) * vector->element_size
	);

	vector->length--;
	if(vector->length < 1ul << ((uint8_t) (vector->reserved - 1))) {
		vector->reserved--;
		vector->data =
			reallocate(vector->data, 1ul << vector->reserved, vector->element_size);
	}
}

void vector_destroy(vector_t *vector) {
	free(vector->data);
}
