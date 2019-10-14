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
typedef long long ll;

const ll MAX = 1LL << 32;
int NT;
ll a[35][101000];
int l[35];
int B, D, F;

ll get(int b, int d)
{
 b = min(b, d);

 if(b == 0)
  return 0;

 if(b > 33)
  return MAX;

 if(b == 1)
  return d;

 if(l[b] <= d)
  return MAX;

 return a[b][d];
}

ll maxf()
{
 if(get(B, D) >= MAX)
  return -1;
 else
  return get(B, D);
}

int mind()
{
 if(B == 1)
  return F;

 for(int i = 0; true; i++)
  if(get(B, i) >= F)
   return i;

 return -1;
}

int minb()
{
 if(F <= D)
  return 1;

 for(int i = 0; i <= D; i++)
  if(get(i, D) >= F)
   return i;

 return -1;
}

void init()
{
 int i, j;

 for(i = 2; i <= 33; i++)
  for(j = 1; true; j++)
  {
   l[i] = j;
   a[i][j] = get(i, j - 1) + get(i - 1, j - 1) + 1;

   if(a[i][j] >= MAX)
   {
    a[i][j] = MAX;
    break;
   }
  }
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
  fin >> F >> D >> B;
  fout << "Case #" << i + 1 << ": " << maxf() << " " << mind() << " " << minb() << endl;
 }

 return 0;
}
