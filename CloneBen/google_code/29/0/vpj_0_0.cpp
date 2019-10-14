#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fr(i, n) for(i = 0; i < (n); i++)
#define fr2(i, s, n) for(i = (s); i < (n); i++)

string num, sl, tl;
int n;
string res;
int NT;

void proc()
{
 int i, j;

 n = 0;

 fr(i, sz(num))
 {
  fr(j, sz(sl))
   if(num[i] == sl[j])
    break;

  n *= sz(sl);
  n += j;
 }

 res = "";

 while(n)
 {
  res += tl[n % sz(tl)];
  n /= sz(tl);
 }

 reverse(all(res));
}

int main()
{
 int i;

 ifstream fin("input.txt");
 ofstream fout("output.txt");

 fin >> NT;

 fr(i, NT)
 {
  fin >> num >> sl >> tl;
  proc();
  fout << "Case #" << i + 1 << ": " << res << endl;
 }

 return 0;
}
