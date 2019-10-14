#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int COND = 0;
#define DB(x) { if (COND) { cerr << __LINE__ << " " << #x << " " << x << endl; } }

#define ull unsigned long long

int array[31] = {
  0,
  5,
27,
143,
751,
935,
607,
903,
991,
335,
47,
943,
471,
55,
447,
463,
991,
95,
607,
263,
151,
855,
527,
743,
351,
135,
407,
903,
791,
135,
647,

};

int main(int argc, char **argv) {
  COND = argc >= 2 && argv[1][0] == 'q';

  /*
  ull x = 1, y = 0;
  
  FOR (i, 1, 30) {
    ull nx = x * 3 + y * 5;
    ull ny = x + 3 * y;

    x = nx;
    y = ny;
    DB(x<<" "<<y);
    }*/
  int T;
  cin >> T;
  FOR (i, 1, T) {
    int n; cin >> n;
    int num = array[n];

    printf("Case #%d: ", i); 
    if (num < 100) printf("0");
    if (num < 10) printf("0");
    printf("%d", num);
    printf("\n");
  }
    
  return 0;
}

/*

// Main.cs created with MonoDevelop
// User: user at 10:06 PM 7/25/2008
//
// To change standard headers go to Edit->Preferences->Coding->Standard Headers
//
using System;

namespace mono2
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			decimal x = 1;
			decimal sqrt = 5;
			for (int i = 0; i < 1000; i++) {
				sqrt = (sqrt + 5 / sqrt) / 2;
			}
			for (int i = 1; i <= 30; i++) {
				x = x * (3 + sqrt);
				Console.WriteLine("" + Math.Floor(x % 1000));
			}
		}
	}
}

*/
