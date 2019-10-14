#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fs first
#define mod 1000000007
using namespace std;

long long nyak[1000005];

string baca;

int main(){
	int t; cin >> t;

	for(int i = 1; i <= t; i++){
		int n; cin >> n;
		cin >> baca;
		int nyak = (n + 1)/2;
		long long jum = 0, ret = 0;
		for(int j = 0; j < nyak; j++){
			jum = jum + baca[j] - '0';
		}
		ret = max(ret, jum);

		for(int j = nyak; j < baca.length(); j++){
			jum = jum + baca[j] - '0';
			jum = jum - baca[j - nyak] + '0';
			ret = max(ret, jum);			
		}

		printf("Case #%d: %lld\n",i, ret);
	}
}