#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int a[2][200][200];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
    int cn;
    cin>>cn;
    for(int ci = 0; ci<cn;ci++) {
        memset(a,0,sizeof(a));
        int m;
        cin>>m;
        for(int i = 1;i<=m;i++) {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int x=x1;x<=x2;x++)
                for(int y=y1;y<=y2;y++)
                    a[0][x][y] = 1;
        }
        int flag = 1;
        int ans = 0;
                    
        while(flag) {
            flag = 0;
            int p = ans%2;
            int q = (ans+1)%2;
            for(int i=1;i<=100;i++) {
                for(int j =1;j<=100;j++) {
                    a[q][i][j]=a[p][i][j];
                    if(a[p][i-1][j]==0 && a[p][i][j-1]==0) {
                        a[q][i][j]=0;
                    }
                    if(a[p][i-1][j]==1 && a[p][i][j-1]==1) {
                        a[q][i][j]=1;
                    }
                    if(a[q][i][j]) flag = 1;
                }
            }
            ans++;
        }
        
        printf("Case #%d: %d\n",ci+1,ans);
    }
    return 0;
}
