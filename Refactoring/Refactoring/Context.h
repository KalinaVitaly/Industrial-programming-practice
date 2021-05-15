#pragma once

#include "Strategy.h"

class Context final
{
public:
	explicit Context(Strategy* _strategy = nullptr);
	~Context();
public:
	void SetStrategy(Strategy* _strategy);
	Track DoLogic(int* _path, int _volume);
private:
	Strategy* strategy;
};

