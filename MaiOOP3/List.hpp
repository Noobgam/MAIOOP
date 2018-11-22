#ifndef List_hpp
#define List_hpp

#include "ListItem.hpp"

class List {
public:
    List();
    List(const List& orig);
    
    void push_front(std::shared_ptr<Figure> &hexagon);
    void push_back(std::shared_ptr<Figure> &hexagon);
    void insert(size_t pos, std::shared_ptr<Figure> &hexagon);
    bool empty();
    std::shared_ptr<Figure> get(size_t pos);
    void remove(size_t pos);
    void clear();
    friend std::ostream& operator<<(std::ostream& os, const List& stack);
    virtual ~List();
private:
    
    std::shared_ptr<ListItem> getItem(size_t pos);
    std::shared_ptr<ListItem> first;
};

#endif /* List_hpp */
