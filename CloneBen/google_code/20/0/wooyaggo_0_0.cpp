// C++ Header

// -- Base
#include <iostream>
#include <sstream>
// Data Structure
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

// C Header
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstddef>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int    ui;
typedef long double     ld;

ll total_month = 0;
ll days_in_month = 0;
ll days_in_week = 0;


pair<ll, ll> get_month_week_pair() {
	ll res_month = 0;
	ll res_week = 0;

	ll curr_weekday = 0;
	do {
		curr_weekday += days_in_month;
		
		res_week += (curr_weekday+days_in_week-1)/days_in_week;
		res_month++;

		curr_weekday %= days_in_week;
	} while(curr_weekday != 0);

	return make_pair(res_month, res_week);
}

ll get_week(ll month) {
	ll res_week = 0;
	ll curr_weekday = 0;
	for(ll i=0;i<month;i++) {
		curr_weekday += days_in_month;
		
		res_week += (curr_weekday+days_in_week-1)/days_in_week;

		curr_weekday %= days_in_week;
	}
	return res_week;
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int T; scanf("%d", &T);

	for(int tc=1; tc<=T; tc++) {
		scanf("%lld %lld %lld", &total_month, &days_in_month, &days_in_week);
		
		pair<ll, ll> pll = get_month_week_pair();

		ll period_month = pll.first;
		ll period_week = pll.second;

		ll res_week = (total_month/period_month)*period_week;
		total_month %= period_month;
		res_week += get_week(total_month);

		printf("Case #%d: %lld\n", tc, res_week);
	}
	return 0;
}
