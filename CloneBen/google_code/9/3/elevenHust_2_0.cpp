#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;
int N, K;
int main()
{
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> K;
		vector<int> data;
		int tmp;
		for (int i = 0; i < N ;i++) {
			cin >> tmp;
			data.push_back(tmp);
		}
		int cnt = N;
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i <= cnt-3; i++)
				if (data[i]==data[i+1]&&data[i]==data[i+2]) {
					data.erase (data.begin()+i, data.begin()+3+i);
					//cout << data[i] << cnt << endl;
					flag = true;
					cnt-=3;
					break;
				}
		}
		cout <<"Case #"<<cas<<": " <<cnt<<endl;
		/*
		for (int i = 0; i < cnt; i++)
			cout << data[i] << "\t";
		cout << endl;
		*/
	}
	return 0;
}
