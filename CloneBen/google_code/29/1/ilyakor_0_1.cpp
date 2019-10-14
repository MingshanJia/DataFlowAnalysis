#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cctype>

#define int64 long long
#define ii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

template<class T> T abs(T x){return x>0 ? x:(-x);}
template<class T> T sqr(T x){return x*x;}

int num1[300],num2[300];
int c1,c2;

int main()
{
	int n;
	cin >> n;
	for(int ic=0;ic<n;ic++){
		memset(num1,-1,sizeof(num1));
		string s,s1,s2;
		cin >> s >> s1 >> s2;
		for(int i=0;i<sz(s1);i++)
			num1[s1[i]]=i;
		for(int i=0;i<sz(s2);i++)
			num2[s2[i]]=i;
		c1=sz(s1);
		c2=sz(s2);
		int64 x=0;
		for(int i=0;i<sz(s);i++){
			if(num1[s[i]]==-1) while(1);
			x=(x*(int64)c1)+(int64)(num1[s[i]]);
		}
		string ss;
		if(!x) ss+=s2[0];
		while(x){
			ss=s2[x%c2]+ss;
			x/=c2;
		}
		cout << "Case #" << ic+1 << ": " << ss << "\n";
	}
	return 0;
}
