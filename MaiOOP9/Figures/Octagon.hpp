#ifndef Octagon_hpp
#define Octagon_hpp

#include <stdio.h>

#include <stdio.h>
#include "Figure.h"
#include <iostream>

class Octagon : public Figure {
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(const Octagon& orig);
    Octagon(size_t a);
    
    Octagon& operator=(const Octagon & right);
    
    friend bool operator==(const Octagon& left, const Octagon& right);
    friend std::ostream& operator<<(std::ostream& os,const Octagon& stack);
    friend std::istream& operator>>(std::istream& is, Octagon& obj);
    
    double Square() const;
    void Print() const;
    std::string ToString() const;
    virtual ~Octagon();
private:
    size_t side;
};


#endif /* Octagon_hpp */

