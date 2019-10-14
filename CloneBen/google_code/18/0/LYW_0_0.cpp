#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long num_type[6];
int P[6][6];

int flag[6], idx[6];
long long  MAX = 100000 * (long long)100000 * (long long)100000 * (long long)1000 + 1;
int enemy[6][3];

long long get_truth() {
	long long ret = -MAX;
	for (int i03 = 0; i03 <= num_type[0]; i03++) {
		if (num_type[3] < i03)
			break;
		for (int i04 = 0; i04 <= num_type[0]; i04++) {
			if (num_type[4] < i04)
				break;
			int i05 = num_type[0] - i03 - i04;
			if (0 <= i05 && i05 <= num_type[5]) {
				for (int i13 = 0; i13 <= num_type[1]; i13++) {
					if (num_type[3] < i03 + i13)
						break;
					for (int i14 = 0; i14 <= num_type[1]; i14++) {
						if (num_type[4] < i04 + i14)
							break;
						int i15 = num_type[1] - i13 - i14;
						int i23 = num_type[3] - i03 - i13;
						int i24 = num_type[4] - i04 - i14;
						int i25 = num_type[5] - i05 - i15;
						
						if (0 <= i15 && 0 <= i23 && 0 <= i24 && 0 <= i25) {
							if (i23 + i24 + i25 == num_type[2]) {
								ret = max(ret, (long long)i03 * P[0][3] + i04 * P[0][4] + i05 * P[0][5]
											+ i13 * P[1][3] + i14 * P[1][4] + i15 * P[1][5]
											+ i23 * P[2][3] + i24 * P[2][4] + i25 * P[2][5]);
							}						
						}
					}
				}			
			}
		}	
	}
	return ret;
}

long long dfs(int d, int x) {
	if (d) {
		idx[d - 1] = x;
		flag[x] = 1;
	}
	
	if (d == 6) {
		long long ret = 0;		
		long long temp_num[6];
		for (int i = 0; i < 6; i++) {
			temp_num[i] = num_type[i];
		}
		for (int i = 0; i < 6; i++) {
			for (int k = 0; k < 3; k++) {
				int max_value = -100001, max_idx;
				int me = idx[i];

				for (int j = 0; j < 3; j++) {
					int op = enemy[me][j];
					if (temp_num[op] && P[me][op] > max_value) {
						max_value = P[me][op];
						max_idx = op;
					}
				}
				long long n = min(temp_num[me], temp_num[max_idx]);
				ret += n * max_value;
				temp_num[me] -= n;
				temp_num[max_idx] -= n;
			}
		}	
		flag[x] = 0;
		return ret;
	}
	
	long long ret = -MAX;
	for (int i = 0; i < 6; i++) {
		if (flag[i] == 0) {
			ret = max(ret, dfs(d + 1, i));
		}
	}
	flag[x] = 0;
	return ret;
}

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	
	for (int i = 0; i < 3; i++) {
		enemy[i][0] = 3; 
		enemy[i][1] = 4;
		enemy[i][2] = 5;
	}
	for (int i = 3; i < 6; i++) {
		enemy[i][0] = 0; 
		enemy[i][1] = 1;
		enemy[i][2] = 2;
	}
		
	
	for (int testcase = 1; testcase <= testnum; testcase++) {
		long long ans = 0;
		scanf("%d", &N);
		for (int i = 0; i  < 6; i++) {
			scanf("%lld", &num_type[i]);
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &P[i][j + 3]);
				P[j + 3][i] = P[i][j + 3];
			}
		}
		
		for (int i = 0; i < 6; i++) {
			flag[i] = 0;
		}
		
		ans = dfs(0, 0);
		
		printf("Case #%d: %lld\n", testcase, get_truth());
		
		/* Comparision */
		if ( get_truth() != ans) {
//			printf("Error\n");
//			printf("Comparision: %lld\n", get_truth());
		}
	}
	return 0;
}