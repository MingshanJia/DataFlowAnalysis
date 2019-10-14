#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int N;
double f, R, t, stringR, g;

const double PI = 3.1415926535;

double findArea(double r, double X1, double Y1, double X2, double Y2)
{
	double theta1 = atan(Y1 / X1);
	double theta2 = atan(Y2 / X2);
	double theta = theta2 - theta1;
	return 0.5 * (theta - sin(theta)) * r * r; 
}

double findIntersection(double r, double x, double y, double L)
{
	double X1 = x - L / 2;
	double X2 = x + L / 2;
	double Y1 = y - L / 2;
	double Y2 = y + L / 2;

	//cout << "Solve for X1 = " << X1 << " X2 = " << X2 << " Y1 = " << Y1 << " Y2 = " << Y2 << " r = " << r << endl;
	
	if (X1 * X1 + Y1 * Y1 >= r * r) return 0;

	double Xtop, Xbottom, Yleft, Yright;

	if (X2 * X2 + Y1 * Y1 >= r * r)
	{
		Xbottom = sqrt(r * r - Y1 * Y1);
		Yleft = sqrt(r * r - X1 * X1);
		return 0.5 * (Xbottom - X1) * (Yleft - Y1) + findArea(r, Xbottom, Y1, X1, Yleft);
	}

	if (X1 * X1 + Y2 * Y2 >= r * r)
	{
		Yleft = sqrt(r * r - X1 * X1);
		Yright = sqrt(r * r - X2 * X2);
		return 0.5 * (Yleft + Yright - 2 * Y1) * (X2 - X1) + findArea(r, X2, Yright, X1, Yleft);
	}

	if (X2 * X2 + Y2 * Y2 >= r * r)
	{
		Xtop = sqrt(r * r - Y2 * Y2);
		Yright = sqrt(r * r - X2 * X2);
		return L * L - 0.5 * (X2 - Xtop) * (Y2 - Yright) + findArea(r, X2, Yright, Xtop, Y2);
	}

	return L * L;
}

int main()
{
	ifstream input;
	ofstream output;
	input.open("C-large.in");
	output.open("C-large.out");

	input >> N;

	for (int c = 0; c < N; c++)
	{
		input >> f >> R >> t >> stringR >> g;

		vector<double> stringX1;
		vector<double> stringX2;

		double currentX1 = - stringR;
		double currentX2 = + stringR;

		while (currentX2 < R - t)
		{
			stringX1.push_back(currentX1);
			stringX2.push_back(currentX2);

			currentX1 += g + 2 * stringR;
			currentX2 += g + 2 * stringR;
		}

		stringX1.push_back(currentX1);
		stringX2.push_back(currentX2);

		int m = stringX1.size();

		//cout << "m = " << m << endl;
		//for (int i = 0; i < m; i++) cout << "X1 = " << stringX1[i] << " X2 = " << stringX2[i] << endl;

		double area;
		
		if (f >= g / 2 || m == 1)
			area = 0;
		else
		{
			area = 0;
			for (int i = 0; i < m - 1; i++)
				for (int j = i; j < m - 1; j++)
				{
					double now = findIntersection(R - t - f, (stringX2[i] + stringX1[i+1]) / 2, (stringX2[j] + stringX1[j+1]) / 2, g - 2 * f);
					if (i == j) 
						area += now;
					else
						area += 2 * now;
				}
		}

		output << "Case #" << c + 1 << ": " << 1 - 4 * area / (PI * R * R) << endl;
	}

	input.close();
	output.close();
}