#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <chrono>
#include <memory>

#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

using namespace std;

ifstream inputs("D:\\vsproj\\oj\\problem.txt");
ofstream logs("D:\\vsproj\\oj\\log.txt");

class Solution
{
public:
	void solve(int caseid)
	{
		int numPair;
		inputs >> numPair;
		inputs.ignore(numeric_limits<streamsize>::max(), '\n');

		int uid = 0;
		unordered_map<string, int> nameLUT;
		auto uidOf = [&](string name)
		{
			int id;
			if (nameLUT.find(name) != nameLUT.end())
			{
				id = nameLUT.at(name);
			}
			else
			{
				id = uid;
				nameLUT[name] = uid;
				++uid;
			}
			return id;
		};
		vector<pair<int, int>> conflicts(numPair);
		for (int i = 0; i < numPair; ++i)
		{
			string line;
			getline(inputs, line);
			auto space = line.find(' ');
			string name1 = line.substr(0, space);
			string name2 = line.substr(space + 1);
			conflicts[i] = minmax(uidOf(name1), uidOf(name2));
		}
		int numGuy = int(nameLUT.size());
		vector<vector<char>> mask(numGuy, vector<char>(numGuy, 0));
		for (auto p : conflicts)
		{
			mask[p.first][p.second] = 1;
			mask[p.second][p.first] = 1;
		}
		// now bipartite Graph of mask
		vector<char> color(numGuy, 0);
		for (int i = 0; i < numGuy; ++i)
		{
			if (color[i] == 0)
			{
				if (!depthFirstColoring(mask, color, i, 1))
				{
					printHeader(caseid);
					logs << "No" << endl;
					return;
				}
			}
		}
		printHeader(caseid);
		logs << "Yes" << endl;
	}

	bool depthFirstColoring(const vector<vector<char>> &mask, vector<char> &color, int at, int c)
	{
		if (color[at] != 0)
		{
			return color[at] == c;
		}

		color[at] = c;
		for (int i = 0; i < mask.size(); ++i)
		{
			if (mask[at][i] != 0)
			{
				if (!depthFirstColoring(mask, color, i, 3 - c))
				{
					return false;
				}
			}
		}
		return true;
	}

private:
	void printHeader(int caseid)
	{
		logs << "Case #" << caseid << ": ";
	}
};


int main(int argc, char **argv)
{
	int totalQ;
	inputs >> totalQ;
	inputs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int caseid = 1; caseid <= totalQ; ++caseid)
	{
		//cout << caseid << "..." << flush;
		//auto ts = std::chrono::steady_clock::now();
		Solution().solve(caseid);
		//auto tt = std::chrono::steady_clock::now();
		//cout << "done!" << "\ttime " << std::chrono::duration_cast<std::chrono::milliseconds>(tt - ts).count() << "ms" << endl;
	}

	return 0;
}

