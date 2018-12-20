#include "ListItem.hpp"
#include <iostream>

template <class T>
ListItem<T>::ListItem(const std::shared_ptr<T> &data) {
    this->data = data;
    this->next = nullptr;
    //std::cout << "List item: created" << std::endl;
}

template <class T>
ListItem<T>::ListItem(const ListItem& orig) {
    this->data = orig.data;
    this->next = orig.next;
    //std::cout << "List item: copied" << std::endl;1
}

template <class A>
std::ostream& operator<<(std::ostream& os, const ListItem<A>& obj) {
    os << "[" << obj.data->ToString() << "]" << std::endl;
    return os;
}

template <class A>
bool operator==(ListItem<A>& first, ListItem<A>& last) {
    return first.data == last.data;
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
std::shared_ptr<T> ListItem<T>::GetData() const {
    return this->data;
}

#include "Figures/Figure.h"
#include "Vector.hpp"

template class ListItem<Vector<std::shared_ptr<Figure>>>;
template std::ostream& operator<<(std::ostream &out, const ListItem<Figure> &obj);
