#ifndef Vector_hpp
#define Vector_hpp

#include "Iterator.h"
#include <memory>
#include <string>

template <class T>
class Vector {
public:
    Vector(size_t size = 0);
    Vector(const Vector& orig);
                                                
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;
    void push_back(const T& data);
    void pop_back();

    size_t GetSize();
    void resize(size_t newSize);

    virtual ~Vector();
private:
    T* _data = nullptr;                 
    size_t _size = 0;
    size_t _capacity = 0;
};

#endif /* Array_hpp */
