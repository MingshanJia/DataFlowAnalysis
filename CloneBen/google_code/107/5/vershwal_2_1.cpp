#include <bits/stdc++.h>
using namespace std;
int len;
bool isp(string a, string b, string c) {
	int f1, f2, s1, s2;
	for(int i = 0; i<len; i++) {
		if(a[i] != b[i]) {
			f1 = a[i] - 65;
			s1 = b[i] - 65;
			break;
		}
	}
	
	for(int i = 0; i<len; i++) {
		if(c[i] != b[i]) {
			f2 = c[i] - 65;
			s2 = b[i] - 65;
			break;
		}
	}
	if(f1==f2 && s1==s2) {
		return false;
	}
	return true;

}

int main() {
	int t;
	cin>>t;
	long long cnt[10005];
	int t1 = t;
	while(t--) {
		cin>>len;
		string a, b, c;
		cin>>a>>b>>c;
		printf("Case #%d: ", t1-t);
		if(isp(b, a, c)) {
			cout<<"YES ";
		} else {
			cout<<"NO ";
		}

		if(isp(a, b, c)) {
			cout<<"YES ";
		} else {
			cout<<"NO ";
		}
		
		if(isp(a, c, b)) {
			cout<<"YES ";
		} else {
			cout<<"NO ";
		}
		
		cout<<endl;
	}
	return 0;
}