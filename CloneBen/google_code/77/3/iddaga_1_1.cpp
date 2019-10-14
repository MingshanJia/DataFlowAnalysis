#include <stdio.h>
#include <memory.h>
#define MX 10002
int d[MX], dd[MX];
int c[MX];
bool go(int p, int m)
{
	int i;

	for (i = 0; i < m; i++) {
		if (d[p+i])
			d[p+i]--;
		else return 0;
	}
	c[p+i]++;
	return 1;
}
bool help(int m)
{
	int i, j, k;

	memset(c,0,sizeof(c));
	k = 0;
	for (i = 1; i < MX; i++) {
		k += c[i];
		if (d[i] >= k) {
			d[i] -= k;
		}
		else {
			k = d[i];
			d[i] = 0;
		}
		while (d[i]) {
			if (!go(i,m)) return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, T, i, j, k, s, e, m, n;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		scanf("%d",&n);
		memset(d,0,sizeof(d));
		for (i = 0; i < n; i++) {
			scanf("%d",&j);
			d[j]++;
		}
		if (n == 0) {
			printf("0\n");
			continue;
		}
		for (s = 1, e = n; s <= e;) {
			m = (s+e)/2;
			memcpy(dd,d,sizeof(d));
			if (help(m)) s = m+1;
			else e = m-1;
			memcpy(d,dd,sizeof(dd));
		}
		printf("%d\n",s-1);
	}
	return 0;
}