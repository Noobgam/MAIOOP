#pragma once
#include "Point.h"
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle();
	double Area() const override;
	void Print() const override;	
private:
	double a, b, c;
};

