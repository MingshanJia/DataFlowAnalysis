#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, f, s, i, j;
	cin >> t;
	for (int test=1; test<=t; test++) {
		map<int, int> count;
		set<pair<int, int> > seats;
		set<pair<int, int> >::iterator its;
		cin >> f >> s;
		while (f--) {
			cin >> i >> j;
			seats.insert(make_pair(i, j));
		}
		for (its=seats.begin(); its!=seats.end(); its++) {
			i = its->first;
			j = its->second;
			if (i==j) {
				if (count.find(i) == count.end()) {
					count[i] = 1;
				}
				else 
					count[i] = count[i] + 1;
			}
			else {
				if (count.find(i) == count.end()) {
					count[i] = 1;
				}
				else 
					count[i] = count[i] + 1;
				if (count.find(j) == count.end()) {
					count[j] = 1;
				}
				else 
					count[j] = count[j] + 1;
			}
		}
		map<int, int>::iterator it;
		int max = 0;
		for (it=count.begin(); it!=count.end(); it++) {
			if (it->second > max)
				max = it->second;
		}
		printf("Case #%d: %d\n", test, max);
	}

	return 0;
}