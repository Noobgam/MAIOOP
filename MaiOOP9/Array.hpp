#ifndef Array_hpp
#define Array_hpp

#include "Array.hpp"
#include "Iterator.h"

template <class T>
class Array {
public:
    Array(size_t size);
    Array(const Array& orig);
                                                
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    virtual ~Array();
private:
    T* _data = nullptr;                 
    size_t _size = 0;
};

#endif /* Array_hpp */
