#include <map>
#include <fstream>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef pair<int, int> P;
typedef long long ll;

ll M, C, W;
ll A[200], B[200];

ll shuffle(int pos, int id){
  ll a = A[id], b = B[id];
  if(pos <= b) return W + a - 1;
  else if(pos <= a + b - 1) return W - b;
  else return W;
}

int main(){
  int T;
  cin >> T;
  rep(t, T){
    cin >> M >> C >> W;
    rep(i, C){
      cin >> A[C - 1 - i] >> B[C - 1 - i];
    }
    rep(i, C){
      W = shuffle(W, i);
    }
    cout << "Case #" << t + 1 << ": " << W << endl;
  }
  return 0;
}
