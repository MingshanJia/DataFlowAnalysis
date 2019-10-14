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
		int V, D;
		inputs >> V >> D;
		static const double G = 9.8;
		double s = G * D / (1.0 * V * V);
		double theta = asin(max(0.0,min(1.0, s))) * 90.0 / M_PI;

		assert(isnormal(theta));

		printHeader(caseid);
		auto p = logs.precision();
		logs.precision(10);
		logs << theta << endl;
		logs.precision(p);
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

