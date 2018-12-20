#include "AllocationBlock.hpp"

#include <iostream>
#include <cstdio>

template <class T>
AllocationBlock<T>::AllocationBlock(size_t count) : _count(count), _free_count(count), _free_blocks(count) {    
//    std::cerr << "Initialized block with " << _count << std::endl;
    _data_storage = (char*)malloc(sizeof(T) * _count);
//    printf("Address of x is %p\n", (void *)_data_storage);  
//    printf("Address of y is %p\n", (void*)(_data_storage + count * sizeof(T)));
    for (size_t i = 0; i < _count; i++)
        _free_blocks[i] = _data_storage + sizeof(T) * i;
}

template <class T>
void* AllocationBlock<T>::allocate() {
    void* result = nullptr;
//    std::cout << "TAllocationBlock: allocate block ";
//    printf("%p\n", (void *)_free_blocks[_free_count - 1]);  
    
    if (_free_count > 0) {
        result = _free_blocks[--_free_count];
    } else {
        throw std::runtime_error("No memory");
    }
    
    return result;
}

template <class T>
void AllocationBlock<T>::deallocate(void* pointer) {
//    std::cout << "TAllocationBlock: Deallocate block "<< std::endl;
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
#include "ListItem.hpp"
template class AllocationBlock<ListItem<Figure>>;
