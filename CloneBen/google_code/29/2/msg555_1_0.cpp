#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int dr[]={0,1,0,-1,1,1,-1,-1};
int dc[]={1,0,-1,0,1,-1,1,-1};
#define zmax(a,b) (((a)>(b))?(a):(b))
#define zmin(a,b) (((a)>(b))?(b):(a))
#define zabs(a) (((a)>=0)?(a):(-(a)))
#define iif(c,t,f) ((c)?(t):(f))
template<class A, class B> A cvt(B x) {stringstream s;s<<x;A r;s>>r;return r;}

#include<fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");

int denter [] = {4, 1, 8, 2};
int dexit [] = {8, 2, 4, 1};

int main()
{
	int n; fin >> n;

	for(int i = 1; i <= n; i++)
	{
		string s1; fin >> s1;
		string s2; fin >> s2;

		map< pair<int, int >, int > mp;

		int minrow = 0;
		int mincol = 0;
		int maxrow = 0;
		int maxcol = 0;

		int r = -1;
		int c = 0;
		int dir = 1;
		for(int i = 0; i < s1.size(); i++)
		{
			if(s1[i] == 'L') dir = (dir + 3) % 4;
			else if(s1[i] == 'R') dir = (dir + 1) % 4;
			else
			{
				mp[make_pair(r, c)] |= dexit[dir];
				r += dr[dir];
				c += dc[dir];
				mp[make_pair(r, c)] |= denter[dir];
					if(i + 1 != s1.size())
				{
					minrow <?= r;
					mincol <?= c;
					maxrow >?= r;
					maxcol >?= c;
				}
			}
		}
		dir = (dir + 2) % 4;
		for(int i = 0; i < s2.size(); i++)
		{
			if(s2[i] == 'L') dir = (dir + 3) % 4;
			else if(s2[i] == 'R') dir = (dir + 1) % 4;
			else
			{
				mp[make_pair(r, c)] |= dexit[dir];
				r += dr[dir];
				c += dc[dir];
				mp[make_pair(r, c)] |= denter[dir];
					if(i + 1 != s2.size())
				{
					minrow <?= r;
					mincol <?= c;
					maxrow >?= r;
					maxcol >?= c;
				}
			}
		}

		fout << "Case #" << i << ":" << endl;
		for(int r = minrow; r <= maxrow; r++)
		{
			for(int c = mincol; c <= maxcol; c++)
			{
				int val = mp[make_pair(r, c)];
				if(val < 10) fout << (char)('0' + val);
				else fout << (char)('a' + val - 10);
			}
			fout << endl;
		}
	}

	#ifdef NOTSUBMIT
	system("pause");
	#endif
	return 0;
}






