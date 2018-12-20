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

    template <class Fig>
    Vector<Fig> FilterType() const;
    size_t GetSize();
    void resize(size_t newSize);
    std::string ToString() const;


    virtual ~Vector();
private:
    T* _data = nullptr;                 
    size_t _size = 0;
    size_t _capacity = 0;
};

template <class T, class Callable>
std::shared_ptr<Vector<T>> FilterFigures(const std::shared_ptr<Vector<T>>& source, Callable callee) {
    std::shared_ptr<Vector<T>> temp{new Vector<T>()};
    for (int i = 0; i < source->GetSize(); ++i) {
        if (callee((*source)[i])) {
            temp->push_back((*source)[i]);
        }
    }
    return temp;
}



#endif /* Array_hpp */
