#include "Octagon.hpp"

#include <iostream>
#include <cmath>

Octagon::Octagon() : Octagon(0) {}

Octagon::Octagon(size_t a) : side(a) {
    //std::cout << "Octagon created: " << side << std::endl;
}

Octagon::Octagon(const Octagon& orig) {
    //std::cout << "Octagon copy created" << std::endl;
    side = orig.side;
}

Octagon::Octagon(std::istream &is) {
    is >> side;
}

Octagon& Octagon::operator=(const Octagon& right) {
    if (this == &right) return *this;
    //std::cout << "Octagon copied" << std::endl;
    side = right.side;
    
    return *this;
}

bool operator==(const Octagon & left, const Octagon & right){
    return left.side == right.side;
}

double Octagon::Square() const {
    return 2 * side * side * (1.0 + sqrt(2.0));
}

void Octagon::Print() const {
    std::cout << ToString() << std::endl;
}

Octagon::~Octagon() {
    //std::cout << "Octagon deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj) {
    os << obj.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Octagon& obj) {
    is >> obj.side;
    return is;
}

std::string Octagon::ToString() const {
    return std::string("Octagon side = " + std::to_string(side));
}


