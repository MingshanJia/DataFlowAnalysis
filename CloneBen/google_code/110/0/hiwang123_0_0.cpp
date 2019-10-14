#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		scanf("%d",&n);
		char s[8005];
		scanf("%s",s);
		int i,j;
		printf("Case #%d: ",hh);
		for(i=0;i<n;i++){
			int g=0;
			for(j=i*8;j<(i+1)*8;j++){
				g*=2;
				if(s[j]=='I') g++; 
				//printf("%d\n",g);
			}
			printf("%c",(char)g);
		} 
		printf("\n");
	}
	return 0;
}

