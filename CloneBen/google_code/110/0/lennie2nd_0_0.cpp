#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
char s[10000];
int tc;
int b;

int main() {
  scanf("%d\n", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d", &b);
    scanf("%s", s);
    int idx = 0;
    string ret = "";
    for (int i = 0; i < b; i++) {
      int num = 0;
      for (int j = 0; j < 8; j++) {
        num = num * 2;
        if (s[idx] == 'I')
	  num += 1;
	idx++;
      }
      ret = ret + char(num);
    }
    cout << "Case #" << (t+1) << ": " << ret << endl;
  }
}
