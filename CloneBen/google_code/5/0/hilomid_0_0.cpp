//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T,M;
unordered_map<string,int> num; int id;
vector<int> adj[200];
int sign[200]; bool has;
void check(int v){
	if(!has) return;
	for(int i=0;i<adj[v].size();i++){
		if(!sign[adj[v][i]]){
			sign[adj[v][i]]=sign[v]==1?2:1;
			check(adj[v][i]);
		}else{
			if(sign[adj[v][i]]==sign[v])
				has=false;
		}
	}
}
int main()
{
	freopen("A-small-1-attempt0.in","r",stdin);
	freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		cin>>M; string a,b;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			if(num.find(a)==num.end()) num[a]=id++;
			if(num.find(b)==num.end()) num[b]=id++;
			adj[num[a]].push_back(num[b]);
			adj[num[b]].push_back(num[a]);
		}
		has=true;
		for(int i=0;i<id;i++){
			if(!sign[i]){
				sign[i]=1;
				check(i);
			}
		}
		if(has) printf("Case #%d: Yes\n",cas);
		else printf("Case #%d: No\n",cas);
		for(int i=0;i<id;i++)
			adj[i].clear();
		id=0; num.clear(); memset(sign,0,sizeof(sign));
	}
	
	return 0;
}