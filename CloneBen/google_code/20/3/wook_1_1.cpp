// B.wook

#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

const int UNKNOWN = -1, EMPTY = -2;

bool isPlus;

vector<int> A, B, C;
int cache[251][2][2][2][2];

void decide(int &fr, int &to, int val, int st, int i)
{
	if(val == UNKNOWN) {
		fr = st ? 0 : 1;
		if(i == n-1) // 마지막 자리 일 때에는..
		{
			if(st == 0) fr = 0;	// 0도 허용함. -_-;
		}
		to = 9;
	}
	else if(val == EMPTY) {
		fr = to = 0;
	}
	else fr = to = val;
}

int f(int i, int carry, int Ast, int Bst, int Cst)
{
	if(i >= n) {
		if(carry == 0) return 1;
		else return 0;
	}

	int &ret = cache[i][carry][Ast][Bst][Cst];
	if(ret != -1) return ret;

	ret = 0;
	
	int Afr, Ato, Bfr, Bto, Cfr, Cto;
	decide(Afr, Ato, A[i], Ast, i);
	decide(Bfr, Bto, B[i], Bst, i);
	decide(Cfr, Cto, C[i], Cst, i);

	for(int Ach = Afr; Ach <= Ato; ++Ach) {
		for(int Bch = Bfr; Bch <= Bto; ++Bch) {
			for(int Cch = Cfr; Cch <= Cto; ++ Cch) {
				
				if(isPlus)
				{
					// carry applied 
					if( (Ach + Bch + 1) % 10 == Cch ) {
						// validate carry
						int realCarry = (Ach + Bch + 1) / 10;
						if(realCarry == carry)				
							ret |= f(i + 1, 1, Ast || (Ach > 0), Bst || (Bch > 0), Cst || (Cch > 0));
					}
					else if( (Ach + Bch) % 10 == Cch ) {
						int realCarry = (Ach + Bch) / 10;
						if(realCarry == carry)
							ret |= f(i + 1, 0, Ast || (Ach > 0), Bst || (Bch > 0), Cst || (Cch > 0));
					}
				}
				else {	// minus
					if( (Ach - Bch + 10) % 10 == Cch ) {
						int realCarry = (Ach - Bch < 0);
						if(realCarry == carry)
							ret |= f(i + 1, 0, Ast || (Ach > 0), Bst || (Bch > 0), Cst || (Cch > 0));
					}
					else if( (Ach - Bch - 1 + 10) % 10 == Cch ) {
						int realCarry = (Ach - Bch - 1 < 0);
						if(realCarry == carry)
							ret |= f(i + 1, 1, Ast || (Ach > 0), Bst || (Bch > 0), Cst || (Cch > 0));
					}
				}

			}
		}
	}

	return ret;
}

bool isPossible() {
	memset(cache, -1, sizeof(cache));
	return f(0, 0, 0, 0, 0);
}

void construct_answer() 
{
	int Ast = 0, Bst = 0, Cst = 0;
	for(int i = 0; i < n; ++ i) {
		if(i == n-1) Ast = 1;	// 마지막 자리는 0도 허용
		if(A[i] == UNKNOWN)  {
			int v;
			for(v = (Ast ? 0 : 1); v <= 9; ++ v) {
				A[i] = v;
				if(isPossible() == false) continue;
				else break;
			}
			if(v == 10) cout << "WTF!";
		}
		Ast = Ast || (A[i] > 0);
	}
	for(int i = 0; i < n; ++ i) {
		if(i == n-1) Bst = 1;	// 마지막 자리는 0도 허용
		if(B[i] == UNKNOWN)  {
			int v;
			for(v = (Bst ? 0 : 1); v <= 9; ++ v) {
				B[i] = v;
				if(isPossible() == false) continue;
				else break;
			}
			if(v == 10) cout << "WTF!";
		}
		Bst = Bst || (B[i] > 0);
	}
	for(int i = 0; i < n; ++ i) {
		if(i == n-1) Cst = 1;	// 마지막 자리는 0도 허용
		if(C[i] == UNKNOWN)  {
			int v;
			for(v = (Cst ? 0 : 1); v <= 9; ++ v) {
				C[i] = v;
				if(isPossible() == false) continue;
				else break;
			}
			if(v == 10) cout << "WTF!";
		}
		Cst = Cst || (C[i] > 0);
	}
}

int main()
{
	freopen("B.large.in", "r", stdin);
	freopen("B.large.out", "w", stdout);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++ t)
	{
		string A_, op, B_, eq, C_;
		cin >> A_ >> op >> B_ >> eq >> C_;

		n = std::max<int>(A_.length(), B_.length());
		n = std::max<int>(n, C_.length());

		isPlus = (op[0] == '+');

		A_ = string(n - A_.length(), ' ') + A_;
		B_ = string(n - B_.length(), ' ') + B_;
		C_ = string(n - C_.length(), ' ') + C_;
		A = B = C = vector<int>(n);
		for(int i = 0; i < n; ++ i) {
			if(A_[i] == ' ') A[i] = EMPTY; else if(A_[i] == '?') A[i] = UNKNOWN; else A[i] = A_[i] - '0';
			if(B_[i] == ' ') B[i] = EMPTY; else if(B_[i] == '?') B[i] = UNKNOWN; else B[i] = B_[i] - '0';
			if(C_[i] == ' ') C[i] = EMPTY; else if(C_[i] == '?') C[i] = UNKNOWN; else C[i] = C_[i] - '0';
		}

		memset(cache, -1, sizeof(cache));

		cerr << t << endl;

		cout << "Case #" << t << ": ";
		
		int possible = f(0, 0, 0, 0, 0);
		
		if(possible) {
			construct_answer();
			for(int i=0; i<n; ++i) if(A[i] != EMPTY) cout << A[i];
			cout << ' ' << op << ' ' ;
			for(int i=0; i<n; ++i) if(B[i] != EMPTY) cout << B[i];
			cout << ' ' << '=' << ' ' ;
			for(int i=0; i<n; ++i) if(C[i] != EMPTY) cout << C[i];

			cout << endl;
		}
		else cout << "WTF" << endl;
	}


	return 0;
}