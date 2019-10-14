#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

double SCALE = 1000000ll;
double arr[100];
bool vis[100];
int N;

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	//freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("A-small-attempt0.out", "wt", stdout);
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("A-small-attempt1.out", "wt", stdout);
	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	int tt; cin >> tt;
	for(int t = 0 ; t < tt ; t++){
		cerr << t << endl;
		memset(vis, 0, sizeof vis);

		cin >> N;
		for(int i = 0 ; i < N ; i++)
			cin >> arr[i];
		sort(arr, arr+N);

		pair<double, double> p = make_pair(0, SCALE);
		queue<pair<double, double> > q;
		q.push(p);

		vector<double> res;
		double step = 1;
		for(int i = 0 ; i < 20 ; i++){
			if(res.size() == N)break;

			int s = q.size();
			step *= 3;
			vector<double> v;
			for(int j = 0 ; j < s ; j++){
				pair<double, double> p = q.front(); q.pop();
				long double d1 = p.first+SCALE/step;
				long double d2 = p.first+2*SCALE/step;
				for(int k = 0 ; k < N ; k++){
					if(arr[k]*SCALE >= d1 && arr[k]*SCALE <= d2){
						v.push_back(arr[k]);
						vis[k] = true;
					}
				}
				pair<double, double> p1 = make_pair(p.first, d1);
				pair<double, double> p2 = make_pair(d2, p.second);
				q.push(p1);
				q.push(p2);
			}
			sort(v.begin(), v.end());
			for(int j = 0 ; j < v.size() ; j++)
				res.push_back(v[j]);
		}

		for(int i = 0 ; i < N ; i++)
			if(!vis[i])
				res.push_back(arr[i]);

		cout << "Case #" << t+1 << ":" << endl;
		for(int i = 0 ; i < res.size() ; i++){
			//printf("%.6lf\n", res[i]);
			cout << res[i] << endl;
		}
	}

	return 0;
}
