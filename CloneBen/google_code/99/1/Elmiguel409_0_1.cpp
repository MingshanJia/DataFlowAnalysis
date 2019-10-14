#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <cassert>
using namespace std;

#define FOR(a,b,c) for(int a=(int)(b);a<(int)(c);a++)
#define ITER(a,b) for(__typeof((b).begin()) a = (b).begin(); a!=(b).end(); a++)
#define MEMSET(dest,val) memset(dest,val,sizeof(dest))
#define PAIR pair<int,int>
#define BEGEND(a) (a).begin(), (a).end()
#define SHIFT(v) (1LL<<(v))
#define SQ(a) ((a) * (a))
#define LSB(a,b) (b<=sizeof(a)?(b & (SHIFT(a)-1)):LLMAX)

#define eps 1E-9
#define PI acos(-1.0)
#define INF 1000000000
#define LINF 90000000000000000000LL
#define LLMAX ((unsigned long long)(-1))

int N, M;
string dummy, thing;

map<string,int> bneeded;
map<string,vector<string> > mixes;

int solve(string th){
   if(bneeded.count(th)>0) return bneeded[th];
   if(mixes[th].size()==0) return 1;

   vector<int> order;
   FOR(i,0,mixes[th].size()){
	    int v = solve(mixes[th][i]);
	    order.push_back(v);
	}	
   int mx = 0;
   sort(BEGEND(order),greater<int>());
   FOR(i,0,order.size()) mx = max(mx,i+order[i]);
   return bneeded[th] = max(mx,(int)order.size()+1);
}

int _times;
int main(){
  cin >> _times;
  FOR(_t,1,_times+1){
    int mx = 0;
    bneeded.clear();
    mixes.clear();
    vector<string> things;
    cin >> N;
    FOR(i,0,N){
      cin >> thing >> M;
      things.push_back(thing);
      FOR(i,0,M) { cin >> dummy; if(isupper(dummy[0])) mixes[thing].push_back(dummy);}
    }
    cout << "Case #" << _t << ": ";
    FOR(i,0,things.size()) mx = max(mx,solve(things[i]));
    cout << mx << endl;
  }
  return 0;
}
