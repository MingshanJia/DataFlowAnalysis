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
	fin.open("B-small-attempt0.in");
	fout.open("B-small-attempt0.out");
	int numcas;
	fin>>numcas;
	f(cas,1,numcas+1)
	{
		bool done=false;
		fout<<"Case #"<<cas<<": ";
		int n,t,e,temp,temp2;
		fin>>t>>n>>e;
		vector<int> cars [t];
		int emps [t];
		int aval [t];
		f(i,0,t)
		{
			cars[i].clear();
			emps[i]=0;
			aval[i]=0;
		}
		f(i,0,e)
		{
			fin>>temp>>temp2;
			emps[temp-1]++;
			aval[temp-1]+=temp2;
			cars[temp-1].pb(temp2);
		}
		int ans[t];
		f(i,0,t)
		{
			ans[i]=0;
		}
		f(i,0,t)
		{
			if(i==n-1)
			{
				ans[i]=0;
			}
			else
			{
				if(emps[i]>aval[i]&&(!done))
				{
					fout<<"IMPOSSIBLE\n";
					done=true;
					break;
				}
				if(!done)
				{
					
					sort(cars[i].begin(),cars[i].end());
					int curr=cars[i].size()-1;
					while(emps[i]>0&&curr>=0)
					{
						emps[i]-=cars[i][curr];
						curr--;
						ans[i]++;
					}
				}
			}
		}
		if(!done)
		{
			f(i,0,t-1)
			{
				fout<<ans[i]<<" ";
			}
			fout<<ans[t-1]<<"\n";
		}
		
	}
	fin.close();
	fout.close();
	return 0;	
}
