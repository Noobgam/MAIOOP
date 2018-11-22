#ifndef HexagonList_hpp
#define HexagonList_hpp

#include "Hexagon.hpp"
#include "HexagonListItem.hpp"

class HexagonList {
public:
    HexagonList();
    HexagonList(const HexagonList& orig);
    
    void push_front(Hexagon &&hexagon);
    void push_back(Hexagon &&hexagon);
    void insert(size_t pos, Hexagon &&hexagon);
    bool empty();
    Hexagon get(size_t pos);
    void remove(size_t pos);
    void clear();
    friend std::ostream& operator<<(std::ostream& os, const HexagonList& stack);
    virtual ~HexagonList();
private:
    
    HexagonListItem* getItem(size_t pos);
    HexagonListItem *first;
};

#endif /* HexagonList_hpp */
