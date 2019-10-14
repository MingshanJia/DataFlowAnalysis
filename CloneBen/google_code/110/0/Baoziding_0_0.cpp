#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream myfile("testa.in");
  int testcases;
  myfile >> testcases;
  int len;
  string str;
  for (int i = 0; i < testcases; i++) {
    myfile>>len;
    myfile>>str;
    string res(len, ' ');
    for(int j = 0; j < len; j++) {
      string tmp = str.substr(j*8,8);
      int r = 0;
      for(int k = 0; k < 8; k++) {
        if (tmp[k] == 'I')
          r+=(1<<(7-k));
      }
      res[j] = (char)r;
    }
    cout<<"Case #"<<i+1 <<": "<<res<<endl;
  }
  return 0;
}
