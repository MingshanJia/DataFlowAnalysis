#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int array[505][20];

int main()
{
	ofstream fout("C-large.out");
	ifstream fin("C-large.in");
	
	string def = "welcome to code jam";
	
	int T;
	fin >> T;
	string s;
	getline(fin,s);
	

	for(int i = 0; i < T; i++)
	{
		long long ans = 0;
		
		getline(fin,s);
		
		for(int k = 0; k < 505; k++)
		for(int j = 0; j < 20; j++)
			array[k][j] = 0;
		
		for(int j = 0; j < s.size(); j++)
		{
			for(int k = 0; k < def.size(); k++)
			{
				array[j+1][k] += array[j][k];
				array[j+1][k] %= 10000;
				if(s[j] == def[k])
				{
					if(k == 0)
					{
						array[j+1][1]++;
						array[j+1][1] %= 10000;
					}
					else
					{
						array[j+1][k+1] += array[j][k];
						array[j+1][k+1] %= 10000;
					}
				}
			}
			ans += array[j+1][19];
			ans %= 10000;
		}
							
		fout << "Case #" << i+1 << ": " << ans/1000 << (ans/100)%10 << (ans/10)%10 << ans%10 << endl;
	}
	return 0;
}
		
