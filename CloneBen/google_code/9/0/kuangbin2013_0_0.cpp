/* ***********************************************
Author        :kuangbin
Created Time  :2014/9/15 13:09:58
File Name     :A.cpp
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
const int MOD = 1e9+7;
long long pow_m(long long a,long long n){
	long long ret = 1;
	long long tmp = a;
	while(n){
		if(n&1)ret = ret*tmp%MOD;
		tmp = tmp*tmp%MOD;
		n >>= 1;
	}
	return ret;
}
long long C[110][110];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    C[0][0] = 1;
	for(int i = 1;i <= 100;i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if(C[i][j] >= MOD)C[i][j] -= MOD;
		}
	}
	int T;
	int iCase = 0;
	scanf("%d",&T);
	int n,m;
	while(T--){
		iCase++;
		scanf("%d%d",&m,&n);
		int ans = 0;
		for(int i = 0;i <= m;i++){
			if(i%2 == 0)ans += C[m][i]*pow_m(m-i,n)%MOD;
			else ans -= C[m][i]*pow_m(m-i,n)%MOD;
			ans = (ans%MOD+MOD)%MOD;
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
    return 0;
}
