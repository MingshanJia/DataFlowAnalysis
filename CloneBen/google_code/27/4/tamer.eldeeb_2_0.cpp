#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int probs[60];
int main()
{
	ifstream cin("CR-small.in");
	ofstream cout("CR-small.out");
	int T;
	cin >> T;
	for(int cc = 1; cc <= T; cc++)
	{
		int P, C;
		cin >> P >> C;
		for(int i = 0; i < P; i++)
			cin >> probs[i];
		
		int res = 0;
		while(true)
		{
			sort(probs,probs+P);
			reverse(probs,probs+P);
			int c = C;
			for(int i = 0; i < P && c; i++)
				if(probs[i])
				{
					c--;
					probs[i]--;
				}

			if(c > 0)
				break;
			res++;

		}

		cout << "Case #" << cc << ": " << res << endl;
	}
}