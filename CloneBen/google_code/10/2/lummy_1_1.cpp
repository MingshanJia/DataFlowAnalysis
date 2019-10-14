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
	string dir;
	int board[25][25];
		
	while (testCount <= testN){
		infile >> N;
		infile.get();
		getline(infile, dir);
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j){
				infile >> board[i][j];
			}
		}
		//right
		if (dir[0] == 'r'){
			for (int i = 1; i <= N; ++i){
				int pos = N;
				int last = 0;
				for (int j = N; j >= 1; j--){
					if (last == 0){
						if (board[i][j] != 0){
							last = board[i][j];
						}
					}
					else{
						if (board[i][j] == last){
							board[i][pos--] = last<<1;
							last = 0;
						}
						else if(board[i][j]!=0){
							board[i][pos--] = last;
							last = board[i][j];
						}
					}
				}
				board[i][pos--] = last;
				for (; pos >= 1; pos--)
					board[i][pos] = 0;
			}
		}

		//left
		if (dir[0] == 'l'){
			for (int i = 1; i <= N; ++i){
				int pos = 1;
				int last = 0;
				for (int j = 1; j <= N; j++){
					if (last == 0){
						if (board[i][j] != 0){
							last = board[i][j];
						}
					}
					else{
						if (board[i][j] == last){
							board[i][pos++] = last << 1;
							last = 0;
						}
						else if (board[i][j] != 0){
							board[i][pos++] = last;
							last = board[i][j];
						}
					}
				}
				board[i][pos++] = last;
				for (; pos <= N; pos++)
					board[i][pos] = 0;
			}
		}

		//up
		if (dir[0] == 'u'){
			for (int j = 1; j <= N; ++j){
				int pos = 1;
				int last = 0;
				for (int i = 1; i <= N; i++){
					if (last == 0){
						if (board[i][j] != 0){
							last = board[i][j];
						}
					}
					else{
						if (board[i][j] == last){
							board[pos++][j] = last << 1;
							last = 0;
						}
						else if (board[i][j] != 0){
							board[pos++][j] = last;
							last = board[i][j];
						}
					}
				}
				board[pos++][j] = last;
				for (; pos <= N; pos++)
					board[pos][j] = 0;
			}
		}

		//down
		if (dir[0] == 'd'){
			for (int j = 1; j <= N; ++j){
				int pos = N;
				int last = 0;
				for (int i = N; i >= 1; i--){
					if (last == 0){
						if (board[i][j] != 0){
							last = board[i][j];
						}
					}
					else{
						if (board[i][j] == last){
							board[pos--][j] = last << 1;
							last = 0;
						}
						else if (board[i][j] != 0){
							board[pos--][j] = last;
							last = board[i][j];
						}
					}
				}
				board[pos--][j] = last;
				for (; pos >= 1; pos--)
					board[pos][j] = 0;
			}
		}

		//cout
		outfile << "Case #" << testCount++ << ":\n";
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j){
				outfile << board[i][j];
				if (j < N)
					outfile << " ";
				else
					outfile << "\n";
			}
		}

	}
	
	infile.close();
	outfile.close();
	return 0;
}


