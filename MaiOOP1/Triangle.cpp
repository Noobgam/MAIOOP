#include "Triangle.h"
#include <iostream>

Triangle::Triangle() { //how am I supposed to have default constuctor to read from cin, are you out of your mind?
	std::cin >> a >> b >> c;
}

double Triangle::Area() const {
	double p = (a + b + c) * 0.5;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::Print() const {
	std::cout << "Triangle " << a << " " << b << " " << c;
}
