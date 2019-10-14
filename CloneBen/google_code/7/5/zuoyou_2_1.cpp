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

char s1[1000000],s2[1000000];

int main() {

	freopen("C-large.in", "r", stdin);
	freopen("c-large.txt", "w", stdout);
	int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n;
		map<string,int> ind;
		map<string,string> next;
		scanf("%d",&n);
		for (gets(s1);n;--n) {
			gets(s1);
			gets(s2);
			next[s1] = s2;
			ind[s1];
			++ind[s2];
		}	
		map<string,int>::iterator t;
		for (t = ind.begin(); t != ind.end(); ++t) {
			if (t->second == 0) {
				break;
			}
		}
		printf("Case #%d:",z);
		for (string at = t->first;next.find(at) != next.end();) {
			printf(" %s-%s",at.c_str(),next[at].c_str());
			at = next[at];
		}
		puts("");
	}
	return 0;
}

