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

int ar[305][305][305];
int nocopy[305];
int match[305][305];
bool oktoput(int l, int i, int j){
    if(j - i + 1 > l)
        return false;
    return (match[i][l - (j - i + 1)] >= (j-i+1));
}
void solve(){
    
    string s;
    cin>>s;
    int n = s.length();
    
    REP( i , n+1){
        REP( j , n+1)
        match[i][j] = 0;
    }
    REP( i , n){
        for(int j = i; j < n; j ++){
            int l = 0;
            int k = 0;
            while(j + k < n){
//                cout<<s[i+k]<<" "<<s[j+k]<<endl;
                if(s[i+k] == s[j+ k]){
                    l ++ , k ++;
//                    cout<<"efvcd"<<l<<endl;
                }else{
                    break;
                }
            }
//            cout<<l<<endl;
            match[i][j] = l;
            match[j][i] = l;
//            cout<<i<<" "<<j<<" "<<l<<endl;
//            cout<<s.substr(i)<<" "<<s.substr(j)<<" "<<l<<endl;
        }
    }
    
    REP( i , n+1){
        
        nocopy[i] = 1e9;
        REP( j , n+1){
            REP( k , n+1){
                ar[i][j][k] = 1e9;
            }
        }
    }
    //l == 1 => ans = 1
    ar[1][0][0] = 2;
    int ans = n;
    nocopy[1] = 1;
    for(int l = 2; l <= n; l ++){
        int mini = 1000000000;
        for(int i = 0; i <= l-2; i ++){
            for(int j = i; j <= l-2; j ++){
                mini = min(mini , ar[l-1][i][j]); // l-1 length ka min
//                if(l == 9 && ar[l-1][i][j] == 7){
//                    cout<<i<<" "<<j<<" got\n";
//                }
            }
        }
//        cout<<l<<" "<<mini<<endl;
        mini = min(mini , l-1);
//        cout<<l-1<<" "<<mini<<endl;
        for(int i = 0; i <= l-2; i ++){
            for(int j = i; j <= l-2; j ++){
                ar[l-1][i][j] = min(ar[l-1][i][j] , 1 + mini);
            }
        }
        
        for(int i = 0; i <= l-2; i ++){
            for(int j = i; j <= l-2; j ++){
                if(oktoput(l , i , j )){
                    ar[l][i][j] = min(ar[l - (j - i + 1)][i][j] + 1 , ar[l-1][i][j] + 1);
                }else{
                    ar[l][i][j] = min(ar[l][i][j] , ar[l-1][i][j]+1);
                }
            }
        }
        
        
    }
    
    REP( i , n){
        REP( j , n){
//            cout<<ar[n][i][j]<<endl;
            ans = min(ans , ar[n][i][j]);
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
