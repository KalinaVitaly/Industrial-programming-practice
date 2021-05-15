#pragma once
#include "Transport.h"

class Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car() override = default;
public:
	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};

