#pragma once
#include "IAllocStrategy.h"


class CurrentMemoryManagerStrategy {//: public IAllocStrategy {
public:
	static void* Alloc(size_t size);
	static void Delete(void* ptr);
};
