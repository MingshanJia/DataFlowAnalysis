
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(int)(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(int)(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef WIN32
#define FORE(i, x) for (typeid((x).begin()) i = (x).begin(); (i) != (x).end(); (i)++)
#else
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); (i) != (x).end(); (i)++)
#endif

static inline string &ltrim(string &s) { s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))); return s; }
static inline string &rtrim(string &s) { s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end()); return s; }
static inline string &trim(string &s) { return ltrim(rtrim(s)); }

#ifdef DEB
//#define dump(x)  cerr << #x << " = " << (x) << endl
string __n_variable(string t, int n){ t=t+','; int i=0; if(n) for(; i<int(t.size())&&n; i++) if(t[i]==',') n--; n=i; for(;t[i]!=',';i++); t=t.substr(n, i-n); trim(t);if(t[0]=='"') return ""; return t+"="; }
#define __expand_nv(x) __n_variable(t, x)<< t##x << " "

template<class T0>
void ___debug(string t,T0 t0,ostream&os){os<<__expand_nv(0);}
template<class T0,class T1>
void ___debug(string t,T0 t0,T1 t1,ostream&os){os<<__expand_nv(0)<<__expand_nv(1);}
template<class T0,class T1,class T2>
void ___debug(string t,T0 t0,T1 t1,T2 t2,ostream&os){os<<__expand_nv(0)<<__expand_nv(1)<<__expand_nv(2);}
template<class T0,class T1,class T2,class T3>
void ___debug(string t,T0 t0,T1 t1,T2 t2,T3 t3,ostream&os){os<<__expand_nv(0)<<__expand_nv(1)<<__expand_nv(2)<<__expand_nv(3);}
template<class T0,class T1,class T2,class T3,class T4>
void ___debug(string t,T0 t0,T1 t1,T2 t2,T3 t3, T4 t4,ostream&os){os<<__expand_nv(0)<<__expand_nv(1)<<__expand_nv(2)<<__expand_nv(3)<<__expand_nv(4);}
#define dump(...) {{ ___debug( #__VA_ARGS__,  __VA_ARGS__,cerr); cerr<<endl;  } }
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
//#define dump(x) ;
#define dump(...) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> bool chmin(T& a,const T& b) { if(a>b) {a=b; return true;} return false; }
template<class T> bool chmax(T& a,const T& b) { if(a<b) {a=b; return true;} return false; }
typedef long long int lint;
typedef pair<int,int> pi;

template<class S,class T> ostream &operator <<(ostream& out,const pair<S,T>& a){ out<<'('<<a.fr<<','<<a.sc<<')'; return out; }

template<class T> ostream &operator <<(ostream& out,const vector<T>& a){ out<<"["<<a.size()<<"] "; REP(i,a.size()) out<<a[i]<< " "; return out; }
template<class T> ostream &operator <<(ostream& out,const queue<T>& a){ out<<"["<<a.size()<<"] "; REP(i,a.size()) out<<a[i]<< " "; return out; }
template<class T> ostream &operator <<(ostream& out,const deque<T>& a){ out<<"["<<a.size()<<"] "; REP(i,a.size()) out<<a[i]<< " "; return out; }
template<class T> ostream &operator <<(ostream& out,const set<T>& a){ out<<"["<<a.size()<<"] "; FORE(i,a) out<<*i<< " "; return out; }
template<class T1, class T2> ostream &operator <<(ostream& out,const map<T1, T2>& a){ out<<"["<<a.size()<<"] "; FORE(i,a) out<<*i<< " "; return out; }

int n;
const int MAXN = 1100;
int a[MAXN][MAXN];
pi rev[MAXN* MAXN];
int best[MAXN*MAXN];
//find around v+1
bool check(int a, int b){
    return a>=0 && b >= 0 && a<n && b<n;

}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool around(pi s, int v){
    REP(i, 4){
        int px = s.fr + dx[i];
        int py = s.sc + dy[i];
        if (check(px, py)){
            //dump(px, py, a[px][py], v);
            if ( a[px][py] == v + 1){
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int ncase;
    cin >> ncase;
    REP(icase, ncase){
        memset(a, 0, sizeof a);
        memset(rev, 0, sizeof rev);
        cin >> n;
        REP(i, n){
            REP(j, n){
                cin >> a[i][j];
                rev[a[i][j]] =  mp(i, j);
            }
        }
        int ans1, ans2;
        ans1 = ans2 = 0;
        for(int i= n*n; i>=1; i--){
            best[i] = 1;
            pi pos = rev[i];
            if (around(pos, i)  ){
                //dump("around");
                best[i] = best[i+1] + 1;
            }
            //dump(i, best[i]);
            if (ans2 <= best[i]){
                ans1 = i;
                ans2 = best[i];
            }
        }

        printf("Case #%d: %d %d\n", icase + 1, ans1, ans2);
    }
    


    return 0;
}
