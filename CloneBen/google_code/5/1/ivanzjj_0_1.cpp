#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <queue>
#include <math.h>
#include <bitset>
#include <climits>
#include <sstream>
#include <unordered_map>
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int,int> pii;
const double pi = atan (1.0) * 4;
void Main ();
int main (){
	freopen ("F:\\C++\\Google\\Round_Test\\A-small-2-attempt0.in","r",stdin);
	freopen ("F:\\C++\\Google\\Round_Test\\A-small-2-attempt0.out","w",stdout);
	Main ();	return 0;
}
int N;
vector<int>  head[220];

void add (int a, int b){
	head[a].push_back (b);
	head[b].push_back (a);
}

int vis[220];

bool dfs (int now, int fa){
	for (int i=0;i<head[now].size ();i++){
		int u = head[now][i];
		if (vis[u] == -1){
			vis[u] = 1 - vis[now];
			if (!dfs (u, now))	return false;
		}
		else if (vis[u] == vis[now])	return false;
	}
	return true;
}

bool solve (){
	memset (vis, -1, sizeof(vis));
	vis[1] = 0;
	return dfs (1,0);
}

void Main (){
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf ("%d", &N);
		map <string,int> mp;
		vector<pair<string,string>> vec;
		string a,b;
		
		for (int i=0;i<N;i++){
			cin >> a >> b;
			vec.push_back (make_pair(a,b));
			mp[a] = mp[b] = 1;
		}
		map<string,int>::iterator it = mp.begin();
		int cnt = 1;
		for (; it!= mp.end();it++){
			it->second = cnt++;
		}
		for (int i=1;i<cnt;i++)	head[i].clear();
		
		for (int i=0;i<N;i++){
			add ( mp[vec[i].first], mp[vec[i].second] );
		}
		printf ("Case #%d: ",cas);
		if (solve ())	printf ("Yes\n");
		else			printf ("No\n");
	}
}