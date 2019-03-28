#include "vector/vector.h"

#include "assert.h"

static void test_push_single() {
	vector_t vector;
	vector_init(&vector, sizeof(int));

	assert(vector.length == 0);
	int element = 42;
	vector_push(&vector, &element);
	assert(vector.length == 1);
	assert(*(int *) vector_get(&vector, 0) == 42);

	vector_destroy(&vector);
}

static void test_push_multiple() {
	vector_t vector;
	vector_init(&vector, sizeof(size_t));
	assert(vector.length == 0);

	for(size_t i = 0; i < 1000; ++i) {
		vector_push(&vector, &i);
		assert(*(size_t *) vector_get(&vector, i) == i);
	}

	assert(vector.length == 1000);

	vector_destroy(&vector);
}

static void test_delete() {
	vector_t vector;
	vector_init(&vector, sizeof(size_t));

	for(size_t i = 0; i < 1000; ++i) {
		vector_push(&vector, &i);
	}
	assert(vector.length == 1000);
	for(size_t i = 0; i < 500; ++i) {
		vector_delete(&vector, i);
	}

	assert(vector.length == 500);
	for(size_t i = 0; i < 500; ++i) {
		assert(*(size_t *) vector_get(&vector, i) == 2 * i + 1);
	}

	vector_destroy(&vector);

}

int main() {
	test_push_single();
	test_push_multiple();
	test_delete();
}
