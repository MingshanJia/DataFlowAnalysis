#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		int n;
		scanf("%d",&n);
		int pat[n];
		int init=0;
		for(int i=0;i<n;i++){
			char buf[30];
			scanf("%s",buf);
			pat[i]=0;
			for(int j=0;j<n;j++)pat[i]=pat[i]*2+(buf[j]-'0');
			init+=__builtin_popcount(pat[i]);
		}
		
		for(;;){
			bool progress=false;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(pat[i]==pat[j] || (pat[i]&pat[j])==0)continue;
					pat[i]=pat[j]=(pat[i]|pat[j]);
					progress=true;
				}
			}
			if(!progress)break;
		}
		int fin=0;
		for(int i=0;i<n;i++)fin+=__builtin_popcount(pat[i]);
		printf("%d\n",fin-init);
	}
}