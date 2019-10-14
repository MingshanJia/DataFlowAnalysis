/* ***********************************************
Author        :kuangbin
Created Time  :2014/9/15 14:37:15
File Name     :B.cpp
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
double dp[410][41000];
int sum[500];
int loc[1000000];

void getloc(int n,int &x,int &y){
	x = loc[n];
	y = n - sum[x-1];
}
int getid(int x,int y){
	return sum[x-1]+y;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	scanf("%d",&T);
	int B,L,N;
	sum[0] = 0;
	loc[0] = 0;
	for(int i = 1;i < 500;i++){
		for(int j = 1;j <= i;j++)
			loc[sum[i-1]+j] = i;
		sum[i] = sum[i-1] + i;
	}
	while(T--){
		iCase++;
		scanf("%d%d%d",&B,&L,&N);
		memset(dp,0,sizeof(dp));
		dp[1][1] = 750*B;
		for(int i = 1;i < L;i++)
			for(int j = 1;j <= sum[i];j++){
				if(dp[i][j] <= 250)continue;
				dp[i][j] -= 250;
				int x,y;
				getloc(j,x,y);
				dp[i+1][getid(x,y)] += dp[i][j]/3;
				dp[i+1][getid(x+1,y)] += dp[i][j]/3;
				dp[i+1][getid(x+1,y+1)] += dp[i][j]/3;
			}
		double ans = dp[L][N];
		if(ans >= 250)ans = 250;
		printf("Case #%d: %.10lf\n",iCase,ans);
	}
    return 0;
}
