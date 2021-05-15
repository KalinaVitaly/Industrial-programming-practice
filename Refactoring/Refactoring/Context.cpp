#include "Context.h"

Context::Context(Strategy* _strategy)
	: strategy(_strategy)
{
}

Context::~Context()
{
	delete strategy;
}

void Context::SetStrategy(Strategy* _strategy)
{
	delete strategy;
	strategy = _strategy;
}

Track Context::DoLogic(int* _path, int _volume)
{
	return strategy->Algorithm(_path, _volume);
}
