#pragma once
#include <stack>
#include "IMemoryManager.h"
#include "StdMemoryManager.h"

//bool STD_NEW_DELETE = true;

class MemoryManagerSwitcher {
public:
	MemoryManagerSwitcher() : recManager(new(malloc(sizeof(StdMemoryManager))) StdMemoryManager()) {};
	MemoryManagerSwitcher(const MemoryManagerSwitcher&) = delete;
	MemoryManagerSwitcher&  operator=(const MemoryManagerSwitcher&) = delete;
	~MemoryManagerSwitcher() {
		while (recManager != nullptr) {
			IMemoryManager* prev = recManager->prev;
			delete recManager;
			recManager = prev;
		}
	};

	void pushManager(IMemoryManager*);
	void popManager();
	void* Alloc(size_t);
	void Delete(void*) noexcept;

private:
	IMemoryManager* recManager;
};

/*void* operator new(std::size_t size) noexcept(false);
void operator delete(void* ptr) noexcept;
void* operator new(std::size_t size) noexcept;
void* operator new[](std::size_t size) noexcept(false);
void* operator new[](std::size_t size) noexcept;
void operator delete(void* ptr) noexcept;
void operator delete(void* ptr, std::size_t) noexcept;
void operator delete[](void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;
void operator delete[](void* ptr, std::size_t) noexcept;*/