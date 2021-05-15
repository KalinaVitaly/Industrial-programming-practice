#pragma once
#include "Transport.h"

class Plane final : public Transport
{
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane() override = default;
public:
	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};