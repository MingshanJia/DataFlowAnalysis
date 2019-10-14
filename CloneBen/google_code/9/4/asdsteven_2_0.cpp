#include <cstdio>
#include <vector>
using namespace std;

int solve() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<int> a;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < N; i++)
	for (int j = (int)a.size(); j-- > 2;) {
		if (a[j] == a[j - 1] && a[j - 1] == a[j - 2]) {
			a.erase(a.begin() + j);

			a.erase(a.begin() + (j - 1)); a.erase(a.begin() + (j - 2)); 
			j -= 2;
		}
	}
	return a.size();
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %d\n", i, solve());
}