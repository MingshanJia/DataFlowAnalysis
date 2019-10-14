#include <cstdio>
#include <cmath>
using namespace std;
inline long double square(long double a)
{return a * a;
}
int main()
{
	int test_case_num, test_case;
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("output.txt" , "w", stdout);
	scanf("%d", &test_case_num);
	for (test_case = 1 ; test_case <= test_case_num ; test_case++)
	{
		int n;
		long long x, y, z, vx, vy, vz;
		scanf("%d", &n);
		x = y = z = vx = vy = vz = 0;
		for (int i = 0 ; i < n ;i++)
		{
			int a, b, c, d, e, f;
			scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
			x += a;
			y += b;
			z += c;
			vx += d;
			vy += e;
			vz += f;
		}

		long double tmin;

		if ( (vx * vx + vy * vy + vz * vz) == 0)
		{
			if ((vx * x + vy * y + vz * z) == 0)
			{
				tmin = 0;
			}
			else
			{
				tmin = -(long double)(x * x + y * y + z * z) / (vx * x + vy * y + vz * z);
				if (tmin < 0.000001)
					tmin = 0;
			}
		}
		else
		{

			tmin = -(long double)(vx * x + vy * y + vz * z) / (vx * vx + vy * vy + vz * vz);
			if (tmin < 0.000001)
				tmin = 0;
		}

		long double dmin = sqrtl(square(x + tmin * vx) + square(y + tmin * vy) + square(z + tmin * vz)) / n;

		printf("Case #%d: %.9Lf %.9Lf\n", test_case, dmin, tmin);
	}
	return 0;
}