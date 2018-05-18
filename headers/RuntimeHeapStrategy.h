#pragma once
#include "IAllocStrategy.h"


class RuntimeHeapStrategy{// : public IAllocStrategy {
public:
	static void* Alloc(size_t size); //CHECK
	static void Delete(void* ptr);
};