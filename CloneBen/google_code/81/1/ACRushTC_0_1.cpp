#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long int64;

string _main()
{
	int64 n;
	int pD,pG;
	cin>>n>>pD>>pG;
	int D=1;
	for (;pD*D%100!=0;D++);
	if (D>n) return "Broken";
	int win=D*pD/100;
	int lose=D-win;
	if (win>0 && pG==0) return "Broken";
	if (lose>0 && pG==100) return "Broken";
	return "Possible";
}

int main()
{
//	freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	cin>>testcase;
	for (int case_id=1;case_id<=testcase;case_id++)
		cout<<"Case #"<<case_id<<": "<<_main()<<endl;
	return 0;
}
