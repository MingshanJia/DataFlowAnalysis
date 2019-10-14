#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;

int tc, ntc;
bool con1[20][20];
bool con2[20][20];

int ar[8];

bool ok()
{
	int i, j;
	for (i=0; i<m; i++) for (j=0; j<m; j++)
	{
		if (con2[i][j] && !con1[ ar[i] ][ ar[j] ])
			return false;
	}
	return true;
}

int main()
{
	freopen("D-small2.in","r",stdin);
	freopen("D-small2.out","w",stdout);

	scanf("%d",&ntc);
	int i, j;
	int a, b;
	for (tc=1; tc<=ntc; tc++)
	{
		memset(con1, 0, sizeof(con1));
		memset(con2, 0, sizeof(con2));

		scanf("%d",&n);
		for (i=0; i<n-1; i++)
		{
			scanf("%d %d",&a,&b);
			a--; b--;
			con1[a][b] = con1[b][a] = true;
		}

		scanf("%d",&m);
		for (i=0; i<m-1; i++)
		{
			scanf("%d %d",&a,&b);
			a--; b--;
			con2[a][b] = con2[b][a] = true;
		}
	
		for (i=0; i<n; i++) ar[i] = i;

		bool can = false;
		do
		{
			if (ok()) 
			{
				can = true;
				break;
			}
		}while (next_permutation(ar, ar+n));
	
		printf("Case #%d: ",tc);
		if (can) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}