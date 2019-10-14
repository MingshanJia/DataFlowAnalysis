#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include <string>
#include <stack>
using namespace std;
#define TEST_SMALL
//#define TEST_BIG
map< int, int > vis;
int ha[110];
map < string , int > M;
vector < vector < int >  > E;
bool judge(int now){
	bool result = false;
	for (int i = 0; i < E[now].size(); i++){
		int p = E[now][i];
		if (ha[p] == 0){
			ha[p] = 3 - ha[now];
			bool res = judge(p);
			if (res){
				return res;
			}
		}else{
			if (ha[p] == ha[now]){
				return true;
			}
		}
	}
	return result;
}
int main(){

#ifndef TEST_SMALL
	freopen("A-small-1-attempt0.in", "r", stdin);
	freopen("As.out", "w", stdout);
#endif
#ifndef TEST_BIG
	freopen("A-small-2-attempt0.in", "r", stdin);
	freopen("Al.out", "w", stdout);
#endif	
	int cas;
	int n;
	scanf("%d", &cas);
	for(int t = 1; t <= cas; t++){
		scanf("%d", &n);
		M.clear();
		E.clear();
		E.resize(101);
		int id = 0;
		for(int i = 0; i < n; i++){
			char name[100];
			scanf("%s", name);
			int id1, id2;
			if (M.count(name)){
				id1 = M[name];
			}else{
				M[name] = ++id;
				id1 = id;
			}
			scanf("%s", name);
			if (M.count(name)){
				id2 = M[name];
			}else{
				M[name] = ++id;
				id2 = id;
			}
			E[id1].push_back(id2);
			E[id2].push_back(id1);
		}
		memset(ha, 0, sizeof(ha));
		bool res = false;
		for(int i = 1; i <= n ; i++){
			if (ha[i] == 0){
				ha[i] = 1;
				res = judge(i);
				if (res)
					break;
			}
		}
		if (!res){
			printf("Case #%d: Yes\n", t);
		}else{
			printf("Case #%d: No\n", t);
		}
	}
}
