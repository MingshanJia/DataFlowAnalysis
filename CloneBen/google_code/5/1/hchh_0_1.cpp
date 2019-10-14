#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;
const int maxn = 10001;

int f[maxn];
map<string, int> m;

int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

void unin(int x, int y){
	x = find(x);
	y = find(y);
	if(x != y){
		f[x] = y;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif

	int T, n;
	string a, b;
	scanf("%d", &T);
	int cnt = 0;
	for(int t=1; t<=T; t++){
		scanf("%d", &n);
		int flag = 1;

		for(int i=0; i<maxn; i++)         //初始化f[]
		f[i] = i;

		for(int i=0; i<n; i++){
			cin >> a >> b;
			if(!m[a])   m[a] = cnt++;
			if(!m[b])   m[b] = cnt++;
			if(find( m[a] ) == find( m[b] ) || find( m[a]+200 ) == find( m[b]+200 ) )       //产生矛盾的判断
				flag = 0;
			else{
				unin(m[a], m[b]+200);
				unin(m[a]+200, m[b]);
			}
		}
		printf("Case #%d: %s\n", t, flag ? "Yes" : "No");
	}
	return 0;
}
