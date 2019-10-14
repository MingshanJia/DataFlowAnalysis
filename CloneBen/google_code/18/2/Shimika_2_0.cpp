#include <queue>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int a[22][22][55],n[22][22][55],x,y,z,h,c,mx,p[19999],m[10002][10002],v[19999];
char t1[22];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int xi, int yi){
	int i;
	for(i=0;i<4;i++){
		if(a[xi+dx[i]][yi+dy[i]][h]+n[xi+dx[i]][yi+dy[i]][h]==0){
			n[xi+dx[i]][yi+dy[i]][h]=c;
			dfs(xi+dx[i],yi+dy[i]);
		}
	}
}

bool bfs(){
	queue<int> q;
	memset(v,0,sizeof(v));
	memset(p,0,sizeof(p));
	v[1]=1;
	q.push(1);
	int xi,i;
	do{
		xi=q.front(); q.pop();
		if(xi==c*2+2){return true;}
		for(i=1;i<=c*2+2;i++){
			if(m[xi][i]>0 && !v[i]){
				v[i]=1;
				if(i==c*2+2){
					p[c*2+2]=xi;
					return true;
				}
				p[i]=xi;
				q.push(i);
			}
		}
	}while(q.size());
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	int t,q,i,j,k;
	scanf("%d",&t);
	for(i=0;i<=21;i++){
		for(j=0;j<=21;j++){
			for(k=0;k<=51;k++){
				a[i][j][k]=1;
			}
		}
	}
	FILE *fp2=fopen("output.txt","w");
	for(q=1;q<=t;q++){
		mx=0;c=0;x=y=z=h=0;
		scanf("%d %d %d",&x,&y,&z);
		memset(n,0,sizeof(n));
		memset(m,0,sizeof(m));
		memset(a,-1,sizeof(a));
		for(k=1;k<=z;k++){
			h=k;
			for(i=1;i<=x;i++){
				scanf("%s",t1+1);
				for(j=1;j<=y;j++){
					if(t1[j]=='#'){
						a[i][j][k]=1;
					}else{
						a[i][j][k]=0;
					}
				}
			}
			for(i=1;i<=x;i++){
				for(j=1;j<=y;j++){
					if(!n[i][j][k] && !a[i][j][k]){
						n[i][j][k]=++c;
						dfs(i,j);
					}
				}
			}
			/*printf("%d\n",c);
			for(i=1;i<=x;i++){
				for(j=1;j<=y;j++){
					printf("%d",n[i][j][k]);
				}printf("\n");
			}printf("\n");*/
		}
		for(i=1;i<=c;i++){
			m[1][i+1]=1;
			m[1+c+i][2+c*2]=1;
		}
		for(k=2;k<=z;k++){
			for(i=1;i<=x;i++){
				for(j=1;j<=y;j++){
					if(n[i][j][k] && n[i][j][k-1]){
						m[1+n[i][j][k]][1+c+n[i][j][k-1]]=1;
						m[1+n[i][j][k-1]][1+c+n[i][j][k]]=1;
					}
				}
			}
		}
		/*for(i=1;i<=c*2+2;i++){
			for(j=1;j<=c*2+2;j++){
				printf("%d ",m[i][j]);
			}printf("\n");
		}*/
		int xi,mk;
		for(;bfs();){
			xi=c*2+2; mk=0;
			do{
				if(m[p[xi]][xi]>mk){
					mk=m[p[xi]][xi];
				}
				xi=p[xi];
			}while(xi>0);
			mx+=mk;
			xi=c*2+2;
			do{
				m[p[xi]][xi]-=mk;
				m[xi][p[xi]]+=mk;
				xi=p[xi];
			}while(xi>0);
		}

		//printf("%d\n",mx);
		fprintf(fp2,"Case #%d: %d\n",q,c-mx/2);
		//printf("Case #%d: %d\n",q,c-mx/2);
		//fclose(fp2);
	}
	return 0;
}
