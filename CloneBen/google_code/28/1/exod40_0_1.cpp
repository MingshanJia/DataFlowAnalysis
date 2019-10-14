#include <cstdio>
#include <algorithm>

int a , b;
int dp[1 << 12][1 << 12];

void read() {
	scanf ("%d%d",&a,&b);
}

int go ( int a , int b ) {
	if ( a + b == 1 ) return b;
	if ( dp[a][b] != -1 ) return dp[a][b];
	dp[a][b] = 2;
	
	if ( a > 1 )
		dp[a][b] = go ( a - 1 , b );
	if ( b > 1 )
		dp[a][b] = go ( a + 1 , b - 2 );
	if ( a && b ) 
		dp[a][b] = go ( a - 1 , b );
	
	return dp[a][b];
}

void solve() {
	if ( b & 1 )
		printf ("BLACK\n");
	else
		printf ("WHITE\n");
}

int main() {
	int i , k;
	
	scanf ("%d",&k);
	
	memset ( dp , -1 , sizeof dp );
	for (i=1;i<=k;i++) {
		printf ("Case #%d: ",i);
		read();
		solve();
	}
	
	return 0;
}
