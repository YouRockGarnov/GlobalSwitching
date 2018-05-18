#include <stack>
#include "../headers/MemoryManagerSwitcher.h"
#include "../headers/StdMemoryManager.h"
#include "../headers/IMemoryManager.h"
//#include "../cpps/stdOperators.cpp"

void MemoryManagerSwitcher::pushManager(IMemoryManager* man) {
	man->prev = recManager;
	recManager = man;
}

void MemoryManagerSwitcher::popManager() {
	if (recManager)
		recManager = recManager->prev;
}

void* MemoryManagerSwitcher::Alloc(size_t size) {
	if (recManager == nullptr) {
		recManager = new(malloc(sizeof(StdMemoryManager))) StdMemoryManager();
	}
	char* ptr = static_cast<char*>(recManager->Alloc(size + sizeof(IMemoryManager*)));
	new(ptr) IMemoryManager*(recManager);
	return ptr + sizeof(IMemoryManager*);
}

void MemoryManagerSwitcher::Delete(void *ptr) noexcept {
	auto managerPtr = static_cast<IMemoryManager**>(ptr) - 1;
	(*managerPtr)->Delete(static_cast<void*>(managerPtr));
}