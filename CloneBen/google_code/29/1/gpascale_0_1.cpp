/*
TASK: holstein
LANG: C++
ID: greg.pa1
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <queue>
#include <fstream>
#include <assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RFOR(i,a,b) for(int i = (int)(a); i > (int)(b); i--)
#define FSI(a) FOR(i, 0, (a).size())
#define FSJ(a) FOR(j, 0, (a).size())
#define FSK(a) FOR(k, 0, (a).size())
#define VI vector<int>
#define VVI vector<VI>
#define VS vector<string>
#define VVS vector<VS>
#define LL long long
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define NPERM(a) (next_permutation(ALL(a)))
#define PB push_back
#define STREAM(a, b) stringstream ss; ss << (a); string b; while(ss >> (b))
template<class T> string i2s(T s){ostringstream oss; oss << s; return oss.str();}
int s2i(string s){ return atoi(s.c_str()); }
int numbits(int n){ int ret = 0; FOR(i,0,32) if(n & (1 << i)) ret++; return ret; }

int N;
map<char, int> srcM;
map<int, char> targetM;
int nTarget, nSrc;

long long getNum(string s){
	LL ret = 0;
	FOR(i,0,s.length()){
		ret *= (LL) nSrc;
		ret += srcM[s[i]];
	}
	return ret;
}

string solve(LL n){
	string ret;
	while(n > 0){
		ret = targetM[n % nTarget] + ret;
		n /= nTarget;
	}
	return ret;
}

int tcase = 0;

int main(){		
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin >> N;
	FOR(i,0,N){
		string a, b, c;
		fin >> a >> b >> c;
		FOR(i,0,b.length()){
			srcM[b[i]] = i;
		}
		FOR(i,0,c.length()){
			targetM[i] = c[i];
		}
		nTarget = c.length();
		nSrc = b.length();
		fout << "Case #" << ++tcase << ": " << solve(getNum(a)) << endl;
	}	
	return 0;
}

