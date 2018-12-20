#include "Octagon.h"
#include <iostream>

Octagon::Octagon() { //how am I supposed to have default constuctor to read from cin, are you out of your mind?
	std::cin >> Len_;
}

double Octagon::Area() const {
	return 2 * (1 + sqrt(2)) * Len_ * Len_;
}

void Octagon::Print() const {
	std::cout << "Octagon " << Len_;
}