#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct trainLine
{
	int dir, start, end;
};

bool compareLine(trainLine L1, trainLine L2)
{
	return (L1.start < L2.start);
}

int N, T, NA, NB;

int main()
{
	ifstream input;
	ofstream output;
	input.open("B-large.in");
	output.open("B-large.out");

	input >> N;

	for (int c = 0; c < N; c++)
	{
		input >> T;
		input >> NA >> NB;

		vector<trainLine> lines;

		for (int i = 0; i < NA; i++)
		{
			trainLine line;
			line.dir = 0;

			string startTime, endTime;
			input >> startTime >> endTime;

			line.start = (startTime[0] - '0') * 600 + (startTime[1] - '0') * 60 + (startTime[3] - '0') * 10 + (startTime[4] - '0');
			line.end = (endTime[0] - '0') * 600 + (endTime[1] - '0') * 60 + (endTime[3] - '0') * 10 + (endTime[4] - '0');

			lines.push_back(line);
		}

		for (int i = 0; i < NB; i++)
		{
			trainLine line;
			line.dir = 1;

			string startTime, endTime;
			input >> startTime >> endTime;

			line.start = (startTime[0] - '0') * 600 + (startTime[1] - '0') * 60 + (startTime[3] - '0') * 10 + (startTime[4] - '0');
			line.end = (endTime[0] - '0') * 600 + (endTime[1] - '0') * 60 + (endTime[3] - '0') * 10 + (endTime[4] - '0');

			lines.push_back(line);
		}

		sort(lines.begin(), lines.end(), compareLine);

		int ansA = 0;
		int ansB = 0;

		vector<bool> cover(NA + NB);

		for (int i = 0; i < NA + NB; i++)
			if (!cover[i])
			{
				if (lines[i].dir == 0) 
					ansA++;
				else
					ansB++;
				int time = lines[i].end;
				int dir = lines[i].dir;
				for (int j = i + 1; j < NA + NB; j++)
					if (!cover[j] && lines[j].dir != dir && lines[j].start >= time + T)
					{
						cover[j] = true;
						time = lines[j].end;
						dir = lines[j].dir;
					}
			}

		output << "Case #" << c + 1 << ": " << ansA << " " << ansB << endl;
	}
	
	input.close();
	output.close();
}