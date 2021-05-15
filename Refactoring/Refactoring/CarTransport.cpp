#include "CarTransport.h"


Car::Car()
	: Transport(
		60,
		50,
		0,
		100) {}

Car::Car(std::tuple<int, int, double> tuple, int _dist)
	: Transport(
		std::get<1>(tuple),
		std::get<2>(tuple),
		_dist,
		std::get<0>(tuple)
	) {}

double Car::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Car::sumTime(int dist)
{
	return dist / speed;
}

int Car::getDistance()
{
	return this->distance;
}