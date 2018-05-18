#include "headers\MemoryManagerSwitcher.h"

void f() {
	int* i = new int;
	delete i;
}