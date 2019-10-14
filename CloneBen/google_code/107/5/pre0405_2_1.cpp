#include <iostream>

#define yes "YES"
#define no "NO"

using namespace std;

int len;

string inMiddle(string a, string b, string c) {
  int i;
  for (i = 0; i < len; i++) {
    if (a[i] != b[i]) break;
    if (a[i] != c[i]) break;
    if (b[i] != c[i]) break;
  }
  if (b[i] == c[i]) {
    return no;
  }
  if (a[i] == c[i]) {
    swap(b, c);
  }
  if (a[i] == b[i]) {
    for(int j = i + 1; j < len; j++) {
      if (b[j] != a[j]) {
        if (a[i] == a[j] && b[j] == c[i]) {
          return no;
        }
        return yes;
      }
    }
  }
  return yes;
}

int main() {
  int tests;
  cin >> tests;
  for (int t = 1; t <= tests; t++) {
    cin >> len;
    string x,y,z;
    cin >> x >> y >> z;
    cout << "Case #" << t << ": " << inMiddle(x,y,z) << " " << inMiddle(y,x,z) << " " << inMiddle(z,y,x) << "\n";
  }
  return 0;
}