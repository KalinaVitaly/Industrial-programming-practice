#pragma once

#include "CarTransport.h"
#include "TrainTransport.h"
#include "PlaneTransport.h"

class Track final
{
	double cost;
	double time;
	int volume;
public:
	Track();
	Track(Car, int);
	Track(Car, Car, Train, int);
	Track(Car, Car, Plane, int);
	Track(Car, Car, Car, Train, Plane, int);
	Track(Car, Car, Car, Car, Train, Train, Plane, int);
	double getCost();
	~Track();
};
