#ifndef ListItem_hpp
#define ListItem_hpp

#include "AllocationBlock.hpp"
#include <iostream>

template <class T>
class ListItem {
public:
    ListItem(const std::shared_ptr<T> &figure);    
    ListItem(const ListItem& orig);
    
    template <class A> friend std::ostream& operator<<(std::ostream& os, const ListItem<A>& obj);
    template <class A> friend bool operator==(ListItem<A>& first, ListItem<A>& last);

    std::shared_ptr<ListItem<T>> SetNext(std::shared_ptr<ListItem<T>> next);
    std::shared_ptr<ListItem<T>> GetNext();
    std::shared_ptr<T> GetFigure() const;
    
    void *operator new(size_t sz);
    void operator delete(void *ptr);
    
    virtual ~ListItem() {}
    
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<ListItem<T>> next;
    
    static AllocationBlock<ListItem<T>> allocator;
};

#endif /* ListItem_hpp */
