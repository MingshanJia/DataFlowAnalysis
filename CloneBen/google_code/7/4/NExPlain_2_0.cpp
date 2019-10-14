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

const int N = 10000+50;
int tot;
int n;
map<string,int> M;
int s[N],t[N];
string a[N],b[N];
void solve()
{
    int go = -1;
    for(int i =1 ; i <= tot ; i++){
        if(t[i] == -1){
            go = i;
            break;
        }
    }
    do{
        int idx = s[go];
        cout << a[idx] << "-" << b[idx] << " ";
        go = M[b[idx]];
        
    }while(s[go] != -1);
    cout << endl;
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
        scanf("%d",&n);
        M.clear();
        tot = 0;
        CLR(s,-1);
        CLR(t,-1);
        for(int i =1 ;i <= n ;i ++){
            string str;
            cin >> str;
            if(M[str] == 0){
                M[str] = ++tot;
            }
            s[M[str]] = i;
            a[i] = str;
            cin >> str;
            if(M[str] == 0){
                M[str] = ++tot;
            }
            t[M[str]] = i;
            b[i] = str;
        }
        solve();
    }
    return 0;
}