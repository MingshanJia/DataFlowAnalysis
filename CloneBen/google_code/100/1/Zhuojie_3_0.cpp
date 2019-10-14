#include<cstdio>
#include<cstring>
#include<algorithm>
#define L 100
using namespace std;

int T,n,i,m,a,b,j,I;
int bmap[L][L],smap[L][L],xl[L];
bool bt;

main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(bmap,0,sizeof bmap);
		for (i=0;i<n-1;++i) {
			scanf("%d %d",&a,&b);
			bmap[a][b]=bmap[b][a]=1;
		}
		scanf("%d",&m);
		memset(smap,0,sizeof smap);
		for (i=0;i<m-1;++i){
			scanf("%d%d",&a,&b);
			smap[a][b]=smap[b][a]=1;
		}
		for (i=1;i<=n;++i) xl[i]=i;
		bool bt=false;
		do{
			bool bj=true;
			for (i=1;i<=m;++i)
			    for (j=1;j<=m;++j)
			        if (smap[i][j] && !bmap[xl[i]][xl[j]]){
						bj=false;
						break;
					}
			if (bj) {
				bt=true;break;
			}
		}while (next_permutation(xl+1,xl+n+1));
		printf("Case #%d: ",++I);
		if (bt) printf("YES\n");
		else printf("NO\n");
	}
}
