#include "HexagonList.hpp"
#include <stdexcept>

HexagonList::HexagonList() : first(nullptr) {}

HexagonList::HexagonList(const HexagonList& orig) {
    first = orig.first;
}

std::ostream& operator<<(std::ostream& os, const HexagonList& list) {
    auto item = list.first;
    while (item != nullptr) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

void HexagonList::push_front(Hexagon &&hexagon) {
    auto other = new HexagonListItem(hexagon);
    other->SetNext(first);
    first = other;
}

void HexagonList::push_back(Hexagon &&hexagon) {
    auto other = new HexagonListItem(hexagon);
    auto iter = this->first;
    if (first != nullptr) {
        while (iter->GetNext() != nullptr) {
            iter = iter->SetNext(iter->GetNext());
        }
        iter->SetNext(other);
        other->SetNext(nullptr);
    }
    else {
        first=other;
    }
}

void HexagonList::insert(size_t pos, Hexagon &&hexagon) {
    if (pos != 0) {
        auto item = getItem(pos - 1);
        auto nextItem = item->GetNext();
        auto other = new HexagonListItem(hexagon);
        item->SetNext(other);
        other->SetNext(nextItem);
    } else {
        push_front(std::forward<Hexagon>(hexagon));
    }
}

HexagonListItem* HexagonList::getItem(size_t pos) {
    auto iter = this->first;
    for (size_t i = 0; i < pos; i++) {
        iter = iter->GetNext();
        if (iter == nullptr) {
            throw std::out_of_range("Out of range");
        }
    }
    return iter;
}

bool HexagonList::empty() {
    return first == nullptr;
}

Hexagon HexagonList::get(size_t pos){
    return getItem(pos)->GetHexagon();
}
void HexagonList::remove(size_t pos) {
    if (pos != 0) {
        auto item = getItem(pos - 1);
        auto itemNext = item->GetNext();
        if (itemNext != nullptr) {
            auto itemNextNext = itemNext->GetNext();
            delete itemNext;
            item->SetNext(itemNextNext);
        } else {
            throw std::out_of_range("Out of range");
        }
    } else {
        auto item = first;
        first = first->GetNext();
        delete item;
    }
}

void HexagonList::clear() {
    auto item = first;
    while (item != nullptr) {
        first = first->GetNext();
        delete item;
        item = first;
    }
}

HexagonList::~HexagonList() {
    clear();
    std::cout << "List deleted!" << std::endl;
}

