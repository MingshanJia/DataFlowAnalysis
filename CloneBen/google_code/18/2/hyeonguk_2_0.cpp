
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
#include <minmax.h>

using namespace std;

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


#define WALL INT_MAX
#define ROOM INT_MIN

const int
	MoveX[4] = {0, 0, 1, -1},
	MoveY[4] = {1, -1, 0, 0};

void DoFloodFill(vector<vector<int>> &design, pair<int, int> seed, int color,
	vector<pair<int, int>> &statistics)
{
	int n = design.size(),
		m = design[0].size();

	queue<pair<int, int>> q;
	q.push(seed);

	design[seed.first][seed.second] = color;

	while (q.empty() == false)
	{
		statistics.push_back(q.front());
		auto current_x = q.front().first;
		auto current_y = q.front().second;
		q.pop();

		for (int p = 0; p < 4; p++)
		{
			auto next_x = MoveX[p] + current_x;
			auto next_y = MoveY[p] + current_y;
		
			if (0 <= next_x && next_x < n &&
				0 <= next_y && next_y < m)
			{
				if (design[next_x][next_y] == ROOM)
				{
					design[next_x][next_y] = color;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}

void FloodFill(vector<vector<int>> &design, vector<vector<pair<int, int>>> &statistics)
{
	int n = design.size(),
		m = design[0].size();
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(design[i][j] == ROOM)
			{
				statistics.push_back(vector<pair<int, int>>());
				DoFloodFill(design, make_pair(i, j), statistics.size() - 1, statistics.back());
			}
		}
	}
}

int Search(vector<vector<bool>> &graph, vector<bool> &color, vector<bool> &went, int seed, const vector<int> &attempt)
{
	int v = attempt.size();
	queue<int> q;
	q.push(seed);
	
	int count = 0;

	while (q.empty() == false)
	{
		auto current = q.front();
		auto current_color = color[current];
		q.pop();
		count++;
		went[current] = true;

		for (int next = 0; next < v; next++)
		{
			if (graph[attempt[current]][attempt[next]] && !went[next])
			{
				if(current_color == true &&
					color[next] == true)
				{
					return INT_MIN;
				}

				went[next] = true;
				q.push(next);
			}
		}
	}

	return count;
}

bool Test(vector<vector<bool>> &graph, vector<bool> &color, const vector<int> &attempt)
{
	int v = attempt.size();
	vector<bool> went(v, false);
	
	int remaining = v;

	for (int i = 0; i < v && remaining > 0; i++)
	{
		if (went[i] == false)
		{
			auto result = Search(graph, color, went, i, attempt);
			if (result < 0)
			{
				return false;
			}

			remaining -= result;
		}
	}

	return true;
}

void BruteForce(vector<vector<bool>> &graph, int &answer, int current, int v, vector<bool> &color, int count, const vector<int> &attempt)
{
	if (current < v)
	{
		color[current] = true;
		BruteForce(graph, answer, current + 1, v, color, count + 1, attempt);
		color[current] = false;
		BruteForce(graph, answer, current + 1, v, color, count, attempt);

		return;
	}

	if (answer > count)
	{
		return;
	}

	auto result = Test(graph, color, attempt);	

	if (result == true)
	{
		answer = max(answer, count);
	}
}

void MakeIndex(vector<vector<bool>> &graph, vector<vector<int>> &index)
{
	int v = graph.size();
	vector<bool> went(v, false);
	
	for (int i = 0; i < v; i++)
	{
		if (went[i] == false)
		{
			queue<int> q;
			q.push(i);

			index.push_back(vector<int>());

			while (q.empty() == false)
			{
				auto current = q.front();
				q.pop();
				went[current] = true;
				index.back().push_back(current);

				for (int next = 0; next < v; next++)
				{
					if (graph[current][next] && !went[next])
					{
						went[next] = true;
						q.push(next);
					}
				}
			}
		}
	}
}

void TestCase()
{
	int n, m, k;
	file_in >> n >> m >> k;

	vector<vector<vector<int>>> design(k);
	vector<vector<vector<pair<int, int>>>> statistics(k);
	vector<vector<int>> mapping(k);
	vector<vector<bool>> graph;

	int v = 0;

	for (int z = 0; z < k; z++)
	{
		design[z].resize(n);
		
		for (int y = 0; y < n; y++)
		{
			design[z][y].resize(m);

			char input[32];
			file_in >> input;
			
			for (int x = 0; x < m; x++)
			{
				design[z][y][x] = input[x] == '#' ? WALL : ROOM;
			}
		}

		FloodFill(design[z], statistics[z]);
		mapping[z].resize(statistics[z].size());

		for (size_t i = 0; i < statistics[z].size(); i++)
		{
			mapping[z][i] = v;
			v++;
		}
	}

	graph.resize(v);
	for (int i = 0; i < v; i++)
	{
		graph[i].resize(v, false);
	}
	
	for (int z = 1; z < k; z++)
	{
		for each (auto &statistic in statistics[z])
		{
			for each (auto &point in statistic)
			{
				auto i = point.first;
				auto j = point.second;

				if (design[z - 1][i][j] != WALL)
				{
					auto a = mapping[z - 1][design[z - 1][i][j]];
					auto b = mapping[z][design[z][i][j]];
					
					graph[a][b] = graph[b][a] = true;
				}
			}
		}
	}

	/*
	for(auto i=0; i<v; i++){
		for(auto j = 0; j<v; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	vector<vector<int>> index;
	MakeIndex(graph, index);
	
	int real_answer = 0;

	for each (auto &attempt in index)
	{
		int answer = 0;
		vector<bool> color(attempt.size());
		BruteForce(graph, answer, 0, attempt.size(), color, 0, attempt);
		real_answer += answer;
	}

	file_out << real_answer;
}
