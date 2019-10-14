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

const int N = 500+50;
int n;
int a[N],b[N];
int p;
void solve()
{
    while(p--){
        int x;
        scanf("%d",&x);
        int ans = 0;
        for(int i =1; i <= n ;i ++){
            if(x >= a[i] && x <= b[i]){
                ans ++;
            }
        }
        printf("%d",ans);
        if(p)printf(" ");
        else puts("");
    }
}
int main()
{
    
   // freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
   // freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: ",cas);
        scanf("%d",&n);
        for(int i =1 ; i <= n ;i ++){
            scanf("%d%d",&a[i],&b[i]);
        }
        scanf("%d",&p);
        solve();
    }
    return 0;
}