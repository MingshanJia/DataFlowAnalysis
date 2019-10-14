#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>

#define L 201
typedef long long ll;
std::map<std::string, int> m1;
int id;

std::vector<int> graph[L];
int color[L];
bool visit[L];

bool dfs(int u){
	bool ret=1;
	for (int i = 0; i < graph[u].size(); ++i)
	{
		int v=graph[u][i];
		if (!visit[v])
		{
			visit[v]=1;
			color[v]=3 - color[u];
			ret&=dfs(v);
			if(!ret)return 0;
		}else{
			// std::cerr << u << " " << v << "\n";
			// std::cerr << color[u] << " " << color[v] << "\n";
			if(color[u]+color[v]!=3)return 0;
		}
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(0);
	int t,n,m;

	std::cin >> t;

	for (int j = 1; j <=t; ++j)
	{
		std::cin >> n;
		for (int i = 0; i < L; ++i)graph[i].clear();
		m1.clear(); id=1;
		std::string name1,name2;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> name1 >> name2;
			if (!m1[name1])
			{
				m1[name1]=id++;
			}
			if (!m1[name2])
			{
				m1[name2]=id++;
			}
			int u =m1[name1], v=m1[name2];
			// std::cerr << u << " " << v << "\n";			
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		std::fill(visit,visit+L,0);
		std::fill(color,color+L,0);
		bool ans=1;
		for (int i = 1; i < id; ++i)
		{
			if (!visit[i])
			{
				visit[i]=1;
				color[i]=1;
				ans&=dfs(i);
				// std::cerr << ans << "\n";
				if(!ans)break;
			}
		}
		std::cout << "Case #"<< j << ": " << (ans?"Yes\n":"No\n") ;

	}

	

	return 0;
}