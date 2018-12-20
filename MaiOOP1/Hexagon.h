#pragma once
#include "Figure.h"

class Hexagon : public Figure
{
public:
	Hexagon();
	double Area() const override;
	void Print() const override;
protected:
	double Len_ = 0;
};


