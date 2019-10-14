#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <functional>

#define INPUTFILE "test.in"
#define OUTPUTFILE "result.out"

using namespace std;

#define INF 0x4fffffffffffffff

string number[] = { "1111110", "0110000", "1101101", "1111001", "0110011", "1011011"
, "1011111", "1110000", "1111111", "1111011" };

int base[] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b,0x5f, 0x70, 0x7f, 0x7b };

int main()
{
	/*freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);*/

	fstream infile(INPUTFILE, ios::in);
	fstream outfile(OUTPUTFILE, ios::out);
		
	int testN, testCount;
	testCount = 1;
	infile >> testN;
	infile.get();
	int N;
	string myStr[110];
	int myNum[110];
		
	while (testCount <= testN){
		infile >> N;
		infile.get();
		memset(myNum, 0, sizeof(myNum));
		for (int i = 1; i <= N; ++i){
	//		infile.getline(myStr[i].str(), 7, ' ');
			char temp;
			for (int j = 6; j >=0 ; --j){
				temp = infile.get();
				myNum[i] += (temp - '0') << j;
			}
			infile.get();
		}

		bool bError = false;
		bool bFind = false;
		int next;
		int ii;
		for (int begin = 0; begin <= 9; ++begin){
			for (int bad = 0; bad < 128; ++bad){
				for (ii = 1; ii <= N; ii++){
					if (myNum[ii] != (base[(begin-ii+1+10000)%10] & (~bad)) ){
						break;
					}
				}
				if (ii>N){
					if (bFind){
						bError = true;
						break;
					}
					bFind = true;
					next = base[(begin - N+10000) % 10] & (~bad);
				}
			}
			if (bError)
				break;
		}

		if (bError || !bFind)
			outfile << "Case #" << testCount++ << ": ERROR!\n";
		else{
			outfile << "Case #" << testCount++ << ": ";
			for (int i = 6; i >= 0; i--){
				outfile << ((next >> i) & 1);
			}
			outfile << endl;
		}

	}
	
	infile.close();
	outfile.close();
	return 0;
}


