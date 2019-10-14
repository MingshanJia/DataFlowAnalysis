#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define	sz(c) ll((c).size())
#define	all(c) begin(c),end(c)
#define	mp make_pair
#define mt make_tuple
#define	pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define	has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define	FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)

ll f[15][15];

ll compFrom(ll i, ll j){
  ll res = 0;
  vector<pll> list =  {{1,0}, {1,1}, {1,-1}, {0,1}, {0,-1}, {-1,0}, {-1,1}, {-1,-1}};
  for(auto p : list){
    ll ni = i + p.xx;
    ll nj = j + p.yy;
    if(ni < 0 || nj < 0 || ni >= 15 || nj >= 15){
      continue;
    }
    if(f[ni][nj] == 1){
      ni = ni + p.xx;
      nj = nj + p.yy;
      if(ni < 0 || nj < 0 || ni >= 15 || nj >= 15){
        continue;
      }
      res += (f[ni][nj] == 2);
    }
  }
  return res;
}

ll comp(){
  ll res = 0;
  FOR(i,0,15){
    FOR(j,0,15){
      if(f[i][j] == 0){
        res += compFrom(i, j);
      }
    }
  }
  return res;
}

void print(ll tc){
  cout << "Case #" << tc << ": " << endl;
  FOR(i,0,15){
    FOR(j,0,15){
      if(f[i][j] == 0) cout << "I";
      if(f[i][j] == 1) cout << "/";
      if(f[i][j] == 2) cout << "O";
    }
    cout << endl;
  }
}

bool try_solve(vector<ll> &line, ll goal, ll tc){
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = 0; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = 0; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = 1; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = 2; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = i%3; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = line[j]; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  FOR(j,0,15){
    FOR(i,0,15){
      f[i][j] = j%3; 
      if(goal == comp()){
        print(tc);
        return true;
      }
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  ll TC;
  cin >> TC;
  
  FOR(i,0,15){
    FOR(j,0,15){
      f[i][j] = 0; 
    }
  }
  FOR(tc,1,TC+1){
    vector<ll> line = {0,1,2,1,0,1,2,1,0,1,2,1,0,1,2};
    vector<ll> line2 = {0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};
    vector<ll> line3 = {0,1,2,1,1,2,0,1,2,1,1,2,0,1,2};
    vector<ll> line4 = {1,1,2,0,1,2,0,0,1,2,1,0,2,1,0};
    vector<ll> line5 = {0,1,2,1,0,1,2,0,1,2,1,0,2,1,0};
    vector<ll> line6 = {0,1,2,1,0,1,2,0,0,1,2,1,0,1,2};
    vector<ll> line7 = {0,1,2,1,0,1,2,1,0,1,2,1,2,1,0};
    vector<bool> done(300, false);
    ll d, goal;
    cin >> d >> goal;
    if(try_solve(line, goal, tc)) continue;
    if(try_solve(line2, goal, tc)) continue;
    if(try_solve(line3, goal, tc)) continue;
    if(try_solve(line4, goal, tc)) continue;
    if(try_solve(line5, goal, tc)) continue;
    if(try_solve(line6, goal, tc)) continue;
    if(try_solve(line7, goal, tc)) continue;
    cerr << "no solution for " << goal << endl;
  }
}
