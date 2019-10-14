#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Word
{
	string w;
	int let_code;
	int group;
	int points_lost;
	int initial_id;

	bool operator <(const Word &B) const
	{
		if (group < B.group) return true;
		if (B.group < group) return false;
		if (let_code < B.let_code) return true;
		return false;
	}
};

bool SizeCompare(Word A, Word B)
{
	return A.w.size() < B.w.size();
}

string BestWord(vector<Word> V)
{
	int maxp = 0;
	int minindex = 1<<20;
	string rez;
	for (int i = 0; i < V.size(); i++)
		if (V[i].points_lost > maxp)
			rez = V[i].w, maxp = V[i].points_lost, minindex = V[i].initial_id;
		else if (V[i].points_lost == maxp && V[i].initial_id < minindex)
			rez = V[i].w, maxp = V[i].points_lost, minindex = V[i].initial_id;

	return rez;			
}

string GetWord(vector<Word> V, string L)
{
	vector<bool> penalty(V.size(), false);

	//sort by size	
	sort(V.begin(), V.end(), SizeCompare);
	int g = 0;
	for (int i = 1; i < V.size(); i++)
		if (V[i].w.size() != V[i - 1].w.size())
			V[i].group = ++g;
		else V[i].group = g;

	if (g + 1 == V.size())
		return BestWord(V);

	for (int i = 0; i < L.size(); i++)
	{
		char c = L[i];
		//determine letter code
		for (int j = 0; j < V.size(); j++)
		{
			int code = 0;
			for (int t = 0; t < V[j].w.size(); t++)
				if (V[j].w[t] == c)
					code += 1<<t;

			V[j].let_code = code;
		}

		sort(V.begin(), V.end());

		//add penalty
		for (int j = 0; j < V.size(); j++)
			penalty[j] = false;

		for (int j = 0; j < V.size(); j++)
			if (V[j].let_code != 0)
				penalty[V[j].group] = true;

		for (int j = 0; j < V.size(); j++)
			if (V[j].let_code == 0 && penalty[V[j].group])
				V[j].points_lost++;

		g = 0;
		int old_group = V[0].group;
		V[0].group = 0;
		for (int j = 1; j < V.size(); j++)
			if (V[j].group != old_group || V[j].let_code != V[j - 1].let_code)
				old_group = V[j].group, V[j].group = ++g;
			else V[j].group = g;				
	}

	return BestWord(V);
}

vector<Word> V;

int main()
{
	freopen ("B.in", "r", stdin);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		V.clear();
		int n, m;		
		cin >> n >> m;		
		for (int j = 0; j < n; j++)
		{
			Word tmp;
			cin >> tmp.w;
			tmp.let_code = 0;
			tmp.group = 0;
			tmp.points_lost = 0;
			tmp.initial_id = j;
			V.push_back(tmp);
		}

		cout << "Case #" << i + 1 << ":";
		for (int j = 0; j < m; j++)
		{
			string L;
			cin >> L;
			cout << " " << GetWord(V, L);
		}
		cout << "\n";
	}
	return 0;
}

