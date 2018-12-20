#include "Hexagon.h"
#include <iostream>

Hexagon::Hexagon() { //how am I supposed to have default constuctor to read from cin, are you out of your mind?
	std::cin >> Len_;
}

double Hexagon::Area() const {
	return 1.5 * (sqrt(3)) * Len_ * Len_;
}

void Hexagon::Print() const {
	std::cout << "Hexagon " << Len_;
}