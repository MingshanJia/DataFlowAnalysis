#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cmath>


using namespace std;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int n;
		scanf("%d", &n);
		long long a = 0, b = 0, c = 0;
		long long X = 0, VX = 0, Y = 0, VY = 0, Z = 0, VZ = 0;
		for (int i = 0; i < n; ++i)
		{
			int x, y, z, vx, vy, vz;
			scanf("%d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz);
			X += x;
			Y += y;
			Z += z;
			VX += vx;
			VY += vy;
			VZ += vz;
		}
		a = VX * VX + VY * VY + VZ * VZ;
		b = 2 * (X * VX + Y * VY + Z * VZ);
		c = X * X + Y * Y + Z * Z;
		double x0 = 0.0;
		if (a != 0)
		{
			x0 = (double)(-b) / (2 * a);
			if (-b <= 0 && a >= 0 || -b >= 0 && a <= 0)
				x0 = 0.0;
		}
		else
			x0 = 0.0;

		double y0 = (x0 * x0) * a + b * x0 + c;
		y0 /= n * n;
		if (y0 < 1e-8)
			y0 = 0.0;
		else
			y0 = sqrt(y0);
		printf("Case #%d: %.8lf %.8lf\n", t + 1, y0, x0);
	}

	return 0;
}