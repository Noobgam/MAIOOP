#ifndef Hexagon_hpp
#define Hexagon_hpp

#include <stdio.h>

#include <stdio.h>
#include "Figure.h"
#include <iostream>

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(std::istream &is);
    Hexagon(const Hexagon& orig);
    Hexagon(size_t a);
    
    Hexagon& operator=(const Hexagon & right);
    
    friend bool operator==(const Hexagon& left, const Hexagon& right);
    friend std::ostream& operator<<(std::ostream& os,const Hexagon& stack);
    friend std::istream& operator>>(std::istream& is, Hexagon& obj);
    
    double Square() const;
    void Print() const;
    std::string ToString() const;
    virtual ~Hexagon();
private:
    size_t side;
};


#endif /* Hexagon_hpp */
