#pragma once

#include "CarTransport.h"
#include "PlaneTransport.h"
#include "TrainTransport.h"

class AbstractFactory
{
public:
	virtual Transport* CreateCar() = 0;
	virtual Transport* CreatePlane() = 0;
	virtual Transport* CreateTrain() = 0;
	virtual Transport* CreateCar(std::tuple<int, int, double>, int) = 0;
	virtual Transport* CreatePlane(std::tuple<int, int, double>, int) = 0;
	virtual Transport* CreateTrain(std::tuple<int, int, double>, int) = 0;
};

