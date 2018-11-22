#ifndef ListItem_hpp
#define ListItem_hpp

#include <iostream>
#include <memory>

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
    
    virtual ~ListItem() {}
    
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<ListItem<T>> next;
};

#endif /* ListItem_hpp */
