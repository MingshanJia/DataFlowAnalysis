#include <iostream>
using namespace std;
void proc(int iTest);

int main(){
	int test;
	cin >> test;
	for (int iTest = 1; iTest <= test; ++iTest){
		proc(iTest);
	}
	return 0;
}

int *mem;

int get(int v, int *avail) {
	if (mem[v] != 2147483647) {
		return mem[v];
	}
	int n_key = 0;
	int v_copy = v;
	//direct input
	while (v != 0) {
		int key = v % 10;
		if (!avail[key]) {
			n_key = 2147483646;
			break;
		} else {
			n_key++;
		}
		v /= 10;
	}

	v = v_copy;
	// cout << v << endl;
	//mult
	for (int i=2; i*i<=v; i++) {
		if (v % i == 0) {
			int l = get(i, avail);
			int r = get(v / i, avail);
			if (l < 2147483646 && r < 2147483646) {
				n_key = min(l + r + 1, n_key);
			}
		}
	}
	mem[v] = n_key;
	return n_key;
}

void proc(int iTest) {
	int avail[10];
	int X;
	for (int i=0; i<10; i++) {
		cin >> avail[i];
	}
	cin >> X;
	mem = new int[X+1];
	for (int i=0; i<X+1; i++) {
		mem[i] = 2147483647;
	}
	// cout << X << endl;;
	// for (int i=0; i<10; i++) {
	// 	cout << avail[i] <<  ' ' ;
	// }
	// cout << endl;
	int val = get(X, avail) + 1;
	if (val == 2147483647) {
		cout << "Case #" << iTest << ": " << "Impossible" << endl;	
	} else {
		cout << "Case #" << iTest << ": " << val << endl;	
	}
	delete[] mem;
}