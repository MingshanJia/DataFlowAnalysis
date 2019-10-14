#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<int> store0;
priority_queue<int> store1;
int T,n,m,turnLeft,moreCard,score,ret,cur;
int c[82],s[82],t[82];

void import(int idx)
{
	if (idx >= m) return;
	if (t[idx] > 0)
	{
		turnLeft += (t[idx] - 1);  score += s[idx];  moreCard += c[idx];
	}
	else 
	{
		if (c[idx] == 1) store1.push(s[idx]); else if (c[idx] == 0) store0.push_back(s[idx]);
	}
}

int getMax(int num)
{
	sort(store0.rbegin(),store0.rend());
	int ans = 0;
	for (int i = 0; i < store0.size() && i < num; i++) ans += store0[i];
	return ans; 
}

int main()
{
	freopen("c.i1","r",stdin);
	freopen("c.o1","w",stdout);
	
	scanf("%d", &T);
	for (int it = 1; it <= T; it++)
	{
		store0.clear();
		while (!store1.empty()) store1.pop();
		turnLeft = 1;  ret = score = moreCard = 0;
		
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &c[i], &s[i], &t[i]);
		
		scanf("%d", &m);
		for (int i = n; i < n + m; i++) scanf("%d %d %d", &c[i], &s[i], &t[i]);
		m += n;
		for (int i = 0; i < n; i++) import(i);
		cur = n - 1;
		while (moreCard && cur < m)
		{
			moreCard--;  cur++;  import(cur);
		}
		
		while (1)
		{
			ret = max(ret,score + getMax(turnLeft));
			if (store1.empty()) break; else
			{
				int u = store1.top();  store1.pop();  score += u;
				turnLeft--;  if (!turnLeft) break;
				moreCard++;
				while (moreCard && cur < m)
				{
					moreCard--;  cur++;  import(cur);
				}
			}
		}
		ret = max(ret,score);
		
		printf("Case #%d: %d\n", it, ret);
	}
}
