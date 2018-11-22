#include "ListItem.hpp"

#include <iostream>

ListItem::ListItem(const std::shared_ptr<Figure> &figure) {
    this->figure = figure;
    this->next = nullptr;
    //std::cout << "List item: created" << std::endl;
}

ListItem::ListItem(const ListItem& orig) {
    this->figure = orig.figure;
    this->next = orig.next;
    //std::cout << "List item: copied" << std::endl;
}

std::shared_ptr<ListItem> ListItem::SetNext(std::shared_ptr<ListItem> next) {
    std::shared_ptr<ListItem> old = this->next;
    this->next = next;
    return old;
}

std::shared_ptr<Figure> ListItem::GetFigure() const {
    return this->figure;
}

std::shared_ptr<ListItem> ListItem::GetNext() {
    return this->next;
}

ListItem::~ListItem() {
    //std::cout << "List item: deleted"<< std::endl;
}

std::ostream& operator<<(std::ostream& os, const ListItem& obj) {
    os << "[" << obj.figure << "]" << std::endl;
    return os;
}

bool operator==(ListItem & first, ListItem &last){
    return first.figure == last.figure;
}

