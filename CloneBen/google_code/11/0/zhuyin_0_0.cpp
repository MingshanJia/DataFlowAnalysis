#include <iostream>
#include <cstring>
using namespace std;

int num[36][36];
bool check[36];

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int N;
		cin >> N;
		int N2 = N*N;
		for(int i=0;i<N2;i++) {
			for(int j=0;j<N2;j++) {
				cin >> num[i][j];
			}
		}
		bool yes = true;
		for(int i=0;yes && i<N2;i++) {
			memset(check,0,sizeof(check));
			for(int j=0;yes && j<N2;j++) {
				if(num[i][j] < 1 || num[i][j] > N2 || check[num[i][j]-1]) yes = false;
				else check[num[i][j]-1] = true;
			}
		}
		for(int i=0;yes && i<N2;i++) {
			memset(check,0,sizeof(check));
			for(int j=0;yes && j<N2;j++) {
				if(num[j][i] < 1 || num[j][i] > N2 || check[num[j][i]-1]) yes = false;
				else check[num[j][i]-1] = true;
			}
		}
		for(int i=0;yes && i<N;i++) {
			for(int j=0;yes && j<N;j++) {
				memset(check,0,sizeof(check));
				for(int k=0;yes && k<N;k++) {
					for(int l=0;yes && l<N;l++) {
						int number = num[i*N+k][j*N+l];
						if(number < 1 || number > N2 || check[number-1]) yes = false;
						else check[number-1] = true;
					}
				}
			}
		}
		cout << "Case #" << c << ": ";
		if(yes)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}