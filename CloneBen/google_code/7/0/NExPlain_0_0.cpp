#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<assert.h>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
#define CLR(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f

const int N = 1000+5;
int n;
int M[N][N];
int MX[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int get(int x,int y){
    if(MX[x][y] != -1)return MX[x][y];
    MX[x][y] = 0;
    for(int k = 0 ; k < 4 ; k++){
        int nx = x + dx[k],ny = y + dy[k];
        if(M[nx][ny] == M[x][y]+1){
            MX[x][y] = max(MX[x][y],get(nx,ny)+1);
        }
    }
    return MX[x][y];
}
void solve()
{
    pair<int,int> ans = MP(-1,INF);
    for(int i = 1; i <= n ; i ++){
        for(int j = 1; j <= n ; j++){
            get(i,j);
            ans = max(ans,MP(MX[i][j],-M[i][j]));
        }
    }
    printf("%d %d\n",-ans.second,ans.first+1);
}
int main()
{
    
    //freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    //freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: ",cas);
        CLR(MX,-1);
        CLR(M,0);
        scanf("%d",&n);
        for(int i = 1; i <= n ; i ++){
            for(int j = 1 ;j <=n ; j ++){
                scanf("%d",&M[i][j]);
            }
        }
        solve();
    }
    return 0;
}