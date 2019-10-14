#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[1010][1010];
int dp[1010101];
int main(){
    CASET{
        map<string,string>H1;
        set<string>H2;
        DRI(n);
        REP(i,n){
            string str1,str2;
            cin>>str1>>str2;
            H1[str1]=str2;
            H2.insert(str2);
        }
        string st;
        for(map<string,string>::iterator it=H1.begin();it!=H1.end();it++){
            if(H2.count(it->F)==0){
                st=it->F;
                break;
            }
        }
        printf("Case #%d:",case_n++);
        while(H1.count(st)){
            printf(" %s-%s",st.c_str(),H1[st].c_str());
            st=H1[st];
        }
        puts("");
    }
    return 0;
}
