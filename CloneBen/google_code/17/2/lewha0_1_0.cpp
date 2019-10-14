#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>

#define Swap(aa,bb) {cc=aa;aa=bb;bb=cc;}

const int MAGICNUMBER = 1000;
const long double  EPS = 1e-12;
const long double  MY_PI = (long double )3.1415926535897932384626433832795;

int N;
long double  R, H, Hangle;
long double  X[1111], Y[1111], cc;
int T;
long double  left, right, mid, up, down;

inline int CCW(long double  x1, long double  y1, long double  x2, long double  y2, long double  x3, long double  y3)
{
	long double  val = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if(val < -EPS) return -1;
	if(val > EPS) return 1;
	return 0;
}

long double  Angle(long double  px, long double  py)
{
	if(fabs(px) <= EPS && fabs(py) <= EPS) return -1;
	if(fabs(px) <= EPS) return (py > EPS ? 1.0 : 3.0) * acos((long double )0);
	long double  theta = atan(1.0 * py / px);
	if(px > EPS) return (py >= -EPS ? theta : (4 * acos((long double )0.0) + theta));
	return (2 * acos((long double )0) + theta);

}

int main(void)
{
	int l0, l1, l2, l3;

	//freopen("input.txt","r",stdin);
	
	freopen("B1.in","r",stdin);
	freopen("B1.out","w",stdout);

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		fprintf(stderr,"...%d / %d\n",l0,T);
		scanf("%d %Lf %Lf",&N,&R,&H);

		Hangle = H / (long double )12 * MY_PI;

		for(l1=0;l1<N;l1++) scanf("%Lf %Lf",&X[l1],&Y[l1]);

		for(l1=0;l1<N;l1++)
		{
			for(l2=l1+1;l2<N;l2++)
			{
				if(X[l1] > X[l2])
				{
					Swap(X[l1],X[l2]);
					Swap(Y[l1],Y[l2]);
				}
			}
		}
		
		up = 0;
		down = 0;

		for(l1=0;l1<N;l1++)
		{
			left = 0;
			right = Y[l1];

			for(l2=0;l2<MAGICNUMBER;l2++)
			{
				mid = (left + right) / (long double )2.0;

				long double  y_right = 0, y_left = 0;
				long double  x_left = -R, x_right = R;
				long double  theta_right = 0, theta_left = MY_PI;

				for(l3=0;l3<N;l3++)
				{
					if(l1 == l3) continue;

					long double  dx = X[l3] - X[l1];
					long double  dy = Y[l3] - mid;

					long double  A = dx*dx + dy*dy;
					long double  B = (long double )2.0 * (X[l1] * dx + mid * dy);
					long double  C = X[l1]*X[l1] + mid*mid - R*R;

					long double Det = B*B - (long double)4.0 * A * C;
					if(Det <= EPS)
					{
						fprintf(stderr,"What????????????????\n");
					}

					if(X[l3] < X[l1]) // on the left
					{
						long double  sol = (-B + sqrt(B*B - (long double )4.0*A*C)) / ((long double )2.0 * A);

						long double  new_x = X[l1] + sol * dx;
						long double  new_y = mid + sol * dy;
						long double  new_theta = Angle(new_x, new_y);

						if(new_y >= -EPS && new_theta < theta_left)
						{
							x_left = new_x;
							y_left = new_y;
							theta_left = new_theta;
						}
					}
					else
					{
						long double  sol = (-B + sqrt(B*B - (long double )4.0*A*C)) / ((long double )2.0 * A);

						long double  new_x = X[l1] + sol * dx;
						long double  new_y = mid + sol * dy;
						long double  new_theta = Angle(new_x, new_y);

						if(new_y >= -EPS && new_theta > theta_right)
						{
							x_right = new_x;
							y_right = new_y;
							theta_right = new_theta;
						}
					}
				}


				long double  angles = Angle(x_left, y_left) - Angle(x_right, y_right);
				if(angles >= Hangle - EPS)
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
			mid = (left + right) / (long double )2.0;

			up += (Y[l1] - mid);
			down += Y[l1];

		}

		printf("Case #%d: %.10Lf\n",l0,up/down);
	}

	return 0;
}