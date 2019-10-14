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

bitset<10> inttobs(int x)
{
	bitset<10> ans;
	f(i,0,10)
	{
		ans.reset(i);
	}
	f(i,0,10)
	{
		if(x%2==1)
		{
			ans.set(i);
		}
		x/=2;
	}
	return ans;
}
struct kicks
{
	int a,b,c;
};

int main()
{
	fin.open("D-small-attempt0.in");
	fout.open("D-small-attempt0.out");
	int numcas;
	int n,m,t1,t2,t3;
	char t4;
	fin>>numcas;
	bitset<10> curr;
	vector<pii>ls;
	vector<pii>ts;
	vector<kicks > sames;
	vector<kicks> diffs;
	kicks toog;
	f(cas,1,numcas+1)
	{
		fout<<"Case #"<<cas<<": ";
		//cerr<<"Case #"<<cas<<": \n";
		vector<bitset<10> > anses;
		fin>>n>>m;
		ls.clear();
		ts.clear();
		sames.clear();
		diffs.clear();
		f(i,0,m)
		{
		fin>>t1;
		fin>>t4;
		fin>>t2;
		t1--;
		t2--;
		
		if(t4=='L')
		{
			ls.pb(make_pair(t1,t2));
		}
		else if(t4=='T')
		{
			ts.pb(make_pair(t1,t2));
		}
		else if(t4=='S')
		{
			fin>>t3;
			t3--;
			toog.a=t1;
			toog.b=t2;
			toog.c=t3;
			sames.pb(toog);
		}
		else if(t4=='D')
		{
			fin>>t3;
			t3--;
			toog.a=t1;
			toog.b=t2;
			toog.c=t3;
			diffs.pb(toog);
		}
		}
		//cerr<<"done\n";
		for(unsigned long j=0;j<int(pow(2.0,n));j++)
		{
			bool good=true;
			curr=bitset<10>(j);
			f(i,0,ts.size())
			{
				//cerr<<curr[ts[i].x]<<" "<<curr[ts[i].y]<<" "<<ts[i].x<<" "<<ts[i].y<<"\n";
				if(curr[ts[i].x]^curr[ts[i].y])
				{
					good=false;
				}
			}
			f(i,0,ls.size())
			{
				//cerr<<curr[ls[i].x]<<" "<<curr[ls[i].y]<<" "<<ls[i].x<<" "<<ls[i].y<<"\n";
				if(!(curr[ls[i].x]^curr[ls[i].y]))
				{
					good=false;
				}
			}

			f(i,0,sames.size())
			{
				//cerr<<curr[sames[i].a]<<" "<<curr[sames[i].b]<<" " <<curr[sames[i].c] <<" "<<sames[i].a<<" "<<sames[i].b<<" "<<sames[i].c<<"\n";
				if(!(curr[sames[i].a]	^!(curr[sames[i].b]^curr[sames[i].c])))
				{
					good=false;
				}
			}
			f(i,0,diffs.size())
			{
				//cerr<<curr[diffs[i].a]<<" "<<curr[diffs[i].b]<<" " <<curr[diffs[i].c] <<" "<<diffs[i].a<<" "<<diffs[i].b<<" "<<diffs[i].c<<"\n";
				if((curr[diffs[i].a]^!(curr[diffs[i].b]^curr[diffs[i].c])))
				{
					good=false;
				}
			}

			if(good)
			{
			//	cerr<<j<<"\n";
				anses.pb(curr);
			}			
									
		}
		string best="";
		for(int k=0;k<n;k++)
		{
			bool gees=true;
			bool start=anses[0][k];
			f(j,0,anses.size())
			{
				if(start!=anses[j][k])
				{
					gees=false;
				}
			}
			if(gees)
			{
				if(start)
				{
					best.pb('L');
				}
				else best.pb('T');
			}
			else best.pb('-');
			best.pb(' ');
		}
		fout<<best.substr(0,best.length()-1)<<"\n";
			
	}
	fin.close();
	fout.close();
	return 0;	
}
