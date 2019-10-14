#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream myfile("B-large-1.in");
  int testcases;
  myfile >> testcases;
  long long k;
  long long v;
  for (int i = 0; i < testcases; i++) {
    myfile>>k;
    myfile>>v;
    if (v == 0) {
      cout<<"Case #"<<i+1 <<": "<<k+1<<endl;
      continue;
    }
    if (k == 0) {
      cout<<"Case #"<<i+1 <<": "<<1<<endl;
      continue;
    }
    long long res = (v+1)*(v+1)*(v+1)+(k-v)*(3*v*v+3*v+1);
    cout<<"Case #"<<i+1 <<": "<<res<<endl;
  }
  return 0;
}
