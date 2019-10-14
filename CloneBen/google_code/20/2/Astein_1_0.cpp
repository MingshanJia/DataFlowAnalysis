#include <cstdio>
#include <iostream>

using namespace std;

struct expr {
	bool has_sol;
	string A, B, C;

	expr() {
		A = B = C = "";
		has_sol = false;
	}

	expr(string a, string b, string c) {
		A = a, B = b, C = c;
		has_sol = true;
	}
};

string a, b, c;
int na[300], nb[300], nc[300];
string reta, retb, retc;
expr stable[300][2];
int check[300][2];
bool isplus;

expr find_sol(int pos, int carry) {
	if (check[pos][carry] == 1) return stable[pos][carry];
	expr ret, tmp;
	if (pos == 0) {
		check[pos][carry] = 1;
  	for (int ca = 0; ca <= 9; ++ca) {
  		if (na[pos] != -1 && na[pos] != ca) continue;
  		for (int cb = 0; cb <= 9; ++cb) {
    		if (nb[pos] != -1 && nb[pos] != cb) continue;
  			for (int cc = 0; cc <= 9; ++cc) {
  	  		if (nc[pos] != -1 && nc[pos] != cc) continue;
  	  		if (isplus) {
  	  			if (ca + cb == cc + 10 * carry) {
  	  				ret.A = string(1, '0' + ca);
  	  				ret.B = string(1, '0' + cb);
  	  				ret.C = string(1, '0' + cc);
  	  				ret.has_sol = true;
   	  				return stable[pos][carry] = ret;
						}
					} else {
  	  			if ((ca + 10 * carry - cb) == cc) {
  	  				ret.A = string(1, '0' + ca);
  	  				ret.B = string(1, '0' + cb);
  	  				ret.C = string(1, '0' + cc);
  	  				ret.has_sol = true;
 	  			  	return stable[pos][carry] = ret;
						}
					}
				}
			}
		}
		ret.has_sol = false;
		stable[pos][carry] = ret;
		return ret;
	}
	for (int ca = 0; ca <= 9; ++ca) {
		if (na[pos] != -1 && na[pos] != ca) continue;
		for (int cb = 0; cb <= 9; ++cb) {
  		if (nb[pos] != -1 && nb[pos] != cb) continue;
			for (int cc = 0; cc <= 9; ++cc) {
	  		if (nc[pos] != -1 && nc[pos] != cc) continue;
	  		tmp = expr();
	  		if (isplus) {
	  			if ((ca + cb) == cc + 10 * carry) {
	  				tmp = find_sol(pos - 1, 0);
	  				// carry = 0
					} else if ((ca + cb + 1) == cc + 10 * carry) {
	  				tmp = find_sol(pos - 1, 1);
	  				// carry = 1
					}
				} else {
	  			if ((10 * carry + ca - cb) == cc) {
	  				tmp = find_sol(pos - 1, 0);
	  				// carry = 0
					} else if ((10 * carry + ca - cb) == cc + 1) {
	  				tmp = find_sol(pos - 1, 1);
	  				// carry = 1
					}
				}
				if (tmp.has_sol) {
					tmp.A = string(1, ca + '0') + tmp.A;
					tmp.B = string(1, cb + '0') + tmp.B;
					tmp.C = string(1, cc + '0') + tmp.C;
					if (ret.has_sol) {
						if (tmp.A + tmp.B + tmp.C < ret.A + ret.B + ret.C) {
							ret = tmp;
						}
					} else ret = tmp;
				}
			}
		}
	}
	check[pos][carry] = 1;
	return stable[pos][carry] = ret;
}

string nozero(string s) {
	while (s[0] == '0' && s.size() > 1) s = s.substr(1);
	return s;
}

string go(string a, string b, string c, bool _isplus) {
	isplus = _isplus;
	int maxlen = -1;
	if (isplus) maxlen = c.size(); else maxlen = a.size();
	maxlen++;
	while (a.size() != maxlen) a = "0" + a;
	while (b.size() != maxlen) b = "0" + b;
	while (c.size() != maxlen) c = "0" + c;
	for (int i = 0; i < maxlen; ++i) {
		stable[i][0] = stable[i][1] = expr();
		check[i][0] = check[i][1] = 0;
		na[i] = a[maxlen - 1 - i] - '0';
		if (na[i] == 15) na[i] = -1;
		nb[i] = b[maxlen - 1 - i] - '0';
		if (nb[i] == 15) nb[i] = -1;
		nc[i] = c[maxlen - 1 - i] - '0';
		if (nc[i] == 15) nc[i] = -1;
	}
	expr ret = find_sol(maxlen - 1, 0);
	if (ret.has_sol) {
		return nozero(ret.A) + " " + (isplus ? "+" : "-") + " " + nozero(ret.B) + " = " + nozero(ret.C);
	}
	return "";
}

int main() {
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn) {
		string op, eq;
		cin >> a >> op >> b >> eq >> c;
		string rret = "";

		for (int sa = 0; sa <= 9; ++sa) {
			if (a[0] != '?' && sa != a[0] - '0') continue;
			if (a.size() != 1 && sa == 0) continue;
			for (int sb = 0; sb <= 9; ++sb) {
				if (b[0] != '?' && sb != b[0] - '0') continue;
				if (b.size() != 1 && sb == 0) continue;
				for (int sc = 0; sc <= 9; ++sc) {
					if (c[0] != '?' && sc != c[0] - '0') continue;
					if (c.size() != 1 && sc == 0) continue;
					string ta = a, tb = b, tc = c;
				  ta[0] = '0' + sa;
				  tb[0] = '0' + sb;
				  tc[0] = '0' + sc;
				  string ret = go(ta, tb, tc, op == "+");
				  if (ret != "") {
				  	if (rret == "") {
				  		rret = ret; 
						} else {
							if (rret > ret) rret = ret;
						}
					}
				}
			}
		}
  	cout << "Case #" << cn << ": " << rret << endl;
	}
}
