#ifndef List_hpp
#define List_hpp

#include "ListItem.hpp"

template <class T>
class List {
public:
    List();
    List(const List& orig);
    
    void push_front(std::shared_ptr<T> &hexagon);
    void push_back(std::shared_ptr<T> &hexagon);
    void insert(size_t pos, std::shared_ptr<T> &hexagon);
    bool empty();
    std::shared_ptr<T> get(size_t pos);
    void remove(size_t pos);
    void clear();
    
    template <class A> friend std::ostream& operator<<(std::ostream& os, const List<A>& list);

    virtual ~List();

private:
    std::shared_ptr<ListItem<T>> getItem(size_t pos);
    
    std::shared_ptr<ListItem<T>> first;
};

#endif /* List_hpp */
