//#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define Eo(x) {cerr<< #x << " = " << (x) << endl;}

typedef double real;
typedef long long int64;
const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-6;
typedef pair<int,int> pip;

string d[15000];
char was[12];
int n;

int go(const string& t, const string& base){
    memset(was,0,sizeof(was));
    int res = 0;
    set<string> can;
    for (int i = 0; i < n; i++) if (d[i].size()==base.size()) {
        can.insert(d[i]);
    }
    for (int i = 0; i < t.size() && can.size()>1; i++){
        char has = 0;
        for(set<string>::iterator it = can.begin(); !has && it != can.end(); ++it){
            for (int j = 0; j < it->size(); j++){
                if ((*it)[j]==t[i]){
                    has = true;
                    break;
                }
            }
        }
        if (!has) {
            continue;
        }
        char any=0;
        for (int j = 0; j < base.size(); j++) if (base[j]==t[i]){
            was[j]=1;
            any=1;
        }
        if(!any){
            res++;
        }
        for(set<string>::iterator it = can.begin(); it != can.end();){
            set<string>::iterator zit = it;
            zit++;
            const string& s = *it;
            for (int j = 0; j < s.size(); j++){
                if ((was[j] && s[j] != base[j]) || (!was[j]&&s[j]==t[i])){
                    can.erase(it);
                    break;
                }
            }
            it = zit;
        }
    }
    return res;
}

string solve(const string& t){
    int mx = -1;
    string best;
    for (int i = 0; i < n; i++) {
        int z = go(t,d[i]);
        //Eo(d[i]);Eo(z);
        if (z>mx){
            mx = z;
            best = d[i];
        }
    }
    return best;
}

int main(){
    int T; cin >> T;
    for (int _ = 0; _ < T; _++){
        int m; cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> d[i];
        }
        string s;
        printf("Case #%d:",_+1);
        for (int i = 0; i < m; i++){
            cin >> s;
            printf(" %s",solve(s).c_str());
        }
        puts("");
    }
    return 0;
}
