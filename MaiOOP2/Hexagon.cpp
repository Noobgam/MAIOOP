#include "Hexagon.hpp"

#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {}

Hexagon::Hexagon(size_t a) : side(a) {
    //std::cout << "Hexagon created: " << side << std::endl;
}

Hexagon::Hexagon(const Hexagon& orig) {
    //std::cout << "Hexagon copy created" << std::endl;
    side = orig.side;
}

Hexagon::Hexagon(std::istream &is) {
    is >> side;
}

Hexagon& Hexagon::operator=(const Hexagon& right) {
    if (this == &right) return *this;
    //std::cout << "Hexagon copied" << std::endl;
    side = right.side;
    
    return *this;
}

bool operator==(const Hexagon & left, const Hexagon & right){
    return left.side == right.side;
}

double Hexagon::Square() {
    return sqrt(3.0) * 3 * (double)(side * side) / 2;
}

void Hexagon::Print() {
    std::cout << "Hexagon side = " << side << std::endl;
}

Hexagon::~Hexagon() {
    //std::cout << "Hexagon deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
    os << "Hexagon side = " << obj.side;
    return os;
}

std::istream& operator>>(std::istream& is, Hexagon& obj) {
    is >> obj.side;
    return is;
}
