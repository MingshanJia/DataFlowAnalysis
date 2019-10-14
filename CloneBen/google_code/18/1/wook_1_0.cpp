// GCJ 2012 Korea Semifinal

#define PROB "B"
#define CONSOLE false  

#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#pragma warning(disable:4996)
using namespace std;

#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

enum YUT {
	Do = 1,
	Gae = 2,
	Gul = 3,
	Yut = 4,
	Mo = 5
};



int U, N, A, B;
YUT yut[21];
vector<int> Apos, Bpos;

int moving(int dice, int pos) 
{
	if(pos == 5) return pos + dice + 14;
	if(pos == 10){
		if(dice ==1) return 25;
		if(dice ==2) return 26;
		if(dice ==3) return 22;
		if(dice ==4) return 27;
		if(dice ==5) return 28;
	}
	if(pos <= 14) return pos + dice;
	if(15 <= pos && pos <= 19) {
		int t = pos + dice;
		if(t == 20) return 29;
		if(t > 20) return 30;	//WON
		else return t;
	}
	if(20 <= pos && pos <= 24 && pos != 22)
	{
		int t = pos + dice;
		if(t >= 25) t -= 10;
		return t;
	}
	if(pos == 22)
	{
		if(dice == 1) return 27;
		if(dice == 2) return 28;
		if(dice == 3) return 29;
		else return 30;
	}
	if(25 <= pos && pos <= 26) {
		if(pos == 25 && dice ==1) return 26;
		int t = pos + dice;
		if(t >= 27) t --;
		if(t == 26) return 22;
		if(t >= 30) return 30;
		return t;
	}
	if(pos == 27) {
		if(dice==1) return 28;
		if(dice==2) return 29;
		return 30;
	}
	if(pos == 28) {
		if(dice == 1) return 29;
		return 30;
	}
	if(pos == 29) {
		return 30;
	}
	return 31;
}

bool same(int pos, vector<int> &real) 
{
	if(real.empty())
		return pos == 30 || pos == 0;

	int a = pos,
		b = real[0];

	if(a == b) return true;
	if(a > b) swap(a, b);
	if(a == 0 && b == 29) return true;
	return false;
}

bool go(bool teamA, int a, int b, int i)
{
	if(i >= N) {
		if(same(a, Apos) && same(b, Bpos))
			return true;
		return false;
	}

	YUT &dice = yut[i];

	int nexts = moving(dice, teamA ? a : b);
	for(int j = 0; j < 1; ++ j) {
		int a_next, b_next;

		if(teamA)
			a_next = nexts, b_next = b;
		else
			b_next = nexts, a_next = a;

		bool next_team = !teamA;

		if(dice == Yut || dice == Mo) {
			next_team = teamA;	//try again
		}

		if( teamA && a_next == b) b_next = 0, next_team = teamA;	// good bye baby good bye 
		if(!teamA && b_next == a) a_next = 0, next_team = teamA;	

		if( go(next_team, a_next, b_next, i+1) )
			return true;
	}

	return false;
}

bool solve() 
{
	return go(true, 0, 0, 0);
}

YUT readyut() {
	string t;
	cin >> t;
	if(t == "Do") return Do;
	if(t == "Gae") return Gae;
	if(t == "Gul") return Gul;
	if(t == "Yut") return Yut;
	if(t == "Mo") return Mo;
	while(1);
}

int main()
{
	for(int i=0; i<=28; ++ i) {
		printf("<%d>\n", i);
		for(int j=1; j<=5; ++j)
			printf("%d ", moving(j, i));
		printf("\n");
	}

	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tt = 1; tt <= T; ++ tt)
	{
		cin >> U >> N >> A >> B;
		for(int i =0; i < N; ++ i )
			yut[i] = readyut();

		Apos.clear();
		Bpos.clear();
		for(int i=0; i<A; ++ i) {
			int t; cin >> t; Apos.push_back(t);
		}
		for(int i=0; i<B; ++ i) {
			int t; cin >> t; Bpos.push_back(t);
		}

		fprintf(stderr, "<!> %d\n", tt);
		printf("Case #%d: %s\n", tt, solve() ? "YES":"NO");

	}

	return 0;
}
