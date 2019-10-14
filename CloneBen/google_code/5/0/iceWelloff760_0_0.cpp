#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define ULL unsigned long long int
#define MP make_pair
#define PB push_back
#define LD long double
#define MOD 1000000007

void input(){
	freopen("A-small-1-attempt0.in","r",stdin);
   	freopen("A-small-1-attempt0.out","w",stdout);
}


int vis[250];
vector<int>v[250];
map<string,int>mymap;

int  dfs(int ver,int id){
	int i,ans=0;

	for(i=0;i<v[ver].size();i++){
		if(vis[v[ver][i]]==-1){
			vis[v[ver][i]]=(!id);
			ans=dfs(v[ver][i],(!id));
			if(ans==1) return 1;
		}
		else{
			if(vis[v[ver][i]]!=(!id))
			return 1;
		}
	}
	
	return 0;
}






int main(){
input();
LL id1,id2,j,n,ans,i,t,test=1;
string str1,str2;

cin>>t;
while(t--){
	cin>>n;
	cout<<"Case #"<<test<<": ";test++;
	for(i=0;i<n;i++){
		cin>>str1>>str2;
		if(mymap.find(str1)!=mymap.end()){
			id1=mymap[str1];
		}
		else{
			id1=mymap.size();
			mymap[str1]=id1;
		}
		if(mymap.find(str2)!=mymap.end()){
			id2=mymap[str2];
		}
		else{
			id2=mymap.size();
			mymap[str2]=id2;
		}
		v[id1].PB(id2);
		v[id2].PB(id1);
	}
	for(i=0;i<mymap.size();i++){
		memset(vis,-1,sizeof(vis));ans=0;
		ans=dfs(i,0);vis[i]=0;
		for(j=0;j<mymap.size();j++)
			if(vis[j]==-1) break;
		if(ans==0 && j==mymap.size())
		break;
	}
	if(i!=mymap.size()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(i=0;i<mymap.size();i++) v[i].clear();
	mymap.clear();
	
}
return 0;
}
