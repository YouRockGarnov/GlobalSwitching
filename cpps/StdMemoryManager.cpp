#pragma once
#include "../headers/StdMemoryManager.h"
#include <cstdlib>
#include <iostream>

void* StdMemoryManager::Alloc(std::size_t size) {
	std::cout << "Alloc";

	if (size == 0)
		size = 1;

	return malloc(size);
}

void StdMemoryManager::Delete(void* ptr) {
	if(ptr)
		free(ptr);
}
