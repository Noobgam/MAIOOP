#include "AllocationBlock.hpp"

#include <iostream>

template <class T>
AllocationBlock<T>::AllocationBlock(size_t count) : _free_blocks(count), _free_count(_count) {    
    std::cerr << "Initialized block with " << _count << std::endl;
    _data_storage = (char*)malloc(sizeof(T) * _count);
    for (size_t i = 0; i < _count; i++)
        _free_blocks[i] = _data_storage + sizeof(T) * i;
}

template <class T>
void* AllocationBlock<T>::allocate() {
    void* result = nullptr;
    std::cout << "TAllocationBlock: allocate block "<< reinterpret_cast<size_t>(_free_blocks[_free_count - 1]) << std::endl;
    
    if (_free_count > 0) {
        result = _free_blocks[--_free_count];
    } else {
        throw std::runtime_error("No memory");
    }
    
    return result;
}

template <class T>
void AllocationBlock<T>::deallocate(void* pointer) {
    std::cout << "TAllocationBlock: Deallocate block "<< std::endl;
    _free_blocks[_free_count] = pointer;
    _free_count ++;
}

template <class T>
bool AllocationBlock<T>::has_free_blocks() {
    return _free_count > 0;
}

template <class T>
AllocationBlock<T>::~AllocationBlock() {}

#include "Figures/Figure.h"
template class AllocationBlock<Figure>;
