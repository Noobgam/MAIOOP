#include "Vector.hpp"
#include <cstring>
#include <utility>
#include <memory>
#include <algorithm>
#include <functional>

template <class T>
Vector<T>::Vector(size_t size) : _size(size), _capacity(size) {
    _data = new T[_size];                                    
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) : _size(other._size), _capacity(other._capacity) {
    _data = new T[_capacity]; //shallow copy
    memcpy(_data, other._data, sizeof(T) * _size);
}

template <class T>
void Vector<T>::push_back(const T& data) {
    if (_size == _capacity) {
        resize(2 * _capacity + 1);    
    }
    _data[_size++] = data;
}

template <class T>
void Vector<T>::pop_back() {
    --_size;
}

template <class T>
size_t Vector<T>::GetSize() {
    return _size;
}

template <class T>
void Vector<T>::resize(size_t newSize) {
    T* newData = new T[newSize]();
    for (size_t i = 0; i < newSize && i < _size; ++i) {
        newData[i] = _data[i];
    }
    std::swap(newData, _data);
    _capacity = newSize;
    _size = std::min(_size, newSize);
    delete[] newData;
}

template <class T>
Vector<T>::~Vector() {
    delete[] _data;
}

template <class T>
T& Vector<T>::operator[] (size_t pos) {
    return _data[pos];
}

template <class T>
const T& Vector<T>::operator[]  (size_t pos) const {
    return _data[pos];
}

template class Vector<std::shared_ptr<std::function<void(void)>>>;
