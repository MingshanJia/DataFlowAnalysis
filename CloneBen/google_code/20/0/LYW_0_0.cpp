#include <cstdio>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		long long int num_month;
		int days_per_month, days_per_week;
				
		scanf("%lld %d %d", &num_month, &days_per_month, &days_per_week);
		
		int flag[100], idx[100], num_lines[100];		
		for (int i = 0; i < days_per_week; i++) {
			num_lines[i] = (days_per_month + i) / days_per_week;
			if ((days_per_month + i) % days_per_week)
				num_lines[i]++;
			idx[i] = 0;
			flag[i] = 0;
		}
		
		int cycle_length = 0, start_off = 0;
		long long int ans = 0;
		while(1) {
			if (flag[start_off])
				break;
			idx[cycle_length] = start_off;
			cycle_length++;
			flag[start_off] = 1;
			start_off = (start_off + days_per_month) % days_per_week;
		}
		for (int i = 0; i < cycle_length; i++) {
			ans += (num_month / cycle_length) * (long long int)num_lines[idx[i]];
			if (i + 1 <= num_month % cycle_length)
				ans += num_lines[idx[i]];
		}			
		
		printf("Case #%d: %lld\n", testcase, ans);
	}
	return 0;
}