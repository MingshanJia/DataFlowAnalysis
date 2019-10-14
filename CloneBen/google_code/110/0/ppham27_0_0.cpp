#include <iostream>
#include <string>
using namespace std;



string translate(int B, string s) {
  string out;
  for (int i = 0; i < B; ++i) {
    int c = 0;
    for (int j = 0; j < 8; ++j) {
      if (s[8*i + j] == 'I') c += (1 << (7-j));
    }
    out += (char) c;
  }
  return out;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int B; string s;
    cin >> B >> s;    
    cout << "Case #" << i+1 << ": " 
         << translate(B, s)
         << endl;
  }
  return 0;
}
