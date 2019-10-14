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

using namespace std;
typedef long long LL;

int dx[8]={-1,0,1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

int dataMul[5010], dataAdd[5010];

void internalUpdate(int at, int mul, int add) {
    while (at < 5010) {
        dataMul[at] += mul;
        dataAdd[at] += add;
        at |= (at + 1); // can be at+=(at&-at);
    }
}

void update(int left, int right, int by) {
    internalUpdate(left, by, -by * (left - 1));
    internalUpdate(right, -by, by * right);
}


int query(int at) {
    int mul = 0;
    int add = 0;
    int start = at;
    while (at >= 0) {
        mul += dataMul[at];
        add += dataAdd[at];
        at = (at & (at + 1)) - 1; // can be at-=(at&-at);
    }
    return mul * start + add;
}

int main()
{
	freopen("gbus_count.in","r",stdin);
	freopen("gbus_count.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		memset(dataMul,0,sizeof(dataMul));
		memset(dataAdd,0,sizeof(dataAdd));
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			int x, y;
			cin>>x>>y;
			update(x,y,1);
		}
		cout<<"Case #"<<nt++<<": ";
		int q;
		cin>>q;
		while (q--)
		{
			int x;
			cin>>x;
			cout<<query(x)-query(x-1)<<" ";
		}
		cout<<endl;
	}
}
