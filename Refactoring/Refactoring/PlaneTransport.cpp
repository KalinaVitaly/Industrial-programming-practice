#include "PlaneTransport.h"

Plane::Plane()
	: Transport(
		300,
		100,
		0,
		500 ) {}

Plane::Plane(std::tuple<int, int, double> tuple, int _dist)
	: Transport(
		std::get<1>(tuple),
		std::get<2>(tuple),
		_dist,
		std::get<0>(tuple)
	) {}

double Plane::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Plane::sumTime(int dist)
{
	return dist / speed;
}

int Plane::getDistance()
{
	return this->distance;
}