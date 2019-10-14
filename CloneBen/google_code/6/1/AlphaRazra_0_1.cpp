#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fs first
#define mod 1000000007
using namespace std;

long long nyak[1000005];

int t;
string baca[105];
bool aktif[105];
long long pang[55];

bool cek(string a, string b){
	if(a.length() > b.length()){
		return false;
	}
	for(int i = 0; i < a.length(); i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}

int main(){
	pang[0] = 1;
	for(int i = 1; i <= 50; i++){
		pang[i] = pang[i - 1] * 2;
	}

	int t; cin >> t;

	for(int i = 1; i <= t; i++){
		int n,m; cin >> n >> m;

		for(int j = 1; j <= m; j++){
			cin >> baca[j];
		}
		memset(aktif, false, sizeof(aktif));

		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= m; k++){
				if(k == j) continue;
				if(cek(baca[j], baca[k])){
					aktif[k] = true;
				}
			}
		}
		long long jaw = pang[n];
		for(int j = 1; j <= m; j++){
			if(!aktif[j]){
				jaw = jaw - pang[n - baca[j].length()];
			}
		}
		printf("Case #%d: %lld\n",i,jaw);

	}
}