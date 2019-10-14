#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
int tc;
int d;
long ret;



int get_digit(unsigned long long num) {
  std::ostringstream ss;
  ss << num;
  return ss.str().length();
}
unsigned long long get_fact(int exc, int max_digit) {
  unsigned long long result = 1LL;
  int cur = 9000;
  while (cur > 0) {
    result = result * cur;
    if (get_digit(result) >= max_digit) {
      return 0;
    }
    cur -= exc;
  }
  return result;
}


int main() {
  int low = 0;
  int high = 9000;
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d", &d);
    int ret = -1;
    if (d > 4) {
      int tr = 1000;
      for (int i = tr; i <= 9000; i++) {
    	unsigned long long tmp = get_fact(i, d);
    	std::ostringstream ss;
    	ss << tmp;
    	int digit = ss.str().length();
        if (digit == d-1) {
            ret = i;
            break;
        }
      }
      string output;
      output = "IT'S OVER 9000";
      for (int i = 0; i < ret; i++) {
        output += '!';
      }

      cout << "Case #" << (t+1) << ": " << output << endl;
    } else {
      printf("Case #%d: ...\n", t + 1);
    }
  }
}
