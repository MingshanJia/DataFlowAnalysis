#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T, N;
	string card;
	vector<string> cards;
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cards.clear();
		cin >> N;
		getline(cin, card);
		for (int i = 0; i < N; i++) {
			getline(cin, card);
			cards.push_back(card);
		}

		int cost = 0;
		string max = cards[0];
		for (int i = 1; i < N; i++) {
			card = cards[i];
			if (card < max) cost++;
			else max = card;
		}

		cout << "Case #" << t << ": " << cost << endl;
	}
}