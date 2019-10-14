#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
map<string,int> mat;
int T;
vector<int> E[1000];
int code(char ss[]){
	if (mat.count(ss)==0)
		mat[ss] = T++;
	return mat[ss];
}
int visit[1000],color[1000];
int fail;
void dfs(int now,int c){
	visit[now] = 1;
	color[now] = c;
	for (int i=0;i<E[now].size();i++)
		if (!visit[E[now][i]])
			dfs(E[now][i],c^1);
		else {
			if (color[E[now][i]]==c)
				fail = 1;
		}
}
int main(){
	int tt;
	freopen("A-small-1-attempt0.in","r",stdin);
	freopen("A.txt","w",stdout);
	scanf("%d",&tt);
	int N,i;
	char str1[1000],str2[1000];
	for (int tcas = 1;tcas<=tt;tcas++){
		scanf("%d",&N);
		T = 1;
		mat.clear();
		for (i=0;i<=2*N;i++)
			E[i].clear();
		for (i=0;i<N;i++){
			scanf("%s%s",str1,str2);
			int a = code(str1), b =code(str2);
			E[a].push_back(b);
			E[b].push_back(a);
		}

		for (i=1;i<T;i++)
			visit[i] = 0;
		fail = 0;
		for (i=1;i<T;i++)
			if (!visit[i])
				dfs(i,0);
		printf("Case #%d: %s\n",tcas, fail?"No":"Yes");
	}
}



