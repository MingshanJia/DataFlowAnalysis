#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cctype>

#define int64 long long
#define ii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

template<class T> T abs(T x){return x>0 ? x:(-x);}
template<class T> T sqr(T x){return x*x;}


map<ii,vi> M;
int mx,my,Mx,My;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int val[]={2,8,1,4};

int main()
{
	int nc;
	cin >> nc;
	for(int ic=0;ic<nc;ic++){
		M.clear();
		mx=my=Mx=My=0;
		string s[2];
		cin >> s[0] >> s[1];
		int x=0,y=0,dir=0;
		for(int tmp=0;tmp<2;tmp++){
			for(int i=1;i<sz(s[tmp]);i++){
				mx=min(mx,x);
				my=min(my,y);
				Mx=max(Mx,x);
				My=max(My,y);
				if(M.find(ii(x,y))==M.end())
					M[ii(x,y)]=vi(4,-1);
				vi& v=M[ii(x,y)];
				char c=s[tmp][i];
				if(c=='W'){
					v[dir]=1;
					if(s[tmp][i-1]!='L') v[(dir+1)%4]=0;
					if(i<sz(s[tmp])-1){
						x+=dx[dir];
						y+=dy[dir];
						vi& w=M[ii(x,y)];
						if(sz(w)==0) w=vi(4,-1);
						w[(dir+2)%4]=1;
					}
				} else
				if(c=='R'){
					v[dir]=0;
					v[(dir+1)%4]=0;
					dir=(dir+3)%4;
				} else
				if(c=='L'){
					v[(dir+1)%4]=1;
					dir=(dir+1)%4;
				}
			}
			dir=(dir+2)%4;
		}
		cout << "Case #" << ic+1 << ":\n";
		int n=Mx-mx+1;
		int m=My-my+1;
		for(int j=my;j<=My;j++){
			for(int i=mx;i<=Mx;i++){
				vi& v=M[ii(i,j)];
				int cur=0;
				for(int k=0;k<4;k++){
					if(v[k]==1)
						cur+=val[k];
				}
				char c;
				if(cur<10) c='0'+cur;
				else c='a'+(cur-10);
				printf("%c",c);
			}
			printf("\n");
		}
	}
	return 0;
}
