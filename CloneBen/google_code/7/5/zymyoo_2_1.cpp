#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;


//char a[11111], b[11111];

int main() {
	int T, n, icase = 1;
	cin>>T;
	while(T--){
		cin>>n;
		map<string, int> in;
		map<string, string> nxt;
		vector<string> v;
		for(int i = 0; i < n; i++){
			string a, b;
			cin>>a>>b;
			in[b]++;
			nxt[a] = b;
			v.push_back(a);
			v.push_back(b);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		string f;
		for(int i = 0; i < v.size(); i++){
			string t = v[i];
			if(in[t] == 0) {
				f = t; break;
			}
		}

		printf("Case #%d:", icase++);
		while(1){
			if(nxt.find(f) == nxt.end()) break;
			string nf = nxt[f];
			printf(" %s-%s", f.c_str(), nf.c_str());
			f = nf;
		}
		puts("");
	}
	return 0;
}
