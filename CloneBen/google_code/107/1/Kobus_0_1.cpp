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

int v[112345];
int nu[112345];

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
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            v[i]=min(i,n-i-1);
        }
        sort(v,v+n);
        for(int i=0;i<n;i++){
            cin>>nu[i];
        }
        sort(nu,nu+n);
        int resp=0;
        for(int i=0;i<n;i++){
            resp+=(v[i]-nu[i])*(v[i]-nu[i]);
        }
        cout<<resp<<endl;

        
        
    }

    return 0;

}