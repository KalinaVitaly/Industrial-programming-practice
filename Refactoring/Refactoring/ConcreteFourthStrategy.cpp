#include "ConcreteFourthStrategy.h"

Track ConcreteFourthStrategy::Algorithm(int* _path, int _volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[0]][_path[1]]);
		}
	}

	Train train1 = Train();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[1]]))
		{
			train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[_path[1]][_path[2]]);
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

	Plane plane1 = Plane();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[3]]))
		{
			plane1 = Plane(tableCost[(*it).second * 3], matrixDist[_path[3]][_path[4]]);
		}
	}

	Car car3 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[4]]))
		{
			car3 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[4]][_path[5]]);
		}
	}

	Train train2 = Train();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[5]]))
		{
			train2 = Train(tableCost[(*it).second * 3 + 1], matrixDist[_path[5]][_path[6]]);
		}
	}

	Car car4 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[6]]))
		{
			car4 = Car(tableCost[(*it).second * 3 + 2], matrixDist[_path[6]][_path[7]]);
		}
	}

	Track track = Track(car1, car2, car3, car4, train1, train2, plane1, _volume);

	return track;
}