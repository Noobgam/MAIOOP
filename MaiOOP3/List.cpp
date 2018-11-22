#include "List.hpp"
#include <stdexcept>

List::List() : first(nullptr) {}

List::List(const List& orig) {
    first = orig.first;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    auto item = list.first;
    while (item != nullptr) {
        os << item->GetFigure()->ToString() << std::endl;
        item = item->GetNext();
    }
    return os;
}

void List::push_front(std::shared_ptr<Figure> &hexagon) {
    auto other = std::make_shared<ListItem>(ListItem(hexagon));
    other->SetNext(first);
    first = other;
}

void List::push_back(std::shared_ptr<Figure> &hexagon) {
    auto other = std::make_shared<ListItem>(ListItem(hexagon));
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

void List::insert(size_t pos, std::shared_ptr<Figure> &hexagon) {
    if (pos != 0) {
        auto item = getItem(pos - 1);
        auto nextItem = item->GetNext();
        auto other = std::make_shared<ListItem>(ListItem(hexagon));
        item->SetNext(other);
        other->SetNext(nextItem);
    } else {
        push_front(hexagon);
    }
}

std::shared_ptr<ListItem> List::getItem(size_t pos) {
    auto iter = this->first;
    for (size_t i = 0; i < pos; i++) {
        iter = iter->GetNext();
        if (iter == nullptr) {
            throw std::out_of_range("Out of range");
        }
    }
    return iter;
}

bool List::empty() {
    return first == nullptr;
}

std::shared_ptr<Figure> List::get(size_t pos) {
    return getItem(pos)->GetFigure();
}

void List::remove(size_t pos) {
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

void List::clear() {
    auto item = first;
    while (item != nullptr) {
        first = first->GetNext();
        item.reset();
        item = first;
    }
}

List::~List() {
    clear();
    std::cout << "List deleted!" << std::endl;
}

