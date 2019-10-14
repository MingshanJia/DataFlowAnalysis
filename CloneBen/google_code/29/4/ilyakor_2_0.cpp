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

int64 a[200][200];

int main()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<200;i++){
		for(int j=1;j<200;j++){
			a[i][j]=a[i-1][j]+a[i-1][j-1]+1LL;
			a[i][j]=min(a[i][j],(1LL<<32LL));
		}
	}
/*	for(int i=0;i<200;i++){
		for(int j=0;j<200;j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}*/
	int nc;
	cin >> nc;
	for(int ic=0;ic<nc;ic++){
		int f,d,b;
		cin >> f >> d >> b;
		printf("Case #%d: ",ic+1);
		int64 cur=a[d][b];
		if(cur>=(1LL<<32LL)) cur=-1;
		cout << cur << " ";
		int md=150,mb=150;
		for(int i=0;i<200;i++)
			for(int j=0;j<200;j++){
				if(a[i][j]>=f){
					if(i==d) mb=min(mb,j);
					if(j==b) md=min(md,i);
				}
			}
		cout << md << " " << mb << "\n";
	}
	return 0;
}
