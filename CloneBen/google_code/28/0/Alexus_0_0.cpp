#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define PROBLEM "a"

int main(){
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int tn, t;
  scanf("%d", &tn);
  for (t=1; t<=tn; t++){
    printf("Case #%d: ", t);
    int w, b;
    scanf("%d%d", &w, &b);
    if (b&1) printf("BLACK\n");
    else printf("WHITE\n");
  }
  return 0;
}
