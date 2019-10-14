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

int main()
{
	int n; fin >> n;
	
	for(int i = 0; i < n; i++)
	{
		string num; fin >> num;
		string lng1; fin >> lng1;
		string lng2; fin >> lng2;

		map<char, int> mp1;
		map<int, char> mp2;
		for(int i = 0; i < lng1.size(); i++) mp1[lng1[i]] = i;
		for(int i = 0; i < lng2.size(); i++) mp2[i] = lng2[i];

		int val = 0;
		for(int i = 0; i < num.size(); i++)
		{
			val *= lng1.size();
			val += mp1[num[i]];
		}

		string result;
		if(val == 0)
		{
			result += mp2[0];
		}
		else
		{
			while(val)
			{
				result += mp2[val % lng2.size()];
				val /= lng2.size();
			}
			reverse(result.begin(), result.end());
		}
		fout << "Case #" << i + 1 << ": " << result << endl;
	}

	#ifdef NOTSUBMIT
	system("pause");
	#endif
	return 0;
}






