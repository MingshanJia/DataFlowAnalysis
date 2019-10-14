#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, S, Q;

int main()
{
	ifstream input;
	ofstream output;
	input.open("A-large.in");
	output.open("A-large.out");

	input >> N;

	for (int c = 0; c < N; c++)
	{
		input >> S;		
		map<string,int> engines;

		for (int i = 0; i < S; i++)
		{
			string engine;
			if (i == 0) getline(input, engine);
			getline(input, engine);
			engines[engine] = i;
		}

		vector<bool> used(S);
		for (int i = 0; i < S; i++) used[i] = false;

		input >> Q;
		int switches = 0;
		int numUsed = 0;

		for (int i = 0; i < Q; i++)
		{
			string query;
			if (i == 0) getline(input, query);
			getline(input, query);

			if (!used[engines[query]])
			{
				used[engines[query]] = true;
				numUsed++;
			}

			if (numUsed == S)
			{
				switches++;
				for (int j = 0; j < S; j++) used[j] = false;
				used[engines[query]] = true;
				numUsed = 1;
			}
		}

		output << "Case #" << c + 1 << ": " << switches << endl;
	}

	input.close();
	output.close();
}