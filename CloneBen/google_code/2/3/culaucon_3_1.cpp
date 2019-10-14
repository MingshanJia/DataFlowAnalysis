#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long LL;

int n;
int f[10010];

int main() {
	freopen("eat_cake.in","r",stdin);
	freopen("eat_cake.out","w",stdout);

	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=0;i<10010;i++)
		if (f[i]>=0) {
			for (int j=1;i+j*j<10010;j++)
				if (f[i+j*j]==-1 || f[i+j*j]>f[i]+1) f[i+j*j]=f[i]+1;
		}
	
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		cin>>n;
		cout<<"Case #"<<nt++<<": "<<f[n]<<endl;
	}
}
