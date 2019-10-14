#include<vector>
#include<fstream>
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<string>
#include<sstream>
#include<algorithm>

#define x first
#define y second
#define pb push_back
#define f(i,a,b) for(int (i)=(a);(i)<(b);(i)++)

using namespace std;

ifstream fin;
ofstream fout;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,double> pid;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;

int main()
{
	fin.open("A-large.in");
	fout.open("A-large.out");
	int numcas;
	fin>>numcas;
	int g;
	f(cas,1,numcas+1)
	{
		fin>>g;
		long long glist[g];
		f(i,0,g)
		{
			fin>>glist[i];
		}
		sort(glist,glist+g);
		if(glist[0]!=glist[1])
		{
			fout<<"Case #"<<cas<<": "<<glist[0];
		}
		f(i,1,g-1)
		{
			if(glist[i]!=glist[i-1]&&glist[i]!=glist[i+1])
			{
				fout<<"Case #"<<cas<<": "<<glist[i];
			}
		}
		if(glist[g-2]!=glist[g-1])
		{
			fout<<"Case #"<<cas<<": "<<glist[g-1];
		}
		fout<<"\n";
	}
	fin.close();
	fout.close();
	return 0;	
}
