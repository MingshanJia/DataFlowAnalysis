#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;

		vector<pair<int, int> > buses;

		for (int n = 0; n < N; ++n) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			buses.push_back(make_pair(a, b));
		}

		int P;
		cin >> P;

		vector<int> results;

		for (int p = 0; p < P; ++p) {
			int q;
			cin >> q;
			int r = 0;
			for (auto i = buses.begin(); i != buses.end(); ++i) {
				if (i->first <= q && q <= i->second) {
					++r;
				}
			}
			results.push_back(r);
		}

		cout << "Case #" << (t+1) << ":";
		for (auto i = results.begin(); i != results.end(); ++i) {
			cout << " " << *i;
		}
		cout << endl;
	}
}