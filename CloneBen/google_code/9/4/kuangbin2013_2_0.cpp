/* ***********************************************
Author        :kuangbin
Created Time  :2014/9/15 14:02:28
File Name     :C.cpp
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
const int MAXN = 110;
int a[MAXN];
int b[MAXN];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	scanf("%d",&T);
	int n,k;
	while(T--){
		iCase++;
		scanf("%d%d",&n,&k);
		int top = 0;
		for(int i = 0;i < n;i++)scanf("%d",&a[i]);
		for(int i = 0;i < n;i++){
			b[top++] = a[i];
			while(top >= 3 && b[top-1] == b[top-2] && b[top-2] == b[top-3]){
				top -= 3;
			}
		}
		printf("Case #%d: %d\n",iCase,top);
	}
    return 0;
}
