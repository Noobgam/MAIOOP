#ifndef Iterator_h
#define Iterator_h

#include <memory>
#include <iostream>

template <class N, class T>
class Iterator
{
public:
    Iterator(std::shared_ptr<N> n) : cur(n) {}
    
    std::shared_ptr<T> operator*() {
        return cur->GetData();
    }
    
    std::shared_ptr<T> operator->() {
        return cur->GetData();
    }
    
    Iterator operator++() {
        return cur = cur->GetNext();
    }
    
    Iterator operator++(int) {
        Iterator cur(*this);
        ++(*this);
        return cur;
    }
    
    bool operator==(const Iterator &i) {
        return (cur == i.cur);
    }
    
    bool operator!=(const Iterator &i) {
        return (cur != i.cur);
    }
    
private:
    std::shared_ptr<N> cur;
};

#endif /* Iterator_h */
