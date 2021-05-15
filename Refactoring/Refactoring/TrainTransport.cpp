#include "TrainTransport.h"

Train::Train()
	: Transport(
		100,
		500,
		0,
		200
	) {}

Train::Train(std::tuple<int, int, double> tuple, int _dist)
	: Transport(
		std::get<1>(tuple),
		std::get<2>(tuple),
		_dist,
		std::get<0>(tuple)
	) {}


double Train::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Train::sumTime(int dist)
{
	return dist / speed;
}

int Train::getDistance()
{
	return distance;
}
