#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

#define modp(x) (((x)%P+P)%P)
#define mod(x,y) (((x)%(y)+(y))%(y))

int cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	int v1=a.first.first*b.first.second;
	int v2=a.first.second*b.first.first;
	if(v1<v2)return -1;
	if(v1>v2)return 1;
	if(a.second<b.second)return -1;
	if(a.second>b.second)return 1;
	return 0;
}

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int n;
		scanf("%d",&n);
		vector<pair<pair<int,int>,int> > hoge(n);
		for(int i=0;i<n;i++)scanf("%d",&hoge[i].first.first);
		for(int i=0;i<n;i++)scanf("%d",&hoge[i].first.second);
		for(int i=0;i<n;i++)hoge[i].second=i;
		
		for(int t=0;t<n;t++){
			for(int i=0;i<n-1;i++){
				if(cmp(hoge[i],hoge[i+1])==1){
					swap(hoge[i],hoge[i+1]);
				}
			}
		}
		printf("Case #%d:",casenum);
		for(int i=0;i<n;i++)printf(" %d",hoge[i].second);
		puts("");
	}
}