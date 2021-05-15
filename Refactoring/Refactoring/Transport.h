#pragma once

#include "Storage.h"

class Transport
{
public:
	explicit Transport(int _speed, int _volume, int _distance, double _price);
	virtual ~Transport() = default;
public:
	virtual double sumCost(int, int) = 0;
	virtual double sumTime(int) = 0;
	virtual int getDistance() = 0;
protected:
	int speed;
	int volume;
	int distance;
	double price;
};

