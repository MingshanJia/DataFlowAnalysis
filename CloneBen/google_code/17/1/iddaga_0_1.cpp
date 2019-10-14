#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#define MM 1000
using namespace std;
struct DATA {
	int s, a, b;
};
bool cmp(DATA a, DATA b)
{return a.s < b.s;}
int N, M, B, r;
int P[MM], Q[MM];
DATA a[MM*MM]; int ac;
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;

	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d%d%d",&N,&M,&B);
		for (i = 0; i < M; i++)
			fscanf(in,"%d%d",&P[i],&Q[i]);
		ac = 0;
		for (i = 0; i < M; i++) {
			if (P[i] >= B) {
				a[ac].s = P[i];
				a[ac].a = i; a[ac].b = -1;
				ac++;
			}
		}
		for (i = 0; i < M; i++) {
			for (j = i; j < M; j++) {
				if (P[i]+P[j] >= B) {
					a[ac].s = P[i]+P[j];
					a[ac].a = i; a[ac].b = j;
					ac++;
				}
			}
		}
		r = 0;
		sort(a,a+ac,cmp);
		for (i = 0; i < ac; i++) {
			k = N;
			if (a[i].a != a[i].b) {
				if (k > Q[a[i].a])
					k = Q[a[i].a];
				if (a[i].b != -1) {
					if (k > Q[a[i].b])
						k = Q[a[i].b];
				}
				r += k*a[i].s;
				N -= k;
				Q[a[i].a] -= k;
				if (a[i].b != -1)
					Q[a[i].b] -= k;
			}
			else {
				if (k > Q[a[i].a]/2)
					k = Q[a[i].a]/2;
				r += k*a[i].s;
				N -= k;
				Q[a[i].a] -= k*2;
			}
		}
		fprintf(out,"%d\n",N>0?-1:r);
	}
	return 0;
}