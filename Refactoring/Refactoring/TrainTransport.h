#pragma once
#include "Transport.h"

class Train final : public Transport
{
public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train() override = default;
public:
	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};

