#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

int n[1123];
int e[1123];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int t;
    cin>>t;
    int num=1;
    while(t--){
        cout<<"Case #"<<num<<": ";
        num++;
        int l;
        cin>>l;
        for(int i=0;i<l;i++){
            cin>>n[i]>>e[i];

        }
        for(int i=0;i<l-1;i++){
            n[i]-=(n[i+1]*e[i+1]);
            if(n[i]>0)n[i+1]+=n[i];
        }
        cout<<max(n[l-1],e[l-1]+1)<<endl;
        
    }

    return 0;

}