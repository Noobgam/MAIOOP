#ifndef AllocationBlock_hpp
#define AllocationBlock_hpp

#include <stdio.h>
#include "Array.hpp"

template <class T>
class AllocationBlock {
public:
    AllocationBlock(size_t count);
    void *allocate();
    void deallocate(void *pointer);
    bool has_free_blocks();
    
    virtual ~AllocationBlock();
private:
    size_t _count;         
    size_t _free_count;
    char* _data_storage;
    Array<void*> _free_blocks;
};

#endif /* AllocationBlock_hpp */
