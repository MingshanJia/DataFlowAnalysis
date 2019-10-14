#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 16;

int n , k; 
pair < int , int > a[MAXN];

int mid;
int dp[MAXN][1 << MAXN];

void read() {
	int i;
	int x , y;
		
	scanf ("%d%d",&n,&k);
	for (i=0;i<n;i++) {
		scanf ("%d%d",&x,&y);
		a[i] = make_pair ( x , y );
	}
}

int go ( int k , int mask ) {
	if ( !mask ) return 1;
	if ( !k ) return 0;
	if ( dp[k][mask] != -1 ) return dp[k][mask];
	int i , j;
	int x , y;
	int nmask;
	
	dp[k][mask] = 0;
	
	for (i=0;i<n;i++)
		if ( mask & (1 << i) )
			break;
	x = a[i].first;
	y = a[i].second;
	
	for (i=0;i<n;i++) 
		if ( (mask & (1 << i)) 
				   && a[i].first <= x + mid 
				   && a[i].second >= y - mid
				   && a[i].second <= y + mid ) {
				   		nmask = mask;
						
						for (j=0;j<n;j++)
							if ( mask & (1 << j) 
										&& a[j].first >= x && a[j].first <= x + mid
										&& a[j].second >= a[i].second && a[j].second <= a[i].second + mid )
											nmask ^= 1 << j;
						
						dp[k][mask] |= go ( k - 1 , nmask );
				   }
				   
	return dp[k][mask];
}

void solve() {
	int l , r;
	
	sort ( a , a + n );
	
	l = 1;
	r = 64000;
	
	while ( l < r ) {
		mid = l + (r - l) / 2;
		
		memset ( dp , -1 , sizeof dp );
		if ( go ( k , (1 << n) - 1 ) )
			r = mid;
		else
			l = mid + 1;
	}
	
	printf ("%d\n",l);
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
