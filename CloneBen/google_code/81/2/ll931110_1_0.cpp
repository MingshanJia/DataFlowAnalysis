#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mod 1000000007
#define maxn 10005
using namespace std;

int T,n,Q;
string order;
bool appear[maxn][26];
string s[maxn];
vector<int> bucket[11];
long long hash[maxn][26];
int z;

bool hashCmp(int x,int y)
{
	if (hash[x][z] != hash[y][z]) return hash[x][z] < hash[y][z];
	return x < y;
}

pair<int,int> maxPenalty(vector<int> store,int pos)
{
	if (store.empty()) return make_pair(0,n + 1);
	if (store.size() == 1) return make_pair(0,store[0]);
	
	bool flag = true;
	z = order[pos] - 'a';
	for (int i = 0; i < store.size(); i++) if (appear[store[i]][z]) flag = false;
	if (flag) return maxPenalty(store,pos + 1);
	
	sort(store.begin(),store.end(),hashCmp);

	int ans = 0,anspos = store[0];
	int LF = 0,RF = 0;
	while (LF < store.size())
	{
		z = order[pos] - 'a';
		while (RF < store.size() && hash[store[RF]][z] == hash[store[LF]][z]) RF++;
		
		vector<int> tmp;
		for (int i = LF; i < RF; i++) tmp.push_back(store[i]);
		pair<int,int> p = maxPenalty(tmp,pos + 1);
		
		z = order[pos] - 'a';
		if (!appear[store[LF]][z]) p.first++;
		if (p.first > ans || (p.first == ans && p.second < anspos))
		{
			ans = p.first;  anspos = p.second;
		}
		
		LF = RF;
	}
	
	return make_pair(ans,anspos);
}

int main()
{
	freopen("b.i1","r",stdin);
	freopen("b.o1","w",stdout);
	
	scanf("%d", &T);
	for (int it = 1; it <= T; it++)
	{
		scanf("%d %d", &n, &Q);
		for (int i = 0; i < n; i++) cin >> s[i];
		memset(appear,false,sizeof(appear));
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < s[i].size(); j++) appear[i][s[i][j] - 'a'] = true;
		  
		memset(hash,0,sizeof(hash));
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < 26; j++)
			for (int t = 0; t < s[i].size(); t++)
			{
				hash[i][j] = (2LL * hash[i][j]) % mod;
				if (s[i][t] - 'a' == j) hash[i][j] = (hash[i][j] + 1) % mod;
			}
			
		for (int i = 1; i <= 10; i++) bucket[i].clear();
		for (int i = 0; i < n; i++) bucket[s[i].size()].push_back(i);
		printf("Case #%d: ", it);
		
		while (Q--)
		{
			cin >> order;
			int ret = 0,retpos = 0;
			for (int i = 1; i <= 10; i++)
			{
				pair<int,int> p = maxPenalty(bucket[i],0);
				if (p.first > ret || (p.first == ret && p.second < retpos))
				{
					ret = p.first;  retpos = p.second;
				}
			}
			cout << s[retpos] << ' ';
		}
		cout << endl;
	}
}
