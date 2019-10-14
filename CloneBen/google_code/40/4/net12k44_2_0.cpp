#include <bits/stdc++.h>
using namespace std;

const int limit = 50 + 5;
const double pi = 3.14159265358979323846;
const int unit = 10000;
int a[limit];

int read(){
	int a, b;
	scanf("%d.%d",&a,&b);
	return a*unit + b;
}


void solve(){
	int n, K; scanf("%d%d",&n,&K);
	int extra = read();
	for(int i = 0; i < n; ++i)
		a[i] = read();
	
	int total = extra;
	
	while (extra > 0) {
		int cur = 0;
		for(int i = 1; i < n; ++i){
			if (a[i] < a[cur])
				cur = i;
		}
		extra--;
		a[cur]++;
	}
	
	for(int i = 0; i < n; ++i) a[i] = min(a[i], unit);
	double res = 1;
	for(int i = 0; i < n; ++i)
		res = res * a[i] / unit;
	
	printf("%.8f\n", res);
		
	
	
}

int main(){
	freopen("file.out","w",stdout);
	
	int test; scanf("%d",&test);	
	for(int t = 1; t <= test; ++t){
		printf("Case #%d: ", t);
		solve();
	}
	
}