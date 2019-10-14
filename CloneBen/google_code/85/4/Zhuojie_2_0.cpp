#include<cstdio>
#include<cstring>

using namespace std;

int T,n,I,a,b,c,d,i,j,k,ans;
bool bt;
int map[110][110];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		printf("Case #%d: ",++I);
		memset(map,0,sizeof map);
		for (i=0;i<n;++i){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			for (j=a;j<=c;++j)
			    for (k=b;k<=d;++k)
			        map[j][k]=1;
		}
		for (ans=0;;++ans){
			bt=0;
			for (i=0;!bt && i<=100;++i)
			    for (j=0;j<=100;++j)
			        if (map[i][j]) {bt=1;break;}
			if (!bt) break;
			for (i=100;i>0;--i)
			    for (j=100;j>0;--j)
			        if (map[i-1][j] && map[i][j-1]) map[i][j]=1;
			        else if (!(map[i-1][j] || map[i][j-1])) map[i][j]=0;
		}
		printf("%d\n",ans);
	}
}
