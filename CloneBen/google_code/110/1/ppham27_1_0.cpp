#include <iostream>
using namespace std;

long long calculateBlandColors(long long K, long long V) {
  long long distinctColors = 0;
  // cases   
  if (2*V <= K) {
    distinctColors += (K + 1 - 2*V)*((2*V + 1)*(2*V + 1) - V*(V+1));  
    // first color
    for (int i = 0; i < V; ++i) {
      int otherColors = min(K - i, V) + i + 1; // second color
      for (int j = max(0LL, i - V); j <= min(K, i + V); ++j) {
        distinctColors +=  2*(min(min(i,j) + V, K) - max(max(i,j) - V, 0LL) + 1);
      }
    }
  } else {
    for (int i = 0; i <= K; ++i) {
      int otherColors = min(K - i, V) + i + 1; // second color
      for (int j = max(0LL, i - V); j <= min(K, i + V); ++j) {
        distinctColors +=  min(min(i,j) + V, K) - max(max(i,j) - V, 0LL) + 1;
      }
    }
  }
  return distinctColors;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int K, V;
    cin >> K >> V;
    cout << "Case #" << i+1 << ": " 
         << calculateBlandColors(K, V)
         << endl;
  }

  // int cnt = 0;
  // for (int i = 0; i <= 15; ++i) {
  //   for (int j = 0; j <= 15; ++j) {
  //     for (int k = 0; k <= 15; ++k) {
  //       if (abs(i - j) <= 10 && abs(i - k) <= 10 && abs(j - k) <= 10) ++cnt;
  //     }
  //   }
  // }
  // cout << cnt << endl;
    
  return 0;
}
