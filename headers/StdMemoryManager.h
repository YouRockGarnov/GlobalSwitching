#pragma once
#include "IMemoryManager.h"


class StdMemoryManager : public IMemoryManager {
public:
	void* Alloc(size_t size);
	void Delete(void* ptr);
	~StdMemoryManager() {};
};