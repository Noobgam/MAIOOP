#include "List.hpp"
#include <stdexcept>

template <class T>
List<T>::List() : first(nullptr) {}

template <class T>
List<T>::List(const List& orig) {
    first = orig.first;
}

template <class T>
void List<T>::sort_sequential() {
    if (empty()) {
        return;
    }
	std::shared_ptr<T> mid = get(0);
	remove(0);
	List<T> l, r;
	while (!empty()) {
		std::shared_ptr<T> temp = get(0);
		remove(0);
		if (temp->Square() > mid->Square()) {
			r.push_back(temp);
		} else {
            l.push_back(temp);
        }
	}

    l.sort_sequential();
    r.sort_sequential();
    while (!l.empty()) {
        push_back(l.get(0));
        l.remove(0);
    }
    push_back(mid);
    while (!r.empty()) {
        push_back(r.get(0));
        r.remove(0);
    }
}

template <class T>
void List<T>::sort_concurrent() {
    if (empty()) {
        return;
    }
	std::shared_ptr<T> mid = get(0);
	remove(0);
	List<T> l, r;
	while (!empty()) {
		std::shared_ptr<T> temp = get(0);
		remove(0);
		if (temp->Square() > mid->Square()) {
			r.push_back(temp);
		} else {
            l.push_back(temp);
        }
	}
    
    std::future<void> sort_left =  std::async([&l](){l.sort_concurrent();});
    std::future<void> sort_right = std::async([&r](){r.sort_concurrent();});

    while (!l.empty()) {
        push_back(l.get(0));
        l.remove(0);
    }
    push_back(mid);
    while (!r.empty()) {
        push_back(r.get(0));
        r.remove(0);
    }
}

template <class T>
void List<T>::push_front(const std::shared_ptr<T> &hexagon) {
    auto other = std::shared_ptr<ListItem<T>>(new ListItem<T>(hexagon));
//    auto other = std::make_shared<ListItem<T>>(ListItem<T>(hexagon));
    other->SetNext(first);
    first = other;
}

template <class T>
void List<T>::push_back(const std::shared_ptr<T> &hexagon) {
    auto other = std::shared_ptr<ListItem<T>>(new ListItem<T>(hexagon));
//    auto other = std::make_shared<ListItem<T>>(ListItem<T>(hexagon));
    auto iter = this->first;
    if (first != nullptr) {
        while (iter->GetNext() != nullptr) {
            iter = iter->SetNext(iter->GetNext());
        }
        iter->SetNext(other);
        other->SetNext(nullptr);
    }
    else {
        first = other;
    }
}

template <class T>
void List<T>::insert(size_t pos, std::shared_ptr<T> &hexagon) {
    if (pos != 0) {
        auto item = getItem(pos - 1);
        auto nextItem = item->GetNext();
        auto other = std::make_shared<ListItem<T>>(ListItem<T>(hexagon));
        item->SetNext(other);
        other->SetNext(nextItem);
    } else {
        push_front(hexagon);
    }
}

template <class T>
bool List<T>::empty() {
    return first == nullptr;
}

template <class T>
std::shared_ptr<T> List<T>::get(size_t pos) {
    return getItem(pos)->GetFigure();
}

template <class T>
void List<T>::remove(size_t pos) {
    if (pos != 0) {
        auto item = getItem(pos - 1);
        auto itemNext = item->GetNext();
        if (itemNext != nullptr) {
            auto itemNextNext = itemNext->GetNext();
            item->SetNext(itemNextNext);
        } else {
            throw std::out_of_range("Out of range");
        }
    } else {
        auto item = first;
        first = first->GetNext();
    }
}

template <class T>
void List<T>::clear() {
    auto item = first;
    while (item != nullptr) {
        first = first->GetNext();
        item.reset();
        item = first;
    }
}

template <class A>
std::ostream& operator<<(std::ostream& os, const List<A>& list) {
    auto item = list.first;
    while (item != nullptr) {
        os << item->GetFigure()->ToString() << std::endl;
        item = item->GetNext();
    }
    return os;
}

template <class T>
List<T>::~List() {
    clear();
    std::cout << "List deleted!" << std::endl;
}

template <class T>
std::shared_ptr<ListItem<T>> List<T>::getItem(size_t pos) {
    auto iter = this->first;
    for (size_t i = 0; i < pos; i++) {
        iter = iter->GetNext();
        if (iter == nullptr) {
            throw std::out_of_range("Out of range");
        }
    }
    return iter;
}

template <class T>
Iterator<ListItem<T>, T> List<T>::begin() {
    return Iterator<ListItem<T>, T>(first);
}

template <class T>
Iterator<ListItem<T>, T> List<T>::end() {
    return Iterator<ListItem<T>, T>(nullptr);
}

#include "Figures/Figure.h"
template class List<Figure>;
template std::ostream& operator<<(std::ostream &out, const List<Figure> &obj);
