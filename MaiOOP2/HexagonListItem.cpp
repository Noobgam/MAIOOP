#include "HexagonListItem.hpp"

#include <iostream>

HexagonListItem::HexagonListItem(const Hexagon& hexagon) {
    this->hexagon = hexagon;
    this->next = nullptr;
    //std::cout << "List item: created" << std::endl;
}

HexagonListItem::HexagonListItem(const HexagonListItem& orig) {
    this->hexagon = orig.hexagon;
    this->next = orig.next;
    //std::cout << "List item: copied" << std::endl;
}

HexagonListItem* HexagonListItem::SetNext(HexagonListItem* next) {
    HexagonListItem* old = this->next;
    this->next = next;
    return old;
}

Hexagon HexagonListItem::GetHexagon() const {
    return this->hexagon;
}

HexagonListItem* HexagonListItem::GetNext() {
    return this->next;
}

HexagonListItem::~HexagonListItem() {
    //std::cout << "List item: deleted"<< std::endl;
    delete next;
}

std::ostream& operator<<(std::ostream& os, const HexagonListItem& obj) {
    os << "[" << obj.hexagon << "]" << std::endl;
    return os;
}

bool operator==(HexagonListItem & first, HexagonListItem &last){
    return first.hexagon == last.hexagon;
}

