#include <cstdio>
#include <iostream>

using namespace std;

int a[100005];

int main() {
	int T;
	cin >> T;
	long long n, m, k;
	for (int cn = 1; cn <= T; ++cn) {
		cin >> n >> m >> k;
		cout << "Case #" << cn << ": ";
		long long ret = 0;	
		ret = n * (m / k);
		if (m % k != 0) {
			long long T;
			int mod = m % k;
			int line = 0, pos = 0;
			a[0] = 0;
			for (T = 1; ((T * mod) % k) != 0; ++T) {
				pos += mod;
				line++;
				if (pos > k) {
					pos -= k;
					line++;
				}
				a[T] = line;
			}
			line++;
			ret += line * (n / T) + a[n % T];
		}
		cout << ret << endl;
	}
}

