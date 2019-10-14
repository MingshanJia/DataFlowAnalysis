#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
	ofstream fout("A-large.out");
	ifstream fin("A-large.in");
	
	int T;
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		fin >> N;
		string s;
		int arr[50];
		for(int p = 0; p < N; p++)
		{
			fin >> s;
			arr[p] = -1;
			for(int t = s.size()-1; t >= 0; t--)
				if(s[t] == '1')
				{
					arr[p] = t;
					break;
				}
		}
		
		int ans = 0;
		for(int p = 0; p < N; p++)
			if(arr[p] <= p) continue;
			else
			{
				int tmp = p+1;
				while(arr[tmp] > p)
					tmp++;
				int x = arr[tmp];
				ans += (tmp-p);
				for(int q = tmp; q > p; q--)
					arr[q] = arr[q-1];
				arr[p] = x;
			}
		
		fout << "Case #" << i+1 << ": " << ans << endl;
	}
				
	
	
	

	return 0;
}
		
