#include "vector/memory.h"

#include "errno.h"
#include "stdio.h"
#include "string.h"

void *mallocate(size_t amount, size_t size) {
	void *result = malloc(amount * size);
	if(result == NULL && errno != 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	return result;
}

void *callocate(size_t amount, size_t size) {
	void *result = mallocate(amount, size);
	memset(result, 0, amount * size);
	return result;
}

void *reallocate(void *data, size_t amount, size_t size) {
	void *result = realloc(data, amount * size);
	if(result == NULL && errno != 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	return result;
}
