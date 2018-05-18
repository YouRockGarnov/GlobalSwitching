#pragma once
#include "../StackAllocator/headers/StackAlloc.h"
#include "../headers/IMemoryManager.h"

class StackMemoryManager : public IMemoryManager {
public:
	StackMemoryManager() {};
	void Delete(void*);
	void* Alloc(size_t size);
	~StackMemoryManager() = default;

private:
	StackAlloc<char> _alloc;
};