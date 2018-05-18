#pragma once
#include "../headers/StackMemoryManager.h"
#include "../StackAllocator/headers/StackAlloc.h"
#include <iostream>

void* StackMemoryManager::Alloc(size_t size) {
	std::cout << "Stack!!";
	void* ptr = _alloc.allocate(size);
	return ptr;
}

void StackMemoryManager::Delete(void* ptr) {
	//_alloc.deallocate(ptr);
}
