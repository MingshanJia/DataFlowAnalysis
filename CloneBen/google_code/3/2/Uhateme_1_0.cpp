#include <bits/stdc++.h>

using namespace std;
//memset
#define MEMSET_INF 127 // about 2B
#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a));

//stl
#define mp make_pair
#define pb push_back
//#define pc(x) putchar_unlocked(x)
//#define gc() getchar_unlocked()

//Loops
#define REP(i,b) for(int i = 0 ;i < (int)(b); i++)
#define REP1(i,a,b) for(int i = (int)(a);i <= (int)(b); i++)
#define REPMAP(i,mm) for(auto i = mm.begin();i !=mm.end(); i++)

//Sort
#define sortvec(vec) sort(vec.begin(), vec.end())

//Misc
#define LSOne(i) (i & (-i))	// the first Least Significant One-bit in i

//modulo
#define mod %
#define NUM 1000000007


#define LONG_LONG_MAX	9223372036854775807LL
#define LONG_LONG_MIN	(-LONG_LONG_MAX-1)

#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN
#define IMAX INT_MAX
#define IMIN INT_MIN
#define PI M_PI
#define EPS 1e-9
#define INF 1e9
#define M_PI		3.14159265358979323846
#define cin(x) scanf("%d",&x)
#define cout(x) printf("$d",x)
#define endl '\n'
#define s(n) scanf("%d",&n)
#define sll(n) scanf("%I64d",&n)
#define p(n) printf("%d",n)
#define pll(n) printf("%I64d",n)
#define all(v) (v).begin(),(v).end()

//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef tuple<int,int,int> iii;

#define MAX_N 100005

ll ar[5005];
map<ll,ll> m , sum;
ll distinct[5005];
ll now1(int x){
    return m[distinct[x]];
}
ll now2(int x){
    ll v = m[distinct[x]];
    return (v * (v-1))/2;
}
ll now3(int x){
    ll v = m[distinct[x]];
    return (v * (v-1) * (v-2))/6;
}
void solve(){
    
    int n;
    cin>>n;
    m.clear();
    sum.clear();
    REP( i , n){
        cin>>ar[i];
        m[ar[i]] ++;
    }
    sort(ar,ar+n);
    int c = 0;
    int total =0 ;
    REPMAP(i , m){
        distinct[c++] = i->first;
        total += i->second;
        sum[i->first] = total;
    }
    //c = total distinct.
    ll ans = 0;
    for(int s = 0; s < c; s++){
        for(int x = 0; x < c; x++){
            if(x == s)
                continue;
            ll a = now1(s) * now2(x);
//            cout<<s<<" "<<x<<endl;
            ll low = distinct[s];
            ll high = distinct[s] + 2 * distinct[x];
//            cout<<low<<" low "<<high<<endl;
            auto itr1 = sum.upper_bound(low);
            auto itr2 = sum.lower_bound(high);
            if(itr2 != sum.begin()){
                itr2 --;
                ll cc = itr2->second;
                if(itr1 == sum.begin()){
                    
                }else{
                    itr1--;
                    cc -= itr1->second;
                }
                
                if(low < distinct[s] && high > distinct[s]){
                    cc -= m[distinct[s]];
                }
                if(low < distinct[x] && high > distinct[x]){
                    cc -= m[distinct[x]];
                }
                cc =max(cc , (ll) 0);
//                cout<<s<<" "<<x<<" "<<cc<<endl;
                
                a *= cc;
                ans += a;
            }
            
        }
    }
    for(int s = 0; s < c; s++){
        for(int x = s + 1; x < c; x++){
            ll a = now1(s) * now3(x);
           
            ans += a;
            
        }
    }
    
    for(int s = 0; s < c;  s++){
        ll a = now3(s);
        ll low = distinct[s];
        ll high = distinct[s] + 2 * distinct[s];
        auto itr1 = sum.upper_bound(low);
        auto itr2 = sum.lower_bound(high);
        if(itr2 != sum.begin()){
            itr2 --;
            ll cc = itr2->second;
            if(itr1 == sum.begin()){
                
            }else{
                itr1--;
                cc -= itr1->second;
            }

            cc =max(cc , (ll) 0);
            
            a *= cc;
            ans += a;
        }
        
    }
    
    cout<<ans;

}

int main(){
    
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    
    freopen("/Users/ritesray/Documents/io/input.in","r",stdin);
    freopen("/Users/ritesray/Documents/io/output.out","w",stdout);
    
    int TC = 1;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        cout<<"Case #"<<ZZ<<": ";
        clock_t start = clock();
        //		double ans;
        //		cout.precision(10);
        //		cout<<fixed<<ans<<endl;
        solve();
        clock_t end = clock();
        cout<<'\n';
        cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    }
    return 0;
}
