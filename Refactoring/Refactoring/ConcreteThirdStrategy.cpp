#include "ConcreteThirdStrategy.h"

Track ConcreteThirdStrategy::Algorithm(int* _path, int _volume)
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
	Plane plane1 = Plane();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[1]]) && points[_path[1]].find("TS"))
		{
			train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[_path[1]][_path[2]]);
		}
		if ((*it).first.find(points[_path[1]]) && points[_path[1]].find("AP"))
		{
			plane1 = Plane(tableCost[(*it).second * 3], matrixDist[_path[1]][_path[2]]);
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

	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[_path[3]]) && points[_path[3]].find("AP"))
		{
			plane1 = Plane(tableCost[(*it).second * 3], matrixDist[_path[3]][_path[4]]);
		}
		if ((*it).first.find(points[_path[3]]) && points[_path[3]].find("TS"))
		{
			train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[_path[3]][_path[4]]);
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

	Track track = Track(car1, car2, car3, train1, plane1, _volume);
	return track;
}