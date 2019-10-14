#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

vector<int> towns[100];
int cars[100];
int main()
{
	ifstream cin("BR-small.in");
	ofstream cout("BR-small.out");
	int C;
	cin >> C;
	for(int cc = 1; cc<= C; cc++)
	{
		int N,T;
		cin >> N >> T;
		for(int i = 0; i < N; i++)
			towns[i].clear();
		int E;
		cin >> E;
		for(int i = 0; i < E; i++)
		{
			int H, P;
			cin >> H >> P;
			towns[H-1].push_back(P);
		}

		bool valid = true;
		for(int i = 0; i < N && valid; i++)
		{
			cars[i] = 0;
			if(i == T-1)
				continue;
			sort(towns[i].begin(),towns[i].end());
			reverse(towns[i].begin(),towns[i].end());
			int sz = towns[i].size();
			int j = 0;
			cars[i] = 0;
			while(j < sz && valid)
			{
				cars[i]++;
				if(towns[i][j] == 1)
					j++;
				else if(towns[i][j] > 1)
				{
					sz -= towns[i][j]-1;
					j++;
					
				}
				else
					valid = false;
			}
		}
		cout << "Case #" << cc << ": ";
		if(!valid)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << cars[0];
			for(int i = 1; i < N; i++)
				cout << " " << cars[i];
			cout << endl;
		}
	}
}