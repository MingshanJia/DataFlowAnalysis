#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

int main(void) {
	int t, n;
	string arr[101];
	scanf("%d", &t);
	for (int tn = 1; tn <= t; ++tn) {
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			getline(cin, arr[i]);
		}
		int cost = 0, prev = 0;
		for (int i = 0; i < n-1; ++i) {
			if (arr[i+1] < arr[prev]) {
				cost++;
			}
			else
				prev = i+1;
		}
		printf("Case #%d: %d\n", tn, cost);
	}
	return 0;
}