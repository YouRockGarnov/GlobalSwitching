#pragma once

template<typename AllocStrategy>
class AllocOn {
public:
    void* operator new(std::size_t size) {
        return AllocStrategy::Alloc(size);
    }

    void operator delete(void* ptr) {
		AllocStrategy::Delete(ptr);
    }
};