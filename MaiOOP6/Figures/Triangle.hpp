#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>

#include <stdio.h>
#include "Figure.h"
#include <iostream>

class Triangle : public Figure {
public:
    Triangle();
    Triangle(std::istream &is);
    Triangle(const Triangle& orig);
    Triangle(size_t a, size_t b, size_t c);
    
    Triangle& operator=(const Triangle & right);
    
    friend bool operator==(const Triangle& left, const Triangle& right);
    friend std::ostream& operator<<(std::ostream& os,const Triangle& stack);
    friend std::istream& operator>>(std::istream& is, Triangle& obj);
    
    double Square() const;
    void Print() const;
    std::string ToString() const;
    virtual ~Triangle();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};


#endif /* Triangle_hpp */

