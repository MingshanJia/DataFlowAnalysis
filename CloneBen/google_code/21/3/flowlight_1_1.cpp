#include <map>
#include <algorithm>
#include <memory>
#include <fstream>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> coffee;


ll N, K, res;
coffee cs[200];

int main(){
  int T;
  cin >> T;
  rep(t, T){
    cin >> N >> K;
    res = 0;
    rep(i, N){
      cin >> cs[i].second.second >> cs[i].first >> cs[i].second.first;
    }
    sort(cs, cs + N);
    rep(i, N){
      //cout << cs[i].first << " " << cs[i].second.first << " " << cs[i].second.second << endl;
      ll dif = 0;
      int pos = N - i - 1;
      if(pos == 0){
	dif = cs[pos].first;
      }else{
	dif = cs[pos].first - cs[pos-1].first;
      }
      while(dif > 0){
	int best = 0;
	ll score = -1;
	rep(j, i + 1){
	  int pos2 = N - j - 1;
	  if(cs[pos2].second.second > 0 && cs[pos2].second.first > score){
	    best = pos2;
	    score = cs[pos2].second.first;
	  }
	}
	if(score == -1) break;
	ll num = cs[best].second.second;
	//cout << "***" << num << " " << score  << endl;
	if(num >= dif){
	  res += dif * score;
	  cs[best].second.second -= dif;
	  dif = 0;
	}else{
	  res += num * score;
	  dif -= num;
	  cs[best].second.second = 0;
	}
      }
    }
    cout << "Case #" << t + 1 << ": " << res << endl;
  }
  return 0;
}
