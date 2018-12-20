#include "Array.hpp"
#include <cstring>

template <class T>
Array<T>::Array(size_t size) : _size(size) {
    _data = new T[_size];
}

template <class T>
Array<T>::Array(const Array<T>& other) : _size(other._size) {
    _data = new T[_size]; //shallow copy
    memcpy(_data, other._data, sizeof(T) * _size);
}

template <class T>
Array<T>::~Array() {
    delete[] _data;
}

template <class T>
T& Array<T>::operator[] (size_t pos) {
    return _data[pos];
}

template <class T>
const T& Array<T>::operator[]  (size_t pos) const {
    return _data[pos];
}

template class Array<void*>;
