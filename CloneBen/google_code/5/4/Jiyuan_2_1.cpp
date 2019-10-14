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
		int numNames;
		inputs >> numNames;
		inputs.ignore(numeric_limits<streamsize>::max(), '\n');
		int count = 0;
		string largestName;
		for (int i = 0; i < numNames; ++i)
		{
			string name;
			getline(inputs, name);
			if (name < largestName)
			{
				++count;
			}
			if (name > largestName)
			{
				largestName = name;
			}
		}

		printHeader(caseid);
		logs << count << endl;
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

