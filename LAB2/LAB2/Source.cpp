#include "Source.h"

Nums getNums()
{
	Nums nums;
	std::cin >> nums.a >> nums.b >> nums.c >> nums.d >> nums.e >> nums.f;
	return nums;
}

std::string calculate(double a, double b, double c, double d, double e, double f)
{
	std::string result;

	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		result = "5";
	}
	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		double y = (a * f - c * e) / (a * d - c * b);
		double x = (d * e - b * f) / (d * a - b * c);
		result = "2 " + (std::to_string(x)) + " " + std::to_string(y);
	}
	else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
	{
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{
			double y;
			if (b == 0)
				y = f / d;
			else if (d == 0)
				y = e / b;
			else if (e == 0 || f == 0)
				y = 0;
			result = "4 " + std::to_string(y);
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x;
			if (a == 0)
				x = f / c;
			else if (c == 0)
				x = e / a;
			else if (e == 0 || f == 0)
				x = 0;
			result = "3 " + std::to_string(x);
		}
		else
			result = '0';
	}
	else if (a == 0 && c == 0)
	{
		double y;
		if (e == 0)
			y = f / d;
		else if (f == 0)
			y = e / b;
		else
			y = e / b;
		result = "4 " + std::to_string(y);
	}
	else if (b == 0 && d == 0)
	{
		double x;
		if (e == 0)
			x = f / c;
		else if (f == 0)
			x = e / a;
		else
			x = e / a;
		result = "3 " + std::to_string(x);
	}
	else if (b == 0 && e == 0)
	{
		double k, n;
		k = -c / d;
		n = f / d;
		result = "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (d == 0 && f == 0)
	{
		double k, n;
		k = -a / b;
		n = e / b;
		result = "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (a == 0 && e == 0)
	{
		double k, n;
		k = -d / c;
		n = f / c;
		result = "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (c == 0 && f == 0)
	{
		double k, n;
		k = -b / a;
		n = e / a;
		result = "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if ((a / b == c / d))
	{
		double k, n;
		k = -c / d;
		n = f / d;
		result = "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else
	{
		result = "Are you kidding me?";
	}

	return result;
}

int main()
{
	Nums nums = getNums();
	std::cout << calculate(nums.a, nums.b, nums.c, nums.d, nums.e, nums.f);
	return 0;
}