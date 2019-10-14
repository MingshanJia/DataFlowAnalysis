#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int malt[2100];
int unm[2100];

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int n,m;
		int i,j;
		//istringstream strin();
		fin >> n >> m;
		FI(i,0,m)
		{
			int t;
			fin >> t;
			int p,q;
			int k = 0;
			malt[i] = -1;
			FI(j,0,t)
			{
				fin >> p >> q;
				p--;
				if (q == 1) malt[i] = p;
				else k |= (1<<p);
			}
			unm[i] = k;
		}

		int ans = n+1, sel = 0;
		int nn = 1<<n;
		FI(i,0,nn)
		{
			int k = 0, i1 = 0;
			i1 = i;
			while (i1 > 0)
			{
				k += i1%2;
				i1 /= 2;
			}
			//cout << i << ' ' << k << endl;
			if (k > ans) continue;
			int j = 0;
			while (j < m)
			{
				if (malt[j] >= 0 && (i & (1<<malt[j])) > 0)
					;
				else if ((nn-1-i) & unm[j])
					;
				else break;
				j++;
			}
			//cout << j << endl;
			if (j >= m)
			{
				if (k == ans)
					cout << "error" << k << endl;
				ans = k;
				sel = i;
			}
		}
		fout << "Case #" << tind << ":";
		if (ans > n)
			fout << " IMPOSSIBLE" << endl;
		else
		{
			FI(j,0,n) if (sel & (1<<j)) fout << " 1"; else fout << " 0";
			fout << endl;
		}
	}
	return 0;
}
