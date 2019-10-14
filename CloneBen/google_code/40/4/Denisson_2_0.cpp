
#include <bits/stdc++.h>
	
#define pub push_back
#define ll long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define x first
#define y second
	
const int INF = (int)1e9 + 7;
const ll LINF = (ll)4e18 + 7;
	
const double pi = acos(-1.0);

using namespace std;
   
int n, k, tt;
double p;
double a[57];

bool can(double s){
	double need = 0;
	for (int i = 0; i < n; i++){
		need += max((double)0, s - a[i]);
	}
	return need <= p;
}

bool is_testing = 0;
int main(){
	if (is_testing){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> tt;
	for (int ss = 0; ss < tt; ss++){
		cin >> n >> k >> p;
		for (int i = 0; i < n; i++) cin >> a[i];
		double l = 0, r = 1;
		for (int j = 0; j < 200; j++){
			double m = (double)(l + r) / (double)2;
			if (can(m))
				l = m;
			else
				r = m;
		}
		double ans = 1;
		for (int i = 0; i < n; i++) ans = ans * (double)max(l, a[i]);
		cout << "Case #" << ss + 1 << ": ";
		cout.precision(8);
		cout << fixed << ans << "\n";
	}
}