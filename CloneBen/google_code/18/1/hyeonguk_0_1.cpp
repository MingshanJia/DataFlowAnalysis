
#include <cstdio>
#include <iostream>
#include <fstream>

#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <queue>

using namespace std;

#include <climits>

ifstream file_in("input.txt");
ofstream file_out("output.txt");

void TestCase();

int main()
{
	int n;
	file_in >> n;

	for (int i = 1; i <= n; i++)
	{
		file_out << "Case #" << i << ": ";
		TestCase();
		file_out << endl;
	}
}

const pair<int, int> Operations[9] =
{
	make_pair(0, 0), make_pair(0, 1), make_pair(0, 2),
	make_pair(1, 0), make_pair(1, 1), make_pair(1, 2),
	make_pair(2, 0), make_pair(2, 1), make_pair(2, 2),
};

void TestCase()
{
	long long n, a, b, c, d, e, f;
	file_in >> n >> a >> b >> c >> d >> e >> f;

	long long p[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			file_in >> p[i][j];
		}
	}

	vector<pair<int, int>> operations;
	for (int i = 0; i < 9; i++)
	{
		operations.push_back(Operations[i]);
	}

	sort(operations.begin(), operations.end());

	long long answer = _I64_MIN;

	do
	{
		long long current = 0;

		long long
			green[3] = {a, b, c},
			red[3] = {d, e, f};
		
		for each (auto &op in operations)
		{
			auto i = op.first;
			auto j = op.second;

			long long amount = min(green[i], red[j]);
			green[i] -= amount;
			red[j] -= amount;

			current += p[i][j] * amount;
		}

		answer = max(answer, current);

	} while(next_permutation(operations.begin(), operations.end()));

	file_out << answer;
}
