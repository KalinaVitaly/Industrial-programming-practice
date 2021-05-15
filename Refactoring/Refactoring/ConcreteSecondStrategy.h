#pragma once
#include "Strategy.h"
class ConcreteSecondStrategy final : public Strategy
{
public:
	Track Algorithm(int* _path, int _volume) override;
};

