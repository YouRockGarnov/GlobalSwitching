#pragma once
#include "../headers/GlobalSwitcher.h"


void* operator new(std::size_t size) noexcept(false) {
	return GlobalSwitcher::get_switcher().Alloc(size);
}

void operator delete(void* ptr) noexcept {
	GlobalSwitcher::get_switcher().Delete(ptr);
}

void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
	void* p = nullptr;
	try {
		p = ::operator new(size);
	} catch (...) {}
	return p;
}

void* operator new[](std::size_t size) noexcept(false) {
	return ::operator new(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
	void* p = nullptr;
	try {
		p = ::operator new[](size);
	} catch (...) {}
	return p;
}

void operator delete(void* ptr, const std::nothrow_t&) noexcept {
	::operator delete(ptr);
}

void operator delete(void* ptr, std::size_t) noexcept {
	::operator delete(ptr);
}

void operator delete[](void* ptr) noexcept {
	::operator delete(ptr);
}

void operator delete[](void* ptr, const std::nothrow_t&) noexcept {
	::operator delete[](ptr);
}

void operator delete[](void* ptr, std::size_t) noexcept {
	::operator delete[](ptr);
}