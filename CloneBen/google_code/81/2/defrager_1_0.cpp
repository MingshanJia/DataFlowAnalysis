#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

vector<string> dict;

int getPoints(string guess, string a)
{
	int total = 0;
	vector<string> remain;
	
	for (int i = 0; i < dict.size(); i++)
		if (dict[i].size() == guess.size())
			remain.push_back(dict[i]);

	for (int l = 0; l < a.size(); l++)
	{
		char c = a[l];
		bool f = false;

		for (int j = 0; j < remain.size(); j++)
		{
			if (find(remain[j].begin(), remain[j].end(), c) != remain[j].end())
			{
				f = true;
				break;;
			}
		}
		if (!f)
			continue;

		if (find(guess.begin(), guess.end(), c) != guess.end())
		{
			int j = 0;
			for (int i = 0; i < remain.size(); i++)
			{
				bool remove = false;

				for (int p = 0; p < remain[i].size(); p++)
				{
					if ((remain[i][p] == c) != (guess[p] == c))
					{
						remove = true;
						break;
					}
					
				}
				if (!remove)
				{
					remain[j++] = remain[i];
				}
			}
			
			remain.resize(j);
		}
		else
		{
			total++;

			int j = 0;
			for (int i = 0; i < remain.size(); i++)
			{
				if (find(remain[i].begin(), remain[i].end(), c) == remain[i].end())
				{
					remain[j++] = remain[i];
				}
			}
			remain.resize(j);
		}
		
	}


	return total;
}

string solve(string a)
{
	int bestPoint = -1;
	string res;

	for (int i = 0; i< dict.size(); i++)
	{
		int pts = getPoints(dict[i], a);

		if( pts > bestPoint)
		{
			bestPoint =pts;
			res = dict[i];
		}
	}


	return res;
}

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);

	for (int nTest = 1; nTest <= T; nTest++)
	{		
		int N, M;
		cin >> N >> M;
		
		dict.resize(N);
		rep(i, N)
			cin >> dict[i];

		string ans;

		rep(i, M)
		{
			string a;
			cin >> a;

			ans = ans + ' ' + solve(a);
		}
	
		printf("Case #%d: %s\n", nTest, ans.c_str());
		fflush(stdout);
	} 

 
	return 0;
}


