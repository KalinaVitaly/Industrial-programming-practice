#include "ConcreteSecondStrategy.h"

Track ConcreteSecondStrategy::Algorithm(int* _path, int _volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[0]][_path[1]]);
		}
	}

	Car car2 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[2]]))
		{
			car2 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[2]][_path[3]]);
		}
	}

	Train train1 = Train();
	Plane plane1 = Plane();
	Track track = Track();

	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[1]]) && points[_path[1]].find("TS"))
		{
			train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[_path[1]][_path[2]]);
			track = Track(car1, car2, train1, _volume);
		}

		if ((*it).first.find(points[_path[1]]) && points[_path[1]].find("AP"))
		{
			plane1 = Plane(tableCost[(*it).second * 3], matrixDist[_path[1]][_path[2]]);
			track = Track(car1, car2, plane1, _volume);
		}
	}

	return track;
}