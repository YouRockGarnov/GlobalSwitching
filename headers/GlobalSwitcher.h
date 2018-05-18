#pragma once
#include "MemoryManagerSwitcher.h"

class GlobalSwitcher {
public:
	static MemoryManagerSwitcher& get_switcher() {

		static MemoryManagerSwitcher switcher;
		return switcher;
	}
};
