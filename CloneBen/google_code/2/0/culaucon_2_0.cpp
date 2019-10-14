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
#include <queue>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long LL;

int n, m, p;
int a[110][110];
int INF=1e9;
int s[110];
double f[110];
double t[110][110], cur[110][110];
double u[110][110], v[110][110], r[110][110];

void matmul(int un, int um, int vm) {
	for (int i=0;i<un;i++)
		for (int j=0;j<vm;j++) {
			r[i][j]=0;
			for (int k=0;k<um;k++)
				r[i][j]+=u[i][k]*v[k][j];
		}
}

void matpow(int pow) {
	if (pow==1) {
		memcpy(cur, t, sizeof(t));
		return;
	}
	int sig=0;
	for (;(1LL<<sig)<=pow;sig++);sig--;
//	memcpy(cur, t, sizeof(t));
	memset(cur,0,sizeof(cur));
	for (int i=0;i<110;i++) cur[i][i]=1;
//	cout<<sig<<" "<<pow<<endl;
	while (sig>=0) {
		if (((1LL<<sig)&pow)>0) {
			memcpy(u, cur, sizeof(cur));
			memcpy(v, t, sizeof(t));
			matmul(n+1, n+1, n+1);
			memcpy(cur, r, sizeof(r));
		}
		if (sig>=1) {
			memcpy(u, cur, sizeof(cur));
			memcpy(v, cur, sizeof(cur));
			matmul(n+1, n+1, n+1);
			memcpy(cur, r, sizeof(r));
		}
		sig--;
	}
}

int main() {
	freopen("catch_them_all.in","r",stdin);
	freopen("catch_them_all.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		cin>>n>>m>>p;
		for (int i=0;i<110;i++)
			for (int j=0;j<110;j++) a[i][j]=INF;
		
		for (int i=0;i<m;i++) {
			int x, y, z;
			cin>>x>>y>>z;
			a[x-1][y-1]=z;
			a[y-1][x-1]=z;
		}
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
		
		for (int i=0;i<n;i++) {
			s[i]=0;
			for (int j=0;j<n;j++)
				if (i!=j) s[i]+=a[i][j];
		}
		
		f[0]=1;
		for (int i=0;i<n;i++) f[i+1]=s[i]*1./(n-1);
		
		for (int i=0;i<n+1;i++)
			for (int j=0;j<n+1;j++)
				if (j==0) t[i][j]=(i==0?1:0);
				else if (i==0) t[i][j]=s[j-1]*1./(n-1);
				else if (i==j) t[i][j]=0;
				else t[i][j]=1./(n-1);
				
		/*for (int i=0;i<n+1;i++) {
			for (int j=0;j<n+1;j++) cout<<t[i][j]<<" ";cout<<endl;
		}cout<<endl<<"_______"<<endl;*/
		
		double ret=f[1];
		if (p>1) {
			matpow(p-1);
			
			u[0][0]=1;
			for (int i=0;i<n+1;i++) u[0][i]=f[i];
			
			memcpy(v, cur, sizeof(cur));
			matmul(1, n+1, n+1);
			ret=r[0][1];
			//for (int i=0;i<n+1;i++) cout<<r[0][i]<<" ";
		}
		
		printf("Case #%d: %.10lf\n", nt++, ret);
	}
}
