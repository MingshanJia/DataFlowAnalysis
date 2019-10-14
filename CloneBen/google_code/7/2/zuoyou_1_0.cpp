#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <cmath>
#include <cctype>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int a[5050];
int main() {
	freopen("B-small-attempt1.in","r",stdin);
	freopen("b.txt","w",stdout);

	int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		printf("Case #%d:",z);
		memset(a,0,sizeof(a));
		int n;
		for (scanf("%d",&n);n;--n) {
			int x,y;
			scanf("%d%d",&x,&y);
			if (x > y) {
				int t = x;
				x = y;
				y = t;
			}
			for (;x <= y; ++x) {
				++a[x];
			}
		}
		for (scanf("%d",&n);n;--n) {
			int x;
			scanf("%d",&x);
			printf(" %d",a[x]);
		}
		puts("");
	}
	return 0;
}

