#include<map>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 20005;


map<string,int> a;
string b[N];
int sz;

int link[N],ind[N];

string s,t;
int main()
{
	int T,CAS=0;
	int n;

	for(cin>>T;CAS<T;CAS++)
	{
		sz=0;
		a.clear();
		cin>>n;
		memset(ind,0,sizeof(ind));
		memset(link,0,sizeof(link));
		for(int i=1,id1,id2;i<=n;i++)
		{
			cin>>s>>t;
			if(a.find(s)==a.end())
			{
				id1=++sz;
				a[s]=sz;
				b[sz]=s;
			}
			else id1=a[s];
			if(a.find(t)==a.end())
			{
				id2=++sz;
				a[t]=sz;
				b[sz]=t;
			}
			else id2=a[t];
			link[id1]=id2;
			ind[id2]++;
		}
		int st=1;
		for(st=1;st<=sz;st++) if(!ind[st]) break;
		cout<<"Case #"<<CAS+1<<":";
		while(link[st]!=0)
		{
			cout<<' '<<b[st]<<'-'<<b[link[st]];
			st=link[st];
		}
		cout<<endl;
	}
	return 0;
}
/*
1
2

A
B
B
C

*/
