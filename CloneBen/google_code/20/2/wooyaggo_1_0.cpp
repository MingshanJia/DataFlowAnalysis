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

#include <stdio.h>
#include <algorithm>
#include <limits.h>

#include <vector>
#include <utility>

using namespace std;

int max3(int a, int b, int c) {
	return max(max(a,b), c);
}

// a + b = c;
bool is_possible_plus(const string& a, const string& b, const string& c) {
	int max_len = max3(a.length(), b.length(), c.length());
	
	enum eCarryState { kHasCarry, kNoCarry, kBoth } curr_carry_state = kNoCarry;

	for(int i=0; i<max_len; i++) {
		char ca = i<a.length() ? a[i] : '0';
		char cb = i<b.length() ? b[i] : '0';
		char cc = i<c.length() ? c[i] : '0';
		
		int unknown_count = 0;
		if(ca == '?') unknown_count++;
		if(cb == '?') unknown_count++;
		if(cc == '?') unknown_count++;

		if(ca == '?' && cb == '?' && cc == '?') {
			curr_carry_state = kBoth;
		}
		else if(ca == '?' && cb == '?' && cc != '?') {
			if(cc=='0' && curr_carry_state == kHasCarry) {
				curr_carry_state = kHasCarry;
			}
			else if(cc=='9' && curr_carry_state == kNoCarry) {
				curr_carry_state = kNoCarry;
			}
			else {
				curr_carry_state = kBoth;
			}
		}

		else if(ca == '?' && cb != '?' && cc == '?') {
			if(cb=='9' && curr_carry_state == kHasCarry) {
				curr_carry_state = kHasCarry;
			}
			else if(cb=='0' && curr_carry_state == kNoCarry) {
				curr_carry_state = kNoCarry;
			}
			else {
				curr_carry_state = kBoth;
			}
		}
		else if(ca == '?' && cb != '?' && cc != '?') {
			if(curr_carry_state == kHasCarry) {
				cb++;
			}
			
			if(curr_carry_state == kBoth && cb == cc) {
				curr_carry_state = kBoth;
			}
			else {
				curr_carry_state = (cb > cc) ? kHasCarry : kNoCarry;
			}
		}
		else if(ca != '?' && cb == '?' && cc == '?') {
			if(ca=='9' && curr_carry_state == kHasCarry) {
				curr_carry_state = kHasCarry;
			}
			else if(ca=='0' && curr_carry_state == kNoCarry) {
				curr_carry_state = kNoCarry;
			}
			else {
				curr_carry_state = kBoth;
			}
		}
		else if(ca != '?' && cb == '?' && cc != '?') {
			if(curr_carry_state == kHasCarry) {
				ca++;
			}
			
			if(curr_carry_state == kBoth && ca == cc) {
				curr_carry_state = kBoth;
			}
			else {
				curr_carry_state = (ca > cc) ? kHasCarry : kNoCarry;
			}
		}
		else if(ca != '?' && cb != '?' && cc == '?') {
			int n = (ca-'0')+(cb-'0');

			if(curr_carry_state == kHasCarry) {
				n++;
			}

			if(curr_carry_state == kBoth & n == 9) curr_carry_state = kBoth;
			else curr_carry_state = (n/10) ? kHasCarry : kNoCarry;
		}
		else if(ca != '?' && cb != '?' && cc != '?') {
			int n = (ca-'0')+(cb-'0') + (curr_carry_state == kHasCarry);
			
			if(cc-'0' == n%10) {
				;
			}
			else if( curr_carry_state == kBoth && (n+1)%10 == cc-'0') {
				n++;
			}
			else { 
				return false;
			}

			curr_carry_state = (n/10) ? kHasCarry : kNoCarry;
		}
	}

	return curr_carry_state != kHasCarry;
}

// a - b = c
bool is_possible_minus(const string &a, const string& b, const string& c) {
	return is_possible_plus(b, c, a);
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	freopen("B-small-attempt8.in", "r", stdin);
	freopen("B-small-attempt8.out", "w", stdout);
	
	bool (*is_possible)(const string &a, const string& b, const string& c);

	int T;  scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		char arr_a[333], arr_b[333], arr_c[333];
		char op[3], eq[3];
		scanf("%s %s %s %s %s", arr_a, op, arr_b, eq, arr_c);

		string s[3];
		s[0] = arr_a;
		s[1] = arr_b;
		s[2] = arr_c;

		for(int i=0;i<3;i++) reverse(s[i].begin(), s[i].end());

		if(op[0] == '+') is_possible = is_possible_plus;
		if(op[0] == '-') is_possible = is_possible_minus;

		bool can = false;
		vector<string> res;
		for(char ch1='0' + int(s[0].length() != 1); ch1<='9' ; ch1++) for(char ch2='0' + int(s[1].length() != 1); ch2<='9' ; ch2++) for(char ch3='0'+ int(s[2].length() != 1); ch3<='9'; ch3++) { 
			s[0] = arr_a;
			s[1] = arr_b;
			s[2] = arr_c;

			if(s[0][0] == '?') s[0][0] = ch1; 
			if(s[1][0] == '?') s[1][0] = ch2; 
			if(s[2][0] == '?') s[2][0] = ch3; 
			
			for(int i=0;i<3;i++) reverse(s[i].begin(), s[i].end());

			for(int k=0;k<3;k++) {
				for(int i=int(s[k].length())-1; i>=0; i--) if(s[k][i]=='?') {
					char start_ch = (s[k].length() > 1 && i == int(s[k].length()-1)) ? '1' : '0';

					for(char ch = start_ch; ch<='9'; ch++) {
						s[k][i] = ch;
						if(is_possible(s[0], s[1], s[2])) break;
					}
				}
			}
			can = !count(s[0].begin(), s[0].end(), '?') && !count(s[1].begin(), s[1].end(), '?') && !count(s[2].begin(), s[2].end(), '?') &&  is_possible(s[0], s[1], s[2]);
			//is_possible(s[0], s[1], s[2]);
			if(can) {
				char line[1111];
				for(int i=0;i<3;i++) reverse(s[i].begin(), s[i].end());
				sprintf(line, "Case #%d: %s %c %s = %s\n", tc, s[0].c_str(), op[0], s[1].c_str(), s[2].c_str());
				res.push_back(line);
			}
		}

		sort(res.begin(), res.end());
		cout << res[0];

	}

	return 0;
}