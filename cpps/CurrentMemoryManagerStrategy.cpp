//WORKING
#include "../headers/CurrentMemoryManagerStrategy.h"
#include "../headers/GlobalSwitcher.h"
void* CurrentMemoryManagerStrategy::Alloc(size_t size) {
	return GlobalSwitcher::get_switcher().Alloc(size);
}

void CurrentMemoryManagerStrategy::Delete(void* ptr) {
	GlobalSwitcher::get_switcher().Delete(ptr);
}
