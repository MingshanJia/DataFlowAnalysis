#include <cstdio>
#include <cstring>

const int N=201;
int a[N][N],b[N][N];

int main(){
	int tt,cas,i,j,x1,y1,x2,y2,r;
	scanf("%d",&tt);
	for (cas=1;cas<=tt;cas++){
		scanf("%d",&r);
		memset(a,0,sizeof(a));
		while (r--){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for (i=x1;i<=x2;i++)
				for (j=y1;j<=y2;j++)
					a[i][j]=1;
		}
		int t=0,cnt=0;
		for (i=1;i<N;i++)
			for (j=1;j<N;j++)
				if (a[i][j]==1) cnt++;
		while (cnt>0){
			for (i=1;i<N;i++)
				for (j=1;j<N;j++)
					if (a[i][j]==1){
						if (a[i-1][j]==0&&a[i][j-1]==0)
							b[i][j]=0;
						else b[i][j]=1;
					}
					else
					if (a[i][j]==0){
						if (a[i-1][j]==1&&a[i][j-1]==1)
							b[i][j]=1;
						else b[i][j]=0;
					}
			cnt=0;
			for (i=1;i<N;i++)
				for (j=1;j<N;j++)
					if (b[i][j]) cnt++;
			memcpy(a,b,sizeof(a));
			t++;
		}
		printf("Case #%d: %d\n",cas,t);
	}
	return 0;
}
