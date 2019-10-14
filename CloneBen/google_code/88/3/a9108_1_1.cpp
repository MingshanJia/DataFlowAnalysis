//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int a[200];
int f[200][257];
int i,j,k,l,o,p,n,m;

/*void initmin(int i){
	int q,w,e=1;
	for (q=0;q<256;q++) t[q][0]=f[i][q];
	for (w=1;w<8;w++){
		for (q=0;q<256;q++){
			t[q][w]=t[q][w-1];
			if (q+e<256) t[q][w]=min(t[q][w],t[q+e][w-1]);
		}
		e*=2;
	}
}

int getmin(int l,int r){
	int q=(r+1-l),w,e=1;
	for (w=0;e<q;w++)e*=2;
	w--;e/=2;
	return min(t[l][w],t[r-e][w]);
}*/

int main(){
	int T;
	scanf("%d",&o);
	for (T=1;T<=o;T++){
		printf("Case #%d: ",T);
		int wd,wi;
		scanf("%d%d%d%d",&wd,&wi,&m,&n);
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		f[0][256]=wd;
		for (i=0;i<256;i++) f[0][i]=abs(i-a[0]);
		for (i=1;i<n;i++){
			f[i][256]=f[i-1][256]+wd;
			for (j=0;j<256;j++) f[i][j]=f[i-1][256]+abs(j-a[i]);
			//for (j=0;j<256;j++) f[i][j]=min(f[i][j],abs(j-a[i])+getmin(max(0,j-m),min(255,j+m)));
			//initmin(i);
			for (j=0;j<256;j++)
			for (k=0;k<256;k++){
				if (m==0&&j!=k) continue;
				if (m==0) l=0;
				else l=max(0,(abs(j-k)-1)/m);
				f[i][j]=min(f[i][j],l*wi+abs(j-a[i])+f[i-1][k]);
			}
			for (j=0;j<256;j++) f[i][j]=min(f[i][j],f[i-1][j]+wd);
		}
		//for (i=0;i<n;i++) for (j=0;j<10;j++) printf("%d %d:%d\n",i,j,f[i][j]);
		p=wd*n;
		for (i=0;i<257;i++) p=min(p,f[n-1][i]);
		printf("%d\n",p);
	}
    return 0;
}
