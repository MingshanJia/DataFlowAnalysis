//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, cs = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		cin.get();
		string s, l="";
		int ans = 0;
		while (n--){
			getline(cin, s);
			if (s > l){
				l = s;
			}
			else ans++;
		}
		cout << "Case #" << cs++ << ": " << ans << "\n";
	}
}
