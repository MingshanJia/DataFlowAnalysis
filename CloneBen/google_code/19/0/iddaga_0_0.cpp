#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define ll long long
#define MN 1000
#define MX 101001
using namespace std;
struct DATA {
	int p, s;
};
bool cmp(DATA a, DATA b)
{return a.p+a.s > b.p+b.s;}
int n;
DATA d[MN];
int ch[MX];
bool help(int L)
{
	int i, j, k;

	memset(ch,0,sizeof(ch));
	for (i = L; i < MX; i++) ch[i] = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= d[i].p; j++) {
			if (ch[j+d[i].s]) ch[j] = 1;
		}
	}
	return ch[0];
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	int s, e, m;

	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d",&n);
		for (i = 0; i < n; i++)
			fscanf(in,"%d%d",&d[i].p,&d[i].s);
		sort(d,d+n,cmp);
		for (s = 1, e = 101000; s <= e;) {
			m = (s+e)/2;
			if (help(m)) s = m+1;
			else e = m-1;
		}
		fprintf(out,"%d\n",s-1);
	}
	return 0;
}