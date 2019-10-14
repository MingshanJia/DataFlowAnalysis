#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#define ll long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
#define MN 8
#define oo 2147483647
ll N, A, B, C, D, E, F;
ll f[MN][MN], c[MN][MN];
int v[MN][MN];
void upd(int s, int e, ll k)
{c[s][e] = c[e][s] = f[e][s] = k;}
int dis[MN], pr[MN];
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	ll r, mf;

	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%lld%lld%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D,&E,&F);
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		upd(0,1,A); upd(0,2,B); upd(0,3,C);
		upd(4,7,D); upd(5,7,E); upd(6,7,F);
		for (i = 1; i <= 3; i++) {
			for (j = 4; j <= 6; j++)
				upd(i,j,N);
		}
		memset(v,0,sizeof(v));
		for (i = 1; i <= 3; i++) {
			for (j = 4; j <= 6; j++) {
				fscanf(in,"%d",&k);
				v[i][j] = k;
				v[j][i] = -k;
			}
		}
		r = 0;
		for (;;) {
			for (i = 0; i < 8; i++) dis[i] = -oo;
			dis[0] = 0;
			for (k = 0; k < 8; k++) {
				for (i = 0; i < 8; i++) {
					for (j = 0; j < 8; j++) {
						if (f[i][j] < c[i][j] && dis[i] != -oo) {
							if (dis[j] < dis[i]+v[i][j]) {
								dis[j] = dis[i]+v[i][j];
								pr[j] = i;
							}
						}
					}
				}
			}
			if (dis[7] == -oo) break;
			mf = -1;
			for (i = 7; i != 0; i = j) {
				j = pr[i];
				if (mf == -1 || mf > c[j][i]-f[j][i])
					mf = c[j][i]-f[j][i];
			}
			r += mf*dis[7];
			for (i = 7; i != 0; i = j) {
				j = pr[i];
				f[j][i] += mf; f[i][j] -= mf;
			}
		}
		fprintf(out,"%lld\n",r);
	}
	return 0;
}