//Franciszek Budrowski

#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;

const bool print=false;

const LD PI=3.14159265359;


main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int n,k;scanf("%d%d",&n,&k);
		vector<pair<LD,LD> > pankak, taken;//(pole boku, pole podstawy)
		LD wynik=0.;
		FOR(i,1,n){
			int r,h;scanf("%d%d",&r,&h);
			LD bok=PI*2*r * h, podst=PI*r*r;
			pankak.eb(bok,podst);
		}
		sort(ALL(pankak));
		LD baza=0.;
		LD biggestr=0.;
		FOR(i,1,k-1){
			taken.pb(pankak.back());
			baza+=pankak.back().e1;
			biggestr=max(biggestr,pankak.back().e2);
			pankak.pop_back();
		}
		for(auto it:pankak){
			LD lokal=baza+it.e1+max(it.e2,biggestr);
			if(lokal>wynik) wynik=lokal;
		}
		printf("Case #%d: %.9Lf\n",casenr,wynik);
	}
}
		
			
