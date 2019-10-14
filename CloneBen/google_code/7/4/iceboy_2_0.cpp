#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;

		unordered_map<string, string> next;
		unordered_map<string, string> prev;
		for (int n = 0; n < N; ++n) {
			string from, to;
			cin >> from >> to;
			next.insert(make_pair(from, to));
			prev.insert(make_pair(to, from));
		}

		string first = prev.begin()->second;
		while (true) {
			auto i = prev.find(first);
			if (i == prev.end())
				break;
			first = i->second;
		}

		cout << "Case #" << (t+1) << ":";
		while (true) {
			auto i = next.find(first);
			if (i == next.end())
				break;
			cout << " " << i->first << "-" << i->second;
			first = i->second;
		}
		cout << endl;
	}
}