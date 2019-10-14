#include <cstdio>
#include <algorithm>
using namespace std;

int n , k;
int a[16];
int f[16][16];

void read() {
	memset ( f , 0 , sizeof f );
	int i;
	int x , y;
	
	scanf ("%d%d",&n,&k);
	for (i=1;i<=k;i++) {
		scanf ("%d%d",&x,&y);
		f[x][y] = f[y][x] = 1;
	}
}

void solve() {
	int i;
	int ans = 0;
	
	for (i=1;i<=n;i++) a[i] = i;
	
	do {
		a[n + 1] = a[1];
		for (i=2;i<=n+1;i++)
			if ( f[ a[i - 1] ][ a[i] ] ) break;
		if ( i == n + 2 ) ++ ans;
	} while ( next_permutation ( a + 2 , a + n + 1 ) );
	
	ans /= 2;
	printf ("%d\n",ans%9901);
}

int main() {
	int i , k;
	
	scanf ("%d",&k);
	
	for (i=1;i<=k;i++) {
		printf ("Case #%d: ",i);
		read();
		solve();
	}
	
	return 0;
}
