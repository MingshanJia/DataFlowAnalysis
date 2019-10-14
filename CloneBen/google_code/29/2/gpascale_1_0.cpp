#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long ll;
typedef pair<int,int> ipair;
typedef pair<string, string> spair;
typedef struct{double x; double y; double r;} circle;
typedef pair<int, string> ispair;
typedef pair<string, int> sipair;
#define FOR(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RFOR(i,a,b) for(int i = (int)(a); i > (int)(b); i--)
#define FORSZ(i,a,b) FOR(i,0,(b).size())
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define FSI(a) FORSZ(i, 0, (a))
#define FSJ(a) FORSZ(j, 0, (a))
#define FSK(a) FORSZ(k, 0, (a))
#define shift(n) (1<<(n))
#define shiftL(n) ((ll)(1<<(n)))
#define SQR(a) ((a)*(a))
#define mp make_pair
#define pb push_back
#define rev(a) reverse(ALL(a))

ifstream fin("x.in");
ofstream fout("x.out");

#define NMAX 10005
string dir = "0123456789abcdef";
map<pair<int, int>, int> m;
map<pair<int, int>, int> d;

int main()
{
	d[make_pair(-1, 0)] = 1;
	d[make_pair(1, 0)] = 2;
	d[make_pair(0, -1)] = 4;
	d[make_pair(0, 1)] = 8;
	ifstream fin("x.in");
	ofstream fout("x.out");
	int N; fin >> N;
	FOR(tcase,1,N+1){
		m.clear();
		string walk, walkB;
		fin >> walk >> walkB;
		walk = walk + " " + walkB + "*";
		int minRow = 0, maxRow = -10005;
		int minCol = 10005, maxCol = -10005;
		int r = -1, c = 0, dr = 1, dc = 0;
		int exit;
		FOR(i,0,walk.length()){
			if(walk[i] == 'W'){
				if(m.count(make_pair(r, c)) <= 0)
					m[make_pair(r, c)] = 0;				
				m[make_pair(r, c)] |= d[make_pair(dr, dc)];
				//cout << "|=" << d[make_pair(dr, dc)] << endl;
				r += dr; c += dc;
				if(walk[i+1] != ' ' && i > 0 && walk[i-1] != ' ');
				m[make_pair(r, c)] |= d[make_pair(-dr, -dc)];
			}
			else if(walk[i] == 'L'){
				int t = dr;
				dr = -dc;
				dc = t;
			}
			else if(walk[i] == 'R'){
				int t = dc;
				dc = -dr;
				dr = t;
			}
			else if(walk[i] == ' '){
				if(dr < 0) exit = 0;
				else if(dc > 0) exit = 1;
				else if(dr > 0) exit = 2;
				else exit = 3;
				dr *= -1;
				dc *= -1;
			}
			if(r > maxRow) maxRow = r;
			if(c > maxCol) maxCol = c;
			if(c < minCol) minCol = c;
		}
		if(exit == 1) maxCol--;
		else if(exit == 2) maxRow--;
		else if(exit == 3) minCol++;

		/*FOR(i,minRow,maxRow+1){
			FOR(j,minCol,maxCol+1){
				cout << "[" << m[make_pair(i, j)] << "]";
			}
			cout << endl;
		}*/

		fout << "Case #" << tcase << ": " << endl;
		FOR(i,minRow,maxRow+1){
			FOR(j,minCol,maxCol+1){
				if(m.count(make_pair(i, j)) <= 0)
					fout << "0";
				else
					fout << dir[m[make_pair(i, j)]];
			}
			fout << endl;
		}
	}
	return 0;
}
