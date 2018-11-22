#include "ListItem.hpp"
#include <iostream>

template <class T>
ListItem<T>::ListItem(const std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->next = nullptr;
    //std::cout << "List item: created" << std::endl;
}

template <class T>
ListItem<T>::ListItem(const ListItem& orig) {
    this->figure = orig.figure;
    this->next = orig.next;
    //std::cout << "List item: copied" << std::endl;1
}

template <class A>
std::ostream& operator<<(std::ostream& os, const ListItem<A>& obj) {
    os << "[" << obj.figure->ToString() << "]" << std::endl;
    return os;
}

template <class A>
bool operator==(ListItem<A>& first, ListItem<A>& last) {
    return first.figure == last.figure;
}

template <class T>
std::shared_ptr<ListItem<T>> ListItem<T>::SetNext(std::shared_ptr<ListItem<T>> next) {
    std::shared_ptr<ListItem> old = this->next;
    this->next = next;
    return old;
}

template <class T>
std::shared_ptr<ListItem<T>> ListItem<T>::GetNext() {
    return this->next;
}

template <class T>
std::shared_ptr<T> ListItem<T>::GetFigure() const {
    return this->figure;
}

template <class T> 
AllocationBlock<ListItem<T>> ListItem<T>::allocator = AllocationBlock<ListItem<T>>(100);

template <class T>
void* ListItem<T>::operator new(size_t size) {
    std::cerr << size << " " << sizeof(T) << std::endl;
    return allocator.allocate();
}

template <class T>
void ListItem<T>::operator delete(void *ptr) {
    allocator.deallocate(ptr);
}


#include "Figures/Figure.h"
template class ListItem<Figure>;
template std::ostream& operator<<(std::ostream &out, const ListItem<Figure> &obj);
