#ifndef Figure_h
#define Figure_h

#include <string>

class Figure {
public:
    virtual double Square() const = 0;
    virtual void Print() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Figure() {};
};

#endif /* Figure_h */
