#pragma once

#include "Track.h"

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual Track Algorithm(int *, int) = 0;
};

