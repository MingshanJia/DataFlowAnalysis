#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <string>
using namespace std;

char s1[10000], s2[10000];

int main() {
	int cas;
	scanf("%d" , &cas);
	for (int re = 1; re <= cas; re++) {
		int n;
		scanf("%d", &n);
		map<string, string> mp;
		set<string> st;
		for (int i = 0; i < n; i++) {
			scanf("%s%s", s1, s2);
			mp[s1] = s2;
			st.insert(s2);
		}
		string s;
		for (map<string, string>::iterator it = mp.begin(); it != mp.end(); it++) {
			if (!st.count(it->first)) {
				s = it->first;
			}
		}
		printf("Case #%d:", re);
		for (int i = 0; i < n; i++) {
			printf(" %s-%s", s.c_str(), mp[s].c_str());
			s = mp[s];
		}
		puts("");
	}
}