#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

char lhs[251], rhs[251], result[251];
char op[3], eq[3];
int len_lhs, len_rhs, len_result, len_max;
string output_lhs, output_rhs, output_result;

void solve_plus(int idx, bool over, bool not_over,
	string Lhs, string Rhs, string Result,
	string Lhs_over, string Rhs_over, string Result_over) {
	
	// cout << "is over? " << over << endl;
	// cout << Lhs_over << "+" << Rhs_over << "=" << Result_over << endl;
	// cout << "is not over? " << not_over << endl;
	// cout << Lhs << "+" << Rhs << "=" << Result << endl;
	
	if (idx == len_max + 1) {
		if (!not_over) {
			printf("Process error: Cannot get an answer\n");
			return;
		}
		
		output_lhs = Lhs.substr(len_max - len_lhs);
		output_rhs = Rhs.substr(len_max - len_rhs);
		output_result = Result.substr(len_max - len_result);
		return;
	}
	
	bool new_over = false;	
	bool new_not_over = false;
	string new_lhs_over, new_rhs_over, new_result_over;				
	string new_lhs, new_rhs, new_result;
	
	for (int i = 0; i <= 9; i++) {
		// 0 check
		if (i == 0 && len_lhs != 1 && len_lhs == idx)
			continue;
		// if number exists,
		if (idx <= len_lhs && lhs[len_lhs - idx] != '?')
			if (lhs[len_lhs - idx] - '0' != i)
				continue;
		// length exceed check
		if (idx > len_lhs && i != 0)
			continue;

		for (int j = 0; j <= 9; j++) {
			// 0 check
			if (j == 0 && len_rhs != 1 && len_rhs == idx)
				continue;
			// if number exists,
			if (idx <= len_rhs && rhs[len_rhs - idx] != '?')
				if (rhs[len_rhs - idx] - '0' != j)
					continue;
			// length exceed check
			if (idx > len_rhs && j != 0)
				continue;

			for (int k = 0; k <= 9; k++) {
				// 0 check
				if (k == 0 && len_result != 1 && len_result == idx)
					continue;
				// if number exists,	
				if (idx <= len_result && result[len_result - idx] != '?')
					if (result[len_result - idx] - '0' != k)
						continue;
				// length exceed check
				if (idx > len_result && k != 0)
					continue;
				
					
				// over
				if (over && i + j + 1 == k + 10) {
					string t1 = char('0' + i) + Lhs_over;
					string t2 = char('0' + j) + Rhs_over;
					string t3 = char('0' + k) + Result_over;
					
					if (!new_over || (t1 + t2 + t3).compare(new_lhs_over + new_rhs_over + new_result_over) < 0) {
						new_over = true;
						new_lhs_over = t1;
						new_rhs_over = t2;
						new_result_over = t3;
					}
				}
				if (not_over && i + j == k + 10) {
					string t1 = char('0' + i) + Lhs;
					string t2 = char('0' + j) + Rhs;
					string t3 = char('0' + k) + Result;

					if (!new_over || (t1 + t2 + t3).compare(new_lhs_over + new_rhs_over + new_result_over) < 0) {
						new_over = true;
						new_lhs_over = t1;
						new_rhs_over = t2;
						new_result_over = t3;
					}
				}
				
				// not over
				if (over && i + j + 1 == k) {				
					string t1 = char('0' + i) + Lhs_over;
					string t2 = char('0' + j) + Rhs_over;
					string t3 = char('0' + k) + Result_over;
					
					if (!new_not_over || (t1 + t2 + t3).compare(new_lhs + new_rhs + new_result) < 0) {
						new_not_over = true;
						new_lhs = t1;
						new_rhs = t2;
						new_result = t3;
					}
				}
				if (not_over && i + j == k) {
					string t1 = char('0' + i) + Lhs;
					string t2 = char('0' + j) + Rhs;
					string t3 = char('0' + k) + Result;

					if (!new_not_over || (t1 + t2 + t3).compare(new_lhs + new_rhs + new_result) < 0) {
						new_not_over = true;
						new_lhs = t1;
						new_rhs = t2;
						new_result = t3;
					}
				}
			}
		}
	}		
	solve_plus(idx + 1, new_over, new_not_over,
	new_lhs, new_rhs, new_result,
	new_lhs_over, new_rhs_over, new_result_over);

}

void solve_minus(int idx, bool over, bool not_over,
	string Lhs, string Rhs, string Result,
	string Lhs_over, string Rhs_over, string Result_over) {
	
	// cout << "is over? " << over << endl;
	// cout << Lhs_over << "-" << Rhs_over << "=" << Result_over << endl;
	// cout << "is not over? " << not_over << endl;
	// cout << Lhs << "+" << Rhs << "=" << Result << endl;
	
	if (idx == len_max + 1) {
		if (!not_over) {
			printf("Process error: Cannot get an answer\n");
			return;
		}
		
		output_lhs = Lhs.substr(len_max - len_lhs);
		output_rhs = Rhs.substr(len_max - len_rhs);
		output_result = Result.substr(len_max - len_result);
		return;
	}
	
	bool new_over = false;	
	bool new_not_over = false;
	string new_lhs_over, new_rhs_over, new_result_over;				
	string new_lhs, new_rhs, new_result;
	
	for (int i = 0; i <= 9; i++) {
		// 0 check
		if (i == 0 && len_lhs != 1 && len_lhs == idx)
			continue;
		// if number exists,
		if (idx <= len_lhs && lhs[len_lhs - idx] != '?')
			if (lhs[len_lhs - idx] - '0' != i)
				continue;
		// length exceed check
		if (idx > len_lhs && i != 0)
			continue;

		for (int j = 0; j <= 9; j++) {
			// 0 check
			if (j == 0 && len_rhs != 1 && len_rhs == idx)
				continue;
			// if number exists,
			if (idx <= len_rhs && rhs[len_rhs - idx] != '?')
				if (rhs[len_rhs - idx] - '0' != j)
					continue;
			// length exceed check
			if (idx > len_rhs && j != 0)
				continue;

			for (int k = 0; k <= 9; k++) {
				// 0 check
				if (k == 0 && len_result != 1 && len_result == idx)
					continue;
				// if number exists,	
				if (idx <= len_result && result[len_result - idx] != '?')
					if (result[len_result - idx] - '0' != k)
						continue;
				// length exceed check
				if (idx > len_result && k != 0)
					continue;
				
				
				// over
				if (over && i - j - 1 + 10 == k) {
					string t1 = char('0' + i) + Lhs_over;
					string t2 = char('0' + j) + Rhs_over;
					string t3 = char('0' + k) + Result_over;
					
					if (!new_over || (t1 + t2 + t3).compare(new_lhs_over + new_rhs_over + new_result_over) < 0) {
						new_over = true;
						new_lhs_over = t1;
						new_rhs_over = t2;
						new_result_over = t3;
					}
				}
				if (not_over && i - j + 10 == k) {
					string t1 = char('0' + i) + Lhs;
					string t2 = char('0' + j) + Rhs;
					string t3 = char('0' + k) + Result;

					if (!new_over || (t1 + t2 + t3).compare(new_lhs_over + new_rhs_over + new_result_over) < 0) {
						new_over = true;
						new_lhs_over = t1;
						new_rhs_over = t2;
						new_result_over = t3;
					}
				}
				
				// not over
				if (over && i - j - 1 == k) {				
					string t1 = char('0' + i) + Lhs_over;
					string t2 = char('0' + j) + Rhs_over;
					string t3 = char('0' + k) + Result_over;
					
					if (!new_not_over || (t1 + t2 + t3).compare(new_lhs + new_rhs + new_result) < 0) {
						new_not_over = true;
						new_lhs = t1;
						new_rhs = t2;
						new_result = t3;
					}
				}
				if (not_over && i - j == k) {
					string t1 = char('0' + i) + Lhs;
					string t2 = char('0' + j) + Rhs;
					string t3 = char('0' + k) + Result;

					if (!new_not_over || (t1 + t2 + t3).compare(new_lhs + new_rhs + new_result) < 0) {
						new_not_over = true;
						new_lhs = t1;
						new_rhs = t2;
						new_result = t3;
					}
				}				
			}
		}
	}		
	solve_minus(idx + 1, new_over, new_not_over,
	new_lhs, new_rhs, new_result,
	new_lhs_over, new_rhs_over, new_result_over);

}

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	
	for (int testcase = 1; testcase <= testnum; testcase++) {
		scanf("%s", lhs);
		scanf("%s", op);
		scanf("%s", rhs);
		scanf("%s", eq);
		scanf("%s", result);
		
		if (strlen(op) != 1 || (op[0] != '+' && op[0] != '-')) {
			printf("Input error: op\n");
			return -1;
		}
		if (strlen(eq) != 1 || eq[0] != '=') {
			printf("Input error: eq\n");
			return -1;
		}
		
		len_lhs = strlen(lhs);
		len_rhs = strlen(rhs);
		len_result = strlen(result);
		len_max = max(len_lhs, len_rhs);
		len_max = max(len_max, len_result);
		
		if (op[0] == '+') {
			solve_plus(1, false, true, "", "", "", "", "", "");
		} else {
			solve_minus(1, false, true, "", "", "", "", "", "");
		}
		
		printf("Case #%d: %s %s %s %s %s\n", testcase
			, output_lhs.c_str(), op, output_rhs.c_str(), eq,
			output_result.c_str());
	}
	return 0;	
}
