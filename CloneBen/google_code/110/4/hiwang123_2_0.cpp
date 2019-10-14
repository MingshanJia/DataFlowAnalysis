#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
int sol(int g){
	int i;
	double a=0;
	for(i=9000;i>0;i-=g){
		a+=log10(i);
	}
	return (int)ceil(a);
}
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		scanf("%d",&n);
		int l=1,r=8999;
		if(n<5){
			printf("Case #%d: ...\n",hh);
			continue;
		} 
		while(l<=r){
			int mid=(l+r)/2;
			int e=sol(mid);
		//	printf("%d %d\n",mid,e);
			if(e<n) r=mid-1;  //too small
			else l=mid+1;
		}
		int i;
		printf("Case #%d: IT'S OVER 9000",hh);
		//printf("%d\n",l);
		for(i=0;i<l;i++)
		  printf("!");
		printf("\n");
	}
	return 0;
}

