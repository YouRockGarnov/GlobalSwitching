#include "../headers/RuntimeHeapStrategy.h"
#include <cstdlib>

void* RuntimeHeapStrategy::Alloc(size_t size) {

	if (size == 0)
		size = 1;

	return malloc(size);
}

void RuntimeHeapStrategy::Delete(void *ptr) {

	if (ptr)
		free(ptr);
}