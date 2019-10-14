#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int L[] = {2, 3, 1, 0};
const int R[] = {3, 2, 0, 1};

typedef pair <int, int> PII;
#define MP make_pair

map <PII, int> M;

int LX, LY, LD;
int mx, Mx, my, My;

void walk(string &A, int x, int y, int d) {
	string :: iterator p;

	for (p = A.begin() + 1; p != A.end(); ++p) {
		mx = min(mx, x); Mx = max(Mx, x);
		my = min(my, y); My = max(My, y);

		switch(*p) {
			case 'W':
				M[ MP(x, y) ] |= 1 << d;
				x += dx[d]; y += dy[d];
			break;
			case 'L': d = L[d]; break;
			case 'R': d = R[d]; break;
		}
	}
	LX = x - dx[d];
	LY = y - dy[d];
	LD = R[R[d]];
}

int main(void) {
	ifstream fin("tleft.in");
	ofstream fout("tleft.out");
	int CN, cn, i, j;
	string A, B;

	fin >> CN;
	for (cn = 1; cn <= CN; ++cn) {
		fin >> A >> B;

		mx = Mx = my = My = 0; M.clear();
		walk(A, 0, 0, 1);
		walk(B, LX, LY, LD);

		fout << "Case #" << dec << cn << ":\n";
		for (i = mx; i <= Mx; ++i) {
			for (j = my; j <= My; ++j) {
				assert(M[ MP(i, j) ] != 0);
				fout << hex << M[ MP(i, j) ];
			}
			fout << '\n';
		}
	}

	return 0;
}
