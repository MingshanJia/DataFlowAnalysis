#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string S[5000];

int main()
{
	ofstream fout("A-large.out");
	ifstream fin("A-large.in");
	
	int L,D,N;
	fin >> L >> D >> N;
	
	for(int i = 0; i < D; i++)
		fin >> S[i];

	string s;

	for(int i = 0; i < N; i++)
	{
		fout << "Case #" << i+1 << ": ";
		fin >> s;
		long long innit[15];
		for(int p = 0; p < 15; p++)
			innit[p] = 0;
		int ptr = 0;
		for(int p = 0; p < L; p++)
		{
			long long curr = 0;
			if(s[ptr] != '(')
				curr |= (1<<(s[ptr]-'a')), ptr++, innit[p] = curr;
			else
			{
				ptr++;
				while(s[ptr] != ')')
					curr |= (1<<(s[ptr]-'a')), ptr++;
				ptr++;
				innit[p] = curr;
			}
		}
		
		int ans = 0;
		
		for(int q = 0; q < D; q++)
		{
			int ok = 1;
			for(int r = 0; r < L; r++)
				if((innit[r]>>(S[q][r]-'a'))%2 == 0)
				{
					ok = 0;
					break;
				}
			if(ok == 1) ans++;
		}
	
		fout << ans << endl;
	}
	return 0;
}
		
