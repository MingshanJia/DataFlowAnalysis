#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::find

using namespace std;


int main() {
	ifstream fin;
  	fin.open("B.in");
  	ofstream fout;
  	fout.open("B.out");

	int T;
	fin >> T;
	for (int t_id = 0; t_id < T; ++t_id) {
		int D,K,N;
	  	fin >> D >> K >> N;
		fout << "Case #" << t_id + 1 << ": ";
		std::vector<int> data(D);
		std::vector<int> data_end(D);
		for (int i = 0; i < D; ++i) {
			data[i] = i;
		}
		for (int i = 0; i < D; ++i) {
			if (data[i] % 2 == 0) {
				int new_place = (data[i] + N) % D;
				data_end[new_place] = data[i];
			} else {
				int new_place = ((data[i] - N) % D + D) % D;
				data_end[new_place] = data[i];
			}
		}
		int ind = find (data_end.begin(), data_end.end(), K-1) - data_end.begin();
		fout << data_end[(ind + 1)%D] + 1 << " " << data_end[(ind - 1 + D) % D] + 1 << endl;
	}
}