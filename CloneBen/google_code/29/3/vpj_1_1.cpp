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
#define _cl(x) memset(x, 0, sizeof(x))

int NT;
int lf[20], rt[20], mr[20], mc[20];
const int N = 1, S = 2, W = 4, E = 8;
int minr, minc, maxr, maxc;
int rr, cc, oo;
int a[1000][1000];
string S1, S2;
const string enc = "0123456789abcdef";

void calc(int r, int c, int o, string str)
{
 int i;

 for(i = 0; i < sz(str); i++)
 {
  minr = min(minr, r);
  minc = min(minc, c);
  maxr = max(maxr, r);
  maxc = max(maxc, c);

  rr = r, cc = c, oo = o;

  if(str[i] == 'W')
  {
   a[r][c] |= o;

   r += mr[o];
   c += mc[o];
  }
  else if(str[i] == 'L')
   o = lf[o];
  else
   o = rt[o];
 }
}

void proc()
{
 _cl(a);
 minr = minc = 1000000;
 maxr = maxc = -1;

 a[0][500] |= N;
 calc(0, 500, S, S1.substr(1));
 calc(rr, cc, rt[rt[oo]], S2.substr(1));
}

void output(ofstream &fout)
{
 int r, c;

 for(r = minr; r <= maxr; r++)
 {
  for(c = minc; c <= maxc; c++)
   fout << enc[a[r][c]];
  fout << endl;
 }
}

void init()
{
 lf[N] = W, lf[W] = S, lf[S] = E, lf[E] = N;
 rt[N] = E, rt[E] = S, rt[S] = W, rt[W] = N;

 mr[N] = -1, mr[S] = 1;
 mc[E] = 1, mc[W] = -1;
}

int main()
{
 int i;

 ifstream fin("input.txt");
 ofstream fout("output.txt");

 init();

 fin >> NT;

 fr(i, NT)
 {
  fin >> S1 >> S2;
  proc();
  fout << "Case #" << i + 1 << ":" << endl;
  output(fout);
 }

 return 0;
}
