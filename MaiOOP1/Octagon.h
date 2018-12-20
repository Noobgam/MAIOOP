#pragma once
#include "Point.h"
#include "Figure.h"

class Octagon : public Figure
{
public:
	Octagon();
	double Area() const override;
	void Print() const override;
protected:
	double Len_ = 0;
};


