#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int S;
int a[1010][1010];
int goNext[1010000];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void solve(){
    memset(goNext,0,sizeof(goNext));
    scanf("%d",&S);
    for(int i = 0 ; i < S ; ++ i ){
        for(int j = 0 ; j <S;++j){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i = 0 ; i< S ; ++ i ){
        for(int j  = 0 ; j < S ; ++ j ){
            for(int d = 0 ; d < 4 ; ++ d ){

                if(i+dx[d]>=0&&i+dx[d]<S&&j+dy[d]>=0&&j+dy[d]<S){
                    if(a[i+dx[d]][j+dy[d]]==a[i][j]+1){

                        goNext[a[i][j]]=1;
                    }
                }
            }
        }
    }
    int cur = 1;
    int bestD = 1;
    int bestC = 1;

    for(int i = 1; i<=S*S;++i){
        if(goNext[i]){
            continue;
        }
        else{
            if(i-cur+1>bestD){
                bestD=i-cur+1;
                bestC=cur;
            }
            cur=i+1;
        }
    }
    printf("%d %d\n",bestC,bestD);
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T;
    scanf("%d",&T);
    //printf("T=%d\n",T);
    //return 0;
    for(int i = 1 ; i<=T; ++ i ){
        printf("Case #%d: ",i);
        solve();
    }
}
