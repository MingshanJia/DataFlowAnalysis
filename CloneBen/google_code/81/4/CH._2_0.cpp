#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
struct Card
{
	int c, s, t;
	bool operator < (const Card &B) const
	{
		if (t < B.t) return true;
		if (B.t < t) return false;
		if (c < B.c) return true;
		if (B.c < c) return false;
		if (s < B.s) return true;
		if (B.s < s) return false;
		return false;
	}
};

vector<Card> hand;
vector<Card> deck;
int maxp;

int GetMaxPoints(int max2, int max1, vector<Card> H, vector<Card> D)
{
	priority_queue<Card> PQ;
	int t = 1;
	int s = 0;
	size_t di = 0;
	for (size_t i = 0; i < H.size(); i++)
		PQ.push(H[i]);

	while (t > 0 && PQ.size() > 0)
	{
		Card tmp = PQ.top();
		PQ.pop();

		if (tmp.t > 0)
		{
			s += tmp.s;
			t += tmp.t;
			int next = di + tmp.c;
			for (;di < next && di < D.size(); di++)
				PQ.push(D[di]);
			t--;
		}
		else
		{
			if (tmp.c == 2)
			{
				if (max2)
				{
					max2--;
					s += tmp.s;
					t += tmp.t;
					int next = di + tmp.c;
					for (;di < next && di < D.size(); di++)
						PQ.push(D[di]);
					t--;				
				}
			}
			else if (tmp.c == 1)
			{
				if (max1)
				{
					max1--;
					s += tmp.s;
					t += tmp.t;
					int next = di + tmp.c;
					for (;di < next && di < D.size(); di++)
						PQ.push(D[di]);
					t--;								
				}
			}
			else
			{
				s += tmp.s;
				t--;
			}
		}
	}

	return s;
}

int main()
{
	freopen ("C.in", "r", stdin);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		hand.clear();
		deck.clear();
		maxp = 0;
		int n, m;
		int doinr = 0, ununr = 0;

		cin >> n;
		for (int j = 0; j < n; j++)
		{
			Card tmp;
			cin >> tmp.c >> tmp.s >> tmp.t;
			hand.push_back(tmp);
			if (tmp.t == 0)
			{
				if (tmp.c == 2) doinr++;
				if (tmp.c == 1) ununr++;
			}
		}

		cin >> m;

		for (int j = 0; j < m; j++)
		{
			Card tmp;
			cin >> tmp.c >> tmp.s >> tmp.t;
			deck.push_back(tmp);
			if (tmp.t == 0)
			{
				if (tmp.c == 2) doinr++;
				if (tmp.c == 1) ununr++;
			}
		}

		for (int x = 0; x <= doinr; x++)
			for (int y = 0; y <= ununr; y++)
			{
				int p = GetMaxPoints(x, y, hand, deck);
				if (p > maxp)
					maxp = p;
			}

		cout << "Case #" << i + 1 << ": " << maxp << "\n";
	}

	return 0;
}
