#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char a[55][55];
int n,m;
bool pd;

void cover(int i,int j){
     if (i+1>n||j+1>m) {
        pd=false;
        return ;
     }
     if (a[i+1][j]!='#'||a[i][j+1]!='#'||a[i+1][j+1]!='#') {
        pd=false;
        return ;
     }
     a[i][j]='/';
     a[i+1][j]='\\';
     a[i][j+1]='\\';
     a[i+1][j+1]='/';
}

void solve(){
     scanf("%d%d\n",&n,&m);
     for (int i=1;i<=n;i++) {
         for (int j=1;j<=m;j++)
             scanf("%c",&a[i][j]);
         scanf("\n");
     }
     pd=true;
     for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
             if (a[i][j]=='#')
                cover(i,j);
     if (pd==false) {
        printf("Impossible\n");
     }  else {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) 
                printf("%c",a[i][j]);
            printf("\n");
        }
     }
}

int main(){
    
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    
    int test;
    scanf("%d\n",&test);
    for (int tot=1;tot<=test;tot++) {
        printf("Case #%d:\n",tot);
        solve();
    }
    
    return 0;
}
