#include <stdio.h>
#include <algorithm>
#include <math.h>

#define x first
#define y second

using namespace std;

const double pi = acos((double)0) * 2;
pair<double, double> dat[256];

pair<double, double> getangle(double a, double b, double c)
{
	double gamma = acos(- c / sqrt(a*a + b*b));
	double delta = atan2(b, a);
	double theta = gamma + delta;

	while(theta < 0) theta += 2*pi;
	while(theta > 2 * pi) theta -= 2*pi;

	double theta2 = (- gamma) + delta;

	while(theta2 < 0) theta2 += 2*pi;
	while(theta2 > 2 * pi) theta2 -= 2*pi;

	return make_pair(min(theta, theta2), max(theta, theta2));
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		int n;
		double r,h;
		scanf("%d%lf%lf",&n,&r,&h);
		h /= 12;
		h *= pi;
		for(int i = 0; i < n; i ++)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			x /= r;
			y /= r;
			dat[i].x = x;
			dat[i].y = y;
		}
		double anstotal = 0, anspart = 0;

		for(int i = 0; i < n; i ++)
		{
			double low = 0, high = dat[i].y;
			double range = atan2(sqrt(1 - dat[i].x*dat[i].x), dat[i].x);
			for(int magic = 0; magic < 60; magic ++)
			{
				double mid = (low + high) / 2;

				double a1 = 0, a2 = pi;
				for(int j = 0;j < n; j ++)
				{
					if(i == j) continue;
					double x1 = dat[i].x, y1 = mid;
					double x2 = dat[j].x, y2 = dat[j].y;
					double a = y1 - y2;
					double b = x2 - x1;
					double c = x1 * y2 - x2 * y1;
					pair<double, double> res = getangle(a,b,c);
					if(res.first <= range && range <= res.second)
					{
						if(dat[i].x < dat[j].x)
						{
							a1 = max(a1, res.first);
						}
						else
						{
							a2 = min(a2, res.second);
						}
					}
					else
					{
						if(dat[i].x < dat[j].x)
						{
							a1 = a1;
						}
						else
						{
							a2 = min(a2, res.first);
						}
					}
				}

				if(a2 - a1 >= h - 1e-10)
				{
					high = mid;
				}
				else
				{
					low = mid;
				}
			}

			anspart += dat[i].y - (low + high) / 2;
			anstotal += dat[i].y;
		}// end for i

		printf("Case #%d: %.10f\n", testcase, anspart / anstotal);
	}
	return 0;
}