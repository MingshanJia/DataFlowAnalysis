//	GCJ Pratice - AlienNumbers.cpp

#include <string>
#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string nstr, source, target;
		cin >> nstr >> source >> target;
		int n = 0;
		for (int j = 0; j < nstr.size(); j++) {
			n *= source.size();
			n += source.find(nstr[j]);
		}
		nstr.clear();
		while (n) {
			nstr.insert(nstr.begin(), target[n % target.size()]);
			n /= target.size();
		}
		cout << "Case #" << i << ": " << nstr << endl;
	}
	return 0;
}
