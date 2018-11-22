#ifndef HexagonListItem_hpp
#define HexagonListItem_hpp

#include "Hexagon.hpp"

class HexagonListItem {
public:
    HexagonListItem(const Hexagon& hexagon);
    HexagonListItem(const HexagonListItem& orig);//copy constr
    friend std::ostream& operator<<(std::ostream& os, const HexagonListItem& obj);
    friend bool operator==(HexagonListItem& first, HexagonListItem& last);
    
    HexagonListItem* SetNext(HexagonListItem* next);
    HexagonListItem* GetNext();
    Hexagon GetHexagon() const;
    
    virtual ~HexagonListItem();
private:
    Hexagon hexagon;
    HexagonListItem *next;
};

#endif /* HExagonListItem_hpp */
