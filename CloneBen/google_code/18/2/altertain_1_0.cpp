#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for( int i=(a); i<(b); ++i)
#define FORD(i,a,b) for( int i=(a); i>(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

int togo[35][5];
map<string,int> mp;
int dt[64];

void init()
{
	REP(i,29) REP(j,5)
	togo[i][j] = i+j+1;

	togo[5] = {20,21,22,23,24};
	togo[10] = {25,26,22,27,28};
	togo[15] = {16,17,18,19,29};
	togo[16] = {17,18,19,29,30};
	togo[17] = {18,19,29,30,30};
	togo[18] = {19,29,30,30,30};
	togo[19] = {29,30,30,30,30};
	togo[20] = {21,22,23,24,15};
	togo[21] = {22,23,24,15,16};
	togo[22] = {27,28,29,30,30};
	togo[23] = {24,15,16,17,18};
	togo[24] = {15,16,17,18,19};
	togo[25] = {26,22,27,28,29};
	togo[26] = {22,27,28,29,30};
	togo[27] = {28,29,30,30,30};
	togo[28] = {29,30,30,30,30};
	togo[29] = {30,30,30,30,30};
	togo[30] = {31,31,31,31,31};
	togo[31] = {31,31,31,31,31};

	mp["Do"]=0;
	mp["Gae"]=1;
	mp["Gul"]=2;
	mp["Yut"]=3;
	mp["Mo"]=4;
}

void getval(int* now, char q[100])
{
	int len=strlen(q);
	REP(i,len) if (isdigit(q[i])) {
		sscanf(q,"%d",&now[0]);
		return;
	}
}

int nowa[2],nowb[2];
int u,n,a,b;

int main()
{
	init();

/*	REP(i,32) {
		cout<<i<<" : ";
		REP(j,5)
			cout<<togo[i][j]<<" ";
		cout<<endl;
	}
*/
	int tn;
	cin>>tn;
	
	while (tn--) {
		cin>>u>>n>>a>>b;
		REP(i,n) {
			string str;
			cin>>str;
			assert(mp.find(str) != mp.end());
			dt[i]=mp[str];
		}
		nowa[0]=nowa[1]=-1;
		nowb[0]=nowb[1]=-1;

//		char qqq[100];
//		gets(qqq);
		REP(i,a) 
		{
			cin>>nowa[i];
//			gets(qqq);
//			cout<<"qqq : "<<qqq<<endl;
//			getval(nowa,qqq);
		}
		REP(i,b)
		{
			cin>>nowb[i];
//			gets(qqq);
//			cout<<"qqq : "<<qqq<<endl;
//			getval(nowb,qqq);
		}

		int c=0;
		int ta,tb;
		ta=tb=0;
		bool end=false;
		bool good=true;
		REP(i,n) {
			if (end) good=false; // 场车绰单 肚 带廉

			int v=dt[i];
			if (c==0)	ta=togo[ta][v];
			else		tb=togo[tb][v];

			bool cap=false;
			if (ta==tb) {
				if (c==0)	tb=0;
				else		ta=0;
				cap=true;
			}

			if (ta==30 || tb==30) 
				end=true;
			
			if (!cap && dt[i]<3) c=1-c;

			
		}

//		cout<<nowa[0]<<", "<<nowb[0]<<" : "<<ta<<", "<<tb<<endl;

		static int tt=0;
		printf("Case #%d: ",++tt);

		if (ta==0) ta=-1;
		if (tb==0) tb=-1;
		if (ta==29) ta=0;
		if (tb==29) tb=0;
		if (ta==30) ta=-1;
		if (tb==30) tb=-1;
		if (ta==31 || tb==31) good=false;
		if (nowa[0] != ta) good=false;
		if (nowb[0] != tb) good=false;

		if (good)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
