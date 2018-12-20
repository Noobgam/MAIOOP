#include "Triangle.hpp"

#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {}

Triangle::Triangle(size_t a, size_t b, size_t c) : side_a(a), side_b(b), side_c(c) {
    //std::cout << "Triangle created: " << side << std::endl;
}

Triangle::Triangle(const Triangle& orig) {
    //std::cout << "Triangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
}

Triangle::Triangle(std::istream &is) {
    is >> side_a >> side_b >> side_c;
}

Triangle& Triangle::operator=(const Triangle& right) {
    if (this == &right) return *this;
    //std::cout << "Triangle copied" << std::endl;
    side_a = right.side_a;
    side_b = right.side_b;
    side_c = right.side_c;
    
    return *this;
}

bool operator==(const Triangle & left, const Triangle & right){
    return (left.side_a == right.side_a && left.side_b == right.side_b && left.side_c == right.side_c);
}

double Triangle::Square() const {
    double p = double(side_a + side_b + side_c) / 2.0;
    if (p < side_c || p < side_a || p < side_b) {
        return 0;
    }
    return sqrt(p * (p - double(side_a))*(p - double(side_b)) * (p - double(side_c)));
}

void Triangle::Print() const {
    std::cout << ToString() << std::endl;
}

Triangle::~Triangle() {
    //std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj) {
    os << obj.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Triangle& obj) {
    is >> obj.side_a >> obj.side_b >> obj.side_c;
    return is;
}

std::string Triangle::ToString() const {
    return std::string("Triangle sides = " + std::to_string(side_a) + " " + std::to_string(side_b) + " " + std::to_string(side_c));
}
