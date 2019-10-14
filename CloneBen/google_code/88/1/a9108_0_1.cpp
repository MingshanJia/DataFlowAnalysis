//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

char a[60][60];
int i,j,k,l,o,p,n,m;

int check2(int i,int j,int di,int dj,char ch){
	int q;
	for (q=0;;q++){
		if (i<0||j<0||i>=n||j>=n) break;
		if (a[i][j]!=ch) break;
		i+=di,j+=dj;
	}
	return q;
}

int count(char ch){
	int q,w,e,r,ans=0;
	for (q=0;q<n;q++){
		e=r=0;
		for (w=0;w<n;w++){
			if (a[q][w]==ch) e++;
			else e=0;
			if (a[w][q]==ch) r++;
			else r=0;
			ans=max(ans,e);
			ans=max(ans,r);
		}
	}
	for (q=0;q<n;q++)
	for (w=0;w<n;w++){
		ans=max(check2(q,w,-1,-1,ch),ans);
		ans=max(check2(q,w,-1,1,ch),ans);
		ans=max(check2(q,w,1,-1,ch),ans);
		ans=max(check2(q,w,1,1,ch),ans);
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&o);
	for (T=1;T<=o;T++){
		printf("Case #%d: ",T);
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++) scanf("%s",a[i]);
		for (i=0;i<n;i++){
			k=n-1;
			for (j=n-1;j>=0;j--){
				if (a[i][j]=='.') continue;
				a[i][k]=a[i][j];
				k--;
			}
			for (;k>=0;k--) a[i][k]='.';
		}
		if (count('R')>=m){
			if (count('B')>=m) printf("Both\n");
			else printf("Red\n");
		}
		else {
			if (count('B')>=m) printf("Blue\n");
			else printf("Neither\n");
		}
	}
    return 0;
}
