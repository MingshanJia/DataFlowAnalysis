//	GCJ Practice - EggDrop.cpp

#include <iostream>
#include <algorithm>
using namespace std;

const long long MAXF = 1LL << 32;
long long Fmx[101][101];

int main()
{
	for (int D = 1; D <= 100; D++) {
		for (int B = 1; B <= 100; B++) {
			Fmx[D][B] = min(Fmx[D - 1][B - 1] + Fmx[D - 1][B] + 1, MAXF);
		}
	}
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int F, D, B;
		cin >> F >> D >> B;
		long long Fmax = Fmx[D][B];
		if (Fmax == MAXF) Fmax = -1;
		int Dmin = D, Dstep = D;
		while (Dstep > 1) {
			Dstep = (Dstep + 1) / 2;
			if (Fmx[Dmin][B] >= F) Dmin = max(0, Dmin - Dstep);
			else Dmin += Dstep;
		}
		if (Fmx[Dmin][B] < F) Dmin++;
		int Bmin = B, Bstep = B;
		while (Bstep > 1) {
			Bstep = (Bstep + 1) / 2;
			if (Fmx[D][Bmin] >= F) Bmin = max(0, Bmin - Bstep);
			else Bmin += Bstep;
		}
		if (Fmx[D][Bmin] < F) Bmin++;
		cout << "Case #" << i << ": " << Fmax << ' ' << Dmin << ' ' << Bmin << endl;
	}
	return 0;
}
