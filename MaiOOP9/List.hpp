#ifndef List_hpp
#define List_hpp

#include "ListItem.hpp"
#include "Iterator.h"
#include <future>

template <class T>
class List {
public:
    List();
    List(const List& orig);
    
    void push_front(const std::shared_ptr<T> &hexagon);
    void push_back(const std::shared_ptr<T> &hexagon);
    void insert(size_t pos, std::shared_ptr<T> &hexagon);
    bool empty();
    std::shared_ptr<T> get(size_t pos);
    void remove(size_t pos);
    void clear();
    void sort_sequential();
    void sort_concurrent();
    
    
    Iterator<ListItem<T>, T> begin();
    Iterator<ListItem<T>, T> end();
    
    template <class A> friend std::ostream& operator<<(std::ostream& os, const List<A>& list);

    virtual ~List();

private:
    std::shared_ptr<ListItem<T>> getItem(size_t pos);
    
    std::shared_ptr<ListItem<T>> first;
};

#endif /* List_hpp */
