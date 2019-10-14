#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <queue>
#include <math.h>
#include <bitset>
#include <climits>
#include <sstream>
#include <unordered_map>
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int,int> pii;
const double pi = atan (1.0) * 4;
void Main ();
int main (){
//	freopen ("F:\\C++\\Google\\Round_Test\\C-small-1-attempt0.in","r",stdin);
//	freopen ("F:\\C++\\Google\\Round_Test\\C-small-1-attempt0.out","w",stdout);
	Main ();	return 0;
}

int N;
string str;
string END (set<string>& s){
	auto it = s.end (); it--;
	return *it;
}

void Main (){
	int T; cin >> T;
	for (int cas=1;cas<=T;cas++){
		scanf ("%d\n",&N);
		set <string> s;
		int ans = 0;
		for (int i=0;i<N;i++){
			getline (cin, str);
			if (!s.empty() && END (s) > str)	ans++;
			s.insert (str);
		}
		printf ("Case #%d: %d\n",cas, ans);
	}

}