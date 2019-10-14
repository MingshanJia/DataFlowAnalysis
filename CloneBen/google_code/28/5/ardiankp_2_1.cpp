#include <stdio.h>
#include <string.h>

int MOD;

int tc, ntc;
int n, k;

struct edge
{
	int a, b;
};
edge e[15];

int n1(int x)
{
	int res = 0;
	while (x)
	{
		res++;
		x &= x-1;
	}
	return res;
}

int fakt[301];
int num[301];
bool used[301];

int MASK;
int scomp;
bool cyc;

void dfs(int x, int p)
{
	used[x] = true;
	scomp++;
	
	int i;
	int b;
	for (i=0; i<k; i++) if (MASK & (1<<i))
	{
		if (x == e[i].a) b = e[i].b;
		else if (x == e[i].b) b = e[i].a;
		else continue;
		
		if (b == p) continue;
		
		if (used[b]) {cyc = true; continue;}
		dfs(b, x);
	}
}

typedef long long LL;

int calc(int mask)
{
	memset(num, 0, sizeof(num));
	int i;
	for (i=0; i<k; i++) if (mask & (1<<i))
	{
		num[ e[i].a ]++;
		num[ e[i].b ]++;
		
		if (num[ e[i].a ] > 2) return 0;
		if (num[ e[i].b ] > 2) return 0;
	}
	
	memset(used, 0, sizeof(used));
	MASK = mask;
	int ncomp = 0;
	
	int siz[15];	
	for (i=0; i<k; i++) if ((mask & (1<<i)) && !used[ e[i].a ])
	{	
		scomp = 0;
		cyc = false;
		dfs( e[i].a, -1 );
		if (cyc && scomp < n) return 0;
		siz[ncomp++] = scomp;
	}
		
//	printf("edges = \n"); for (i=0; i<k; i++) if (mask & (1<<i))
//		printf("%d %d\n",e[i].a, e[i].b);

			
	int sisa = 0;
	for (i=0; i<n; i++) if (!used[i]) sisa++;

		
	int res = fakt[sisa+ncomp];	
	for (i=0; i<ncomp; i++)
	{
		res = (res + (LL)(siz[i]-1)*fakt[sisa+ncomp-1])%MOD;
	}
	for (i=0; i<ncomp; i++)
	{
		res *= 2;
		res %= MOD;
	}
	
		
	//printf("%d %d %d %d\n",n1(mask),ncomp,sisa,res);	
	return res;
}

int main()
{
	scanf("%d",&ntc);
	int i, j;
	int a, b;
	int res;
	
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&n,&k);

		MOD = n * 2 * 9901;
		
		fakt[0] = 1;
		for (i=1; i<=n; i++) fakt[i] = (i*fakt[i-1])%MOD;
			
				
		for (i=0; i<k; i++)
		{
			scanf("%d %d",&e[i].a,&e[i].b);
			e[i].a--; e[i].b--;
		}
		
		if (n == 2)
		{
			if (k == 0) res = 1;
			else res = 0;
			
			printf("Case #%d: %d\n",tc, res);
			continue;
		}
		
		res = fakt[n];
		for (i=1; i<(1<<k); i++)
		{
			if (n1(i) % 2 == 1) res -= calc( i );
			else res += calc( i );
			
			res %= MOD;
			if (res < 0) res += MOD;
			
			//printf("%d\n",res);						
		}
		
		res /= (2*n);
		
		printf("Case #%d: %d\n",tc, res);
	}
}