#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int Hd,  Ad,  Hk,  Ak,  B,  D;

int calc(int d, int b, int Hd, int Ad, int Hk, int Ak, int B, int D) {
	// printf("?? %d %d\n", d, b);
	int sum = 0;
	int Hd1 = Hd;
	bool conti = false;
	for (int i = 1; i <= d; i++) {
		if (Hd <= Ak - D) {
			sum += 1;
			Hd = Hd1;
			i -= 1;
			if (conti)
				return 1e9;
			conti = true;
		}else {
			conti = false;
			sum += 1;
			Ak = max(0, Ak - D);
		}
		Hd -= Ak;
	}
	conti = false;
	for (int i = 1; i <= b; i++) {
		if (Hd <= Ak) {
			sum += 1;
			Hd = Hd1;
			i -= 1;
			if (conti)
				return 1e9;
			conti = true;
		}else {
			conti = false;
			sum += 1;
			Ad += B;
		}
		Hd -= Ak;
	}
	// printf("%d %d\n", , Hk);
	conti = false;
	while (true) {
		if (Ad >= Hk)
			return sum + 1;
		sum += 1;
		if (Hd <= Ak) {
			Hd = Hd1;
			if (conti)
				return 1e9;
			conti = true;
		}else {
			conti = false;
			Hk -= Ad;
		}
		Hd -= Ak;
	}
}

void doit() {
	scanf("%d%d%d%d%d%d", &Hd, &Ad, &Hk, &Ak, &B, &D);
	int ans = 1e9;
	// printf("?? %d\n", calc(0, 1, Hd, Ad, Hk, Ak, B, D));
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			ans = min(ans, calc(i, j, Hd, Ad, Hk, Ak, B, D));
	if (ans > 1e8)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}