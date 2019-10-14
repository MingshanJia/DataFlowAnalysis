#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

char ch[1000];

int main(void){
	int T;
	scanf("%d",&T);
	for(int casenum=1;casenum<=T;casenum++){
		int i,j,k;
		int n,m;
		vector<string> word;
		scanf("%d %d ",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",ch);
			word.push_back(string(ch));
		}
		vector<vector<int> > hash(n,vector<int>(26));
		for(i=0;i<n;i++){
			for(j='a';j<='z';j++){
				int a=0;
				for(k=0;k<word[i].size();k++){
					if(word[i][k]==j)a|=(1<<k);
				}
				hash[i][j-'a']=a;
				//printf("%d %d : %d\n",i,j-'a',hash[i][j]);
			}
		}
		printf("Case #%d:",casenum);
		for(int mnum=0;mnum<m;mnum++){
			scanf("%s",ch);
			string order=string(ch);
			vector<vector<int> > ve(n);
			for(i=0;i<n;i++){
				ve[i].push_back(word[i].size());
				for(j=0;j<order.size();j++){
					ve[i].push_back(hash[i][order[j]-'a']);
				}
				ve[i].push_back(i);
			}
			sort(ve.begin(),ve.end());
			vector<int> neword(n);
			for(i=0;i<n;i++){
				neword[i]=ve[i][ve[i].size()-1];
				ve[i].pop_back();
			}
			/*for(i=0;i<ve.size();i++){
				printf("(%d) : ",neword[i]);
				for(j=0;j<ve[i].size();j++){
					printf("%d ",ve[i][j]);
				}
				puts("");
			}*/
			vector<int> score(n);
			vector<bool> line(n);
			line[n-1]=true;
			for(j=0;j<ve[0].size();j++){
				int now=0;
				for(i=0;i<n;i++){
					if(line[i] || ve[i][j]!=ve[i+1][j]){
						if(ve[now][j]==0 && !line[i]){
							for(k=now;k<=i;k++){
								//if(ve[k][j]!=0)break;
								score[k]++;
							}
						}
						line[i]=true;
						now=i+1;
					}
				}
			}
			//for(i=0;i<n;i++)printf("[%d] ",score[i]);puts("");
			pair<int,int> maxi=MP(-1,-1);
			int maxipos=-1;
			for(i=0;i<n;i++){
				pair<int,int> pa=MP(score[i],-neword[i]);
				if(maxi<pa){
					maxi=pa;
					maxipos=-pa.second;
				}
			}
			printf(" %s",word[maxipos].c_str());
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
