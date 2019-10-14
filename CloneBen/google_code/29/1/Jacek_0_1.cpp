#include <iostream>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define SIZE(c) (int((c).size()))
#define ALL(c) (c).begin(),(c).end()

int main() {
	int cc;
	cin >> cc;
	REP(c,cc) {
		string num, source, target;
		cin	>> num >> source >> target;
		int x = 0, n = SIZE(num), b1 = SIZE(source), b2 = SIZE(target);
		REP(i,n)
			x = b1*x + source.find(num[i]);
		string res;
		while (x) {
			res.push_back(target[x%b2]);
			x /= b2;
		}
		reverse(ALL(res));
		cout << "Case #" << c+1 << ": " << res << endl;
	}
}
