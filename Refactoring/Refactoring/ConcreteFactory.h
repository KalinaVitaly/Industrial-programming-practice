#pragma once

#include "AbstractFactory.h"

class ConcreteFactory final : public AbstractFactory
{
public:
	Transport* CreateCar() override;
	Transport* CreatePlane() override;
	Transport* CreateTrain() override;
	Transport* CreateCar(std::tuple<int, int, double>, int) override;
	Transport* CreatePlane(std::tuple<int, int, double>, int) override;
	Transport* CreateTrain(std::tuple<int, int, double>, int) override;
};