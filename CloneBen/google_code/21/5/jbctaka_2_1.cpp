#include <iostream>
using namespace std;

int main(void)
{
  int T; cin >> T;
  for (int index = 1; index <= T; index++) {
    unsigned long long N; cin >> N;
    unsigned long long i, result = 0;
    for (i = 1; (i & N) != 0; i <<= 1) {
      result++;
    }
    if (i < N) {
      for (; i <= N; i <<= 1) {
        if (i & N) result++;
        result++;
      }
      result--;
    }
    cout << "Case #" << index << ": ";
    cout << result << endl;
  }
  return 0;
}

// 1
// 1
//   1
//  11
// 100
