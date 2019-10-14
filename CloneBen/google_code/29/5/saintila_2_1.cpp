//	GCJ Practice - EggDrop.cpp (large)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAXF = 1LL << 32;

int MAXD;
vector <vector <long long> > fmx;

long long Fmx(int D, int B)
{
	if (D < MAXD) {
		if (B < fmx[D].size()) return fmx[D][B];
		return fmx[D].back();
	}
	if (B == 0) return 0;
	if (B == 1) return D;
	if (B == 2) {
		long long sum = D + 1;
		sum *= D; sum /= 2;
		return min(sum, MAXF);
	}
	return MAXF;
}

int main()
{
	fmx.push_back(vector<long long>(2, 0));
	for (int D = 1; ; D++) {
		fmx.push_back(vector<long long>(1, 0));
		for (int B = 1; B <= D; B++) {
			long long sum = min(fmx[D - 1][B - 1] + fmx[D - 1][B] + 1, MAXF);
			fmx[D].push_back(sum);
			if (sum == MAXF) break;
		}
		if (fmx[D].back() != MAXF) {
			fmx[D].push_back(fmx[D].back());
		}
		else if (fmx[D].size() == 4) break;
	}
	MAXD = fmx.size();

	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int F, D, B;
		cin >> F >> D >> B;
		long long Fmax = Fmx(D, B);
		if (Fmax == MAXF) Fmax = -1;
		int Dmin = D, Dstep = D;
		while (Dstep > 1) {
			Dstep = (Dstep + 1) / 2;
			if (Fmx(Dmin, B) >= F) Dmin = max(0, Dmin - Dstep);
			else Dmin += Dstep;
		}
		if (Fmx(Dmin, B) < F) Dmin++;
		int Bmin = B, Bstep = B;
		while (Bstep > 1) {
			Bstep = (Bstep + 1) / 2;
			if (Fmx(D, Bmin) >= F) Bmin = max(0, Bmin - Bstep);
			else Bmin += Bstep;
		}
		if (Fmx(D, Bmin) < F) Bmin++;
		cout << "Case #" << i << ": "
			 << Fmax << ' ' << Dmin << ' ' << Bmin << endl;
	}
	return 0;
}
