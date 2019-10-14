#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int T, ca;
int x[3], y[3], z[3];

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 3; ++i){
			scanf("%d%d%d", x + i, y + i, z + i);
		}
		int xmin = min({x[0], x[1], x[2]});
		int xmax = max({x[0], x[1], x[2]});
		double res = (xmax - xmin) / 6.;
		printf("Case #%d: %.10f\n", ++ca, res);
	}
	
	return 0;
}
