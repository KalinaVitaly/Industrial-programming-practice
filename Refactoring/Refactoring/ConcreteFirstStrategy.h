#pragma once
#include "Strategy.h"
class ConcreteFirstStrategy final : public Strategy
{
public:
    Track Algorithm(int* _path, int _volume) override;
};

