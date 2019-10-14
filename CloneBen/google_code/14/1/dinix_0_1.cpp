#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
 int ntc;
 cin>>ntc;
 cin.get();
 //cout.precision(7);
 //cout.setf( std::ios::fixed, std:: ios::floatfield );
 for(int tc=1;tc<=ntc;++tc) {
   int N=0;
   cin>>N;
   cin.get();
   string s;
   vector<string> all;
   for(int i=0;i<N;++i) {
     getline(cin,s);
     all.push_back(s);
   }
   int pay=0;
   string s1=all[0];
   for(int i=1;i<N;++i) {
     string s2=all[i];
     if(s1.compare(s2)>0) {
       ++pay;
     } else {
       s1=s2;
     }
   }

   cout<<"Case #"<<tc<<": "<<pay<<endl;
 }
 return 0;
}
