#include "ConcreteFirstStrategy.h"

Track ConcreteFirstStrategy::Algorithm(int* _path, int _volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[0]][_path[1]]);
		}
	}

	Track track = Track(car1, _volume);
	return track;
}