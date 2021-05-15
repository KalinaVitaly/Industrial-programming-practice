#pragma once

#include <memory>
#include "Track.h"
#include "Context.h"
#include "ConcreteFirstStrategy.h"
#include "ConcreteSecondStrategy.h"
#include "ConcreteThirdStrategy.h"
#include "ConcreteFourthStrategy.h"
#include "ConcreteFactory.h"

class Order final
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;
public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};
