#include<cstdio>
#include<cstring>
#include<cmath>
#define ZERO 1e-10
double X, Y , Z, xx, yy, zz, Vx, Vy, Vz;
double x[500], y[500], z[500] , vx[500], vy[500], vz[500];
double t;
int n;
	
int dcmp(double a , double b)
{
	if (fabs(a - b) < ZERO) return 0;
	else if (a - b > ZERO) return 1;
	else return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int cases;
	scanf("%d" , &cases);
	for (int ca = 1; ca <= cases; ++ca)
	{
		scanf("%d" , &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf%lf%lf%lf%lf", x + i , y + i , z + i , vx + i , vy + i , vz + i);
		X = Y = Z = Vx = Vy = Vz = 0;
		for (int i = 0; i < n; ++i)
		{
			X += x[i]; Y += y[i]; Z += z[i];
			Vx += vx[i]; Vy += vy[i]; Vz += vz[i];
		}
		if ( !dcmp(Vx, 0) && !dcmp(Vy, 0) && !dcmp(Vz, 0)) t = 0;
		else
		{
			t = - (X * Vx + Y * Vy + Z * Vz) / (Vx * Vx + Vy * Vy + Vz * Vz);
			if (dcmp(t , 0) < 0)  t = 0;
		}
		xx = (X + t * Vx) / n;
		yy = (Y + t * Vy) / n;
		zz = (Z + t * Vz) / n;
		printf("Case #%d: %.8lf %.8lf\n", ca, sqrt(xx * xx + yy * yy + zz * zz) , t);
	}
}
