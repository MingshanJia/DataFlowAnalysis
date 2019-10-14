#include <fstream>
#include <string>

using namespace std;

int main(void) {
	ifstream fin("alien.in");
	ofstream fout("alien.out");
	string A, B, C, D;
	int CN, cn, i, p, T;

	fin >> CN;

	for (cn = 1; cn <= CN; ++cn) {

		fin >> A >> B >> C;

		for (T = i = 0; i < (int) A.size(); ++i) {
			p = find(B.begin(), B.end(), A[i]) - B.begin();
			T = T * B.size() + p;
		}
	
		D.clear();
		while (T) {
			D.push_back(C[ T % C.size() ]);
			T /= C.size();
		}
		reverse(D.begin(), D.end());

		fout << "Case #" << cn << ": " << D << '\n';
	}

	return 0;
}
