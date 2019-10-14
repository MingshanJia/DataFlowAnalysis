#include <bits/stdc++.h>
using namespace std;
typedef double ld;
struct mat{
	int r,c;
	vector <vector<ld> >m;
	mat(int _r, int _c){
		for(int x=0;x<_r;x++){
			m.push_back(vector<ld>(_c,0.0));
		}
		r=_r;
		c=_c;
	}
	void print(){
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				printf("%lf ",m[x][y]);
			}
			printf("\n");
		}
	}
};
typedef struct mat mat;
mat operator+(mat a, mat b){
	for(int x=0;x<a.r;x++){
		for(int y=0;y<a.c;y++){
			a.m[x][y]=(a.m[x][y]+b.m[x][y]);
		}
	}
	return a;
}
mat operator-(mat a, mat b){
	for(int x=0;x<a.r;x++){
		for(int y=0;y<a.c;y++){
			a.m[x][y]=(a.m[x][y]-b.m[x][y]);
		}
	}
	return a;
}
mat operator*(mat a, mat b){
	mat c=mat(a.r,b.c);
	for(int x=0;x<a.r;x++){
		for(int y=0;y<b.c;y++){
			for(int z=0;z<a.c;z++){
				c.m[x][y]=(c.m[x][y]+a.m[x][z]*b.m[z][y]);
			}
		}
	}
	return c;
}
mat matpow(mat b, int e){
	if(e==0){
		mat iden=mat(b.r,b.c);
		for(int x=0;x<b.r;x++) iden.m[x][x]=1.0;
		return iden;
	}
	if(e==1) return b;
	mat half=matpow(b,e>>1);
	half=half*half;
	if(e&1) half=half*b;
	return half;
}
int t,v,e,p,adj[105][105],p1,p2,w;
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%d %d %d",&v,&e,&p);
		for(int x=0;x<v;x++){
			for(int y=0;y<v;y++){
				adj[x][y]=(1<<29);
			}
		}
		for(int x=0;x<v;x++) adj[x][x]=0;
		for(int x=0;x<e;x++){
			scanf("%d %d %d",&p1,&p2,&w);
			adj[p1-1][p2-1]=adj[p2-1][p1-1]=w;
		}
		for(int k=0;k<v;k++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
				}
			}
		}
		ld ans=0.0,d0=0.0,dn0=0.0;
		for(int x=0;x<v;x++){
			for(int y=0;y<v;y++){
				if(x==0) d0+=ld(adj[x][y]);
				else dn0+=ld(adj[x][y]); 
			}
		}
		mat dp=mat(3,3);
		dp.m[0][0]=1.0;
		dp.m[0][2]=1.0;
		dp.m[1][1]=ld(v-2)/ld(v-1);
		dp.m[1][2]=1.0/ld(v-1);
		dp.m[2][1]=1.0;
		mat dp2=matpow(dp,p-1);
		ans+=d0*(dp2.m[0][1]+ld(v-1));
		mat dp3=dp2*dp;
		ans+=dn0*dp3.m[0][1];
		printf("Case #%d: %.6lf\n",tc,ans/ld(v-1)/ld(v-1));
	}
}
