#ifndef Figure_h
#define Figure_h

class Figure {
public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual ~Figure() {};
};

#endif /* Figure_h */
