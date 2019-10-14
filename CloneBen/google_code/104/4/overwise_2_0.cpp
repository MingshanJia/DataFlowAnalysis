#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
	int kases, kase = 0;
	for (cin >> kases; kases; kases--)
	{
		int K;
		cin >> K;
		vector<int> deck(1, K);
		int pos = 0;
		for (int i = K-1; i > 0; i--)
		{
			pos = ((pos - i) + 1000000000LL*deck.size()) % deck.size();
			deck.insert(deck.begin() + pos, i);
		}

		cout << "Case #" << ++kase << ":";
		int n;
		cin >> n;
		while (n--)
		{
			int x;
			cin >> x;
			cout << " " << deck[(pos + x - 1) % K];
		}
		cout << endl;
	}
	return 0;
}
