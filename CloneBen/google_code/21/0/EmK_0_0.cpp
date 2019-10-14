// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<cassert>
#include<functional>
#include<complex>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);

int A[500];
int B[500];

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    int ans = -1 ;
    int M,C,W;
    cin>>M>>C>>W;
    ll_t pos = W-1;
    FOR(i,C) cin>>A[i]>>B[i];
    for(int i=C-1;i>=0;i--){
      ll_t a = A[i] - 1; 
      ll_t b = a + B[i] - 1 ;
      if(pos < b - a + 1){
        pos += a;
      }else if(pos <= b){
        pos -= b - a + 1;
      }
      //cout<<a<<" "<<b<<" "<<pos<<endl;
    }
    ans = pos + 1;
    printf("Case #%d: %d\n" , case_no++ , ans);

  }
  return 0 ;
}
