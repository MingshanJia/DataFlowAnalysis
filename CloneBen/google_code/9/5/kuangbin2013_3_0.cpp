/* ***********************************************
Author        :kuangbin
Created Time  :2014/9/15 13:34:13
File Name     :D.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long dp[210][110];
const long long INF = 2e18;
void Add(long long &a,long long b){
	if(a >= INF)return;
	a += b;
	if(a >= INF)a = INF;
}

int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0;i <= 200;i++)
		for(int j = 0;j <= i/2;j++)
		{
			if(dp[i][j] == 0)continue;
			Add(dp[i+1][j],dp[i][j]);
			if((j+1) <= (i+1)/2)
				Add(dp[i+1][j+1],dp[i][j]);
		}
	int n;
	long long k;
	int T;
	int iCase = 0;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d%I64d",&n,&k);
		printf("Case #%d: ",iCase);
		if(k > dp[2*n][n]){
			printf("Doesn't Exist!\n");
			continue;
		}
		int left = n, right = n;
		for(int i = 0;i < 2*n;i++){
			//printf("%d %d\n",left,right);
			if(left == 0){
				printf(")");
				continue;
			}
			//printf("%I64d\n",dp[left+right-1][left-1]);
			if(left > 0 && k <= dp[left+right-1][left-1]){
				printf("(");
				left--;
			}
			else {
				k -= dp[left+right-1][left-1];
				right--;
				printf(")");
			}
		}
		printf("\n");
	}
    return 0;
}
