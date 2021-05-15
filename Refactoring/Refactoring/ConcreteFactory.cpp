#include "ConcreteFactory.h"

Transport* ConcreteFactory::CreateCar()
{
	return new Car();
}

Transport* ConcreteFactory::CreatePlane()
{
	return new Plane();
}

Transport* ConcreteFactory::CreateTrain()
{
	return new Train();
}

Transport* ConcreteFactory::CreateCar(std::tuple<int, int, double> _data, int _distance)
{
	return new Car(_data, _distance);
}

Transport* ConcreteFactory::CreatePlane(std::tuple<int, int, double> _data, int _distance)
{
	return new Plane(_data, _distance);
}

Transport* ConcreteFactory::CreateTrain(std::tuple<int, int, double> _data, int _distance)
{
	return new Train(_data, _distance);
}
