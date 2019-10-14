#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[101000];

int get(int k){
    int ret = 0 ;
    while(k){
        ret+=a[k];
        k-=k&(-k);
    }
    return ret;
}
int get(int a,int b){
    return get(b)-get(a-1);
}
void add(int k,int d ){
    while(k<=10000){
        a[k]+=d;
        k+=k&(-k);
    }
    return ;
}

void solve(){
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++ i ){
        int s,e;
        scanf("%d %d",&s,&e);
        add(s,1);
        add(e+1,-1);
    }
    int p;
    scanf("%d",&p);
    for(int i = 0 ; i < p ; ++ i ){
        int k;
        scanf("%d",&k);
        printf(" %d",get(k));
    }
    printf("\n");
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    //printf("T=%d\n",T);
    //return 0;
    for(int i = 1 ; i<=T; ++ i ){
        printf("Case #%d:",i);
        solve();
    }
}
