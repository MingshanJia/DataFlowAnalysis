#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream myfile("C-small-attempt0.in");
  int testcases;
  myfile >> testcases;
  int num;
  for (int i = 0; i < testcases; i++) {
    myfile >> num;
    if (num <= 4)
      cout<<"Case #"<<i+1 <<": ..."<<endl;
    else if (num == 5)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(8999,'!')<<endl;
    else if (num == 6)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(8989,'!')<<endl;
    else if (num == 7)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(8889,'!')<<endl;
    else if (num == 8)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(7889,'!')<<endl;
    else if (num == 9)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(4499,'!')<<endl;
    else if (num == 10)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(4488,'!')<<endl;
    else if (num == 11)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(4380,'!')<<endl;
    else if (num == 12)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(3492,'!')<<endl;
    else if (num == 13)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2998,'!')<<endl;
    else if (num == 14)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2980,'!')<<endl;
    else if (num == 15)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2822,'!')<<endl;
    else if (num == 16)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2250,'!')<<endl;
    else if (num == 17)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2246,'!')<<endl;
    else if (num == 18)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(2213,'!')<<endl;
    else if (num == 19)
      cout<<"Case #"<<i+1 <<": IT'S OVER 9000"<<string(1990,'!')<<endl;
  }
  return 0;
}
