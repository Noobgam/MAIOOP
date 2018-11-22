#ifndef ListItem_hpp
#define ListItem_hpp

#include "Figures/Figure.h"
#include <iostream>
#include <memory>

class ListItem {
public:
    ListItem(const std::shared_ptr<Figure> &Figure);
    ListItem(const ListItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const ListItem& obj);
    friend bool operator==(ListItem& first, ListItem& last);
    
    std::shared_ptr<ListItem> SetNext(std::shared_ptr<ListItem> next);
    std::shared_ptr<ListItem> GetNext();
    std::shared_ptr<Figure> GetFigure() const;
    
    virtual ~ListItem();
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<ListItem> next;
};

#endif /* ListItem_hpp */
