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
	fin.open("C-small-attempt0.in");
	fout.open("C-small-attempt0.out");
	int numcas;
	fin>>numcas;
	f(cas,1,numcas+1)
	{
		fout<<"Case #"<<cas<<": ";
		//cerr<<"Case #"<<cas<<": \n";
		int p,c;
		unsigned long long ans=0;
		fin>>p>>c;
		long long probs[p];
		f(i,0,p)
		{
			fin>>probs[i];
		}		
		sort(probs,probs+p);
		if(p==c)
		{
			fout<<probs[0]<<"\n";
		}
		else
		{
				
			while(probs[p-c]!=0)
			{
			/*	f(i,0,p)
				{
					cerr<<probs[i]<<" ";
				}*/
				if(probs[p-c-1]==0)
				{
					ans+=probs[p-c]-probs[p-c-1];
					//cerr<<"\n"<<ans<<"\n";
					for(int i=p-1;i>=p-c;i--)
					{
						probs[i]-=probs[p-c]-probs[p-c-1];
					}
				}
				else
				{
					ans+=probs[p-c]-probs[p-c-1]+1;
					//cerr<<"\n"<<ans<<"\n";
					for(int i=p-1;i>=p-c;i--)
					{
						probs[i]-=probs[p-c]-probs[p-c-1]+1;
					}
				}
				
				sort(probs,probs+p);
			}
			fout<<ans<<"\n";
		}
		
	}
	fin.close();
	fout.close();
	return 0;	
}
