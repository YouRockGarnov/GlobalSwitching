#pragma once

class MemoryManagerSwitcher;

class IMemoryManager {
public:
	virtual void Delete(void*) = 0;
	virtual void* Alloc(size_t size) = 0;

	IMemoryManager* prev;
};