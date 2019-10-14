#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 1000007, inf = 0x3f3f3f3f;

pair<char, char> diff(string& a, string& b) {
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] != b[i]) return mp(a[i], b[i]);
	}
	return mp(0, 0);
}

void solve() {
	int l;
	cin >> l;
	string a, b, c;
	cin >> a >> b >> c;

	int ra, rb, rc;
	ra = rb = rc = 0;

	int aux = 0;

	for(int i = 0; i < l; ++i) {
		if(a[i] != b[i] or a[i] != c[i] or b[i] != c[i]) {
			if(a[i] != b[i] and a[i] != c[i] and b[i] != c[i]) {
				cout << "YES YES YES" << endl;
				return;
			} else {
				if(a[i] == c[i]) {
					aux = 1;
					swap(c, b);
				} else if(b[i] == c[i]) {
					swap(a, b); swap(b, c);
					aux = 2;
				} else {
					aux = 0;
				}

				pair<char, char> d = diff(a, b);
				char c1 = d.fi, c2 = d.se;
				char c3 = c[i];

				if(c1 == c[i] and c2 == b[i]) {
					ra = 1;
					rb = 0;
					rc = 0;
				} 
				else if(c2 == c[i] and c1 == b[i]) {
					ra = 0;
					rb = 1;
					rc = 0;
				} else {
					ra = rb = 1;
					rc = 0;
				}

				if(aux == 1) swap(rc, rb);
				if(aux == 2) swap(rc, rb), swap(rb, ra);

				cout << (ra? "YES " :  "NO ");
				cout << (rb? "YES " :  "NO ");
				cout << (rc? "YES" :  "NO");
				cout << endl;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	
}