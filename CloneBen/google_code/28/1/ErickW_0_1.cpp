#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std; typedef unsigned long ulong; typedef long long llong;
typedef unsigned long long ullong;

int main()
{
int cases;

cin >> cases; getchar();

for(int loop=1;loop<=cases;loop++)
{
  int w,b;

  cin >> w >> b;

  printf("Case #%d: %s\n", loop,(b%2) ? "BLACK":"WHITE");

  fflush(stdout);
}

}
