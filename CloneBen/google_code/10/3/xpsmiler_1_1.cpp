#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void solves(vector<vector<int>>& board, int N, char* direction) {
	vector<int> vec;
	bool oldUsed = false;
	if(strcmp(direction, "right") == 0) {
		for (int i = 0; i < N; i++) {
			vec.clear();
			int oldVal = board[i][N-1];
			int j = N - 2;
			while(j >= 0){
				if(board[i][j] == 0) {
					j--;
				}else if(oldVal == 0) {
					oldUsed = false;
					oldVal = board[i][j];
					j--;
				}
				else if(board[i][j] == oldVal) {
					vec.push_back(oldVal*2);
					oldUsed = true;
					j--;
					if(j >= 0) {
						oldVal = board[i][j];
						oldUsed = false;
					}
					j--;
				} else {
					vec.push_back(oldVal);
					oldVal = board[i][j];
					j--;
					oldUsed = false;
				}
				if( j < 0 && !oldUsed) {
					vec.push_back(oldVal);
				}
			}
			reverse(vec.begin(), vec.end());
			for(int k = N - 1; k >=0 ; k--) { // 向you靠
				if(vec.size() > 0) {
					board[i][k] = vec.back();
					vec.pop_back();
				} else {
					board[i][k] = 0;
				}
			}
		}
	}

	else if(strcmp(direction, "left") == 0) {
		for (int i = 0; i < N; i++) {
			vec.clear();
			int oldVal = board[i][0];
			int j = 1;
			while(j < N){
				if(board[i][j] == 0) {
					j++;
				}else if(oldVal == 0) {
					oldVal = board[i][j];
					j++;
					oldUsed = false;
				}
				else if(board[i][j] == oldVal) {
					vec.push_back(oldVal*2);
					oldUsed = true;
					j++;
					if(j >= 0) {
						oldVal = board[i][j];
						oldUsed = false;
					}
					j++;
				} else {
					vec.push_back(oldVal);
					oldVal = board[i][j];
					j++;
					oldUsed = false;
				}
				if (j > N-1 && !oldUsed) {
					vec.push_back(oldVal);
				}
			}
			reverse(vec.begin(), vec.end());
			for(int k = 0; k < N ; k++) { // 向zuo靠
				if(vec.size() > 0) {
					board[i][k] = vec.back();
					vec.pop_back();
				} else {
					board[i][k] = 0;
				}
			}
		}
	}
	else if(strcmp(direction, "up") == 0) {
		for (int i = 0; i < N; i++) {
			vec.clear();
			int oldVal = board[0][i];
			int j = 1;
			while(j < N){
				if(board[j][i] == 0) {
					j++;
				}else if(oldVal == 0) {
					oldVal = board[j][i];
					j++;
					oldUsed = false;
				}
				else if(board[j][i] == oldVal) {
					vec.push_back(oldVal*2);
					oldUsed = true;
					j++;
					if(j >= 0) {
						oldVal = board[j][i];
						oldUsed = false;
					}
					j++;
				} else {
					vec.push_back(oldVal);
					oldVal = board[j][i];
					j++;
					oldUsed = false;
				}
				if (j > N-1 && !oldUsed) {
					vec.push_back(oldVal);
				}
			}
			reverse(vec.begin(), vec.end());
			for(int k = 0; k < N ; k++) { // 向shang靠
				if(vec.size() > 0) {
					board[k][i] = vec.back();
					vec.pop_back();
				} else {
					board[k][i] = 0;
				}
			}
		}
	}
	else if(strcmp(direction, "down") == 0) {
		for (int i = 0; i < N; i++) {
			vec.clear();
			int oldVal = board[N-1][i];
			int j = N - 2;
			while(j >= 0){
				if(board[j][i] == 0) {
					j--;
				}else if(oldVal == 0) {
					oldVal = board[j][i];
					j--;
					oldUsed = false;
				}
				else if(board[j][i] == oldVal) {
					vec.push_back(oldVal*2);
					oldUsed = true;
					j--;
					if(j >= 0) {
						oldVal = board[j][i];
						oldUsed = false;
					}
					j--;
				} else {
					vec.push_back(oldVal);
					oldVal = board[j][i];
					j--;
					oldUsed = false;
				}
				if( j < 0 && !oldUsed) {
					vec.push_back(oldVal);
				}
			}
			reverse(vec.begin(), vec.end());
			for(int k = N - 1; k >=0 ; k--) { // 向xia靠
				if(vec.size() > 0) {
					board[k][i] = vec.back();
					vec.pop_back();
				} else {
					board[k][i] = 0;
				}
			}
		}
	}

}
	int main() {              
		FILE *infp, *outfp;
		infp = fopen( "B-large.in","r" );
		outfp = fopen( "output.txt","w" );

		if (!infp) {
			printf( "cannnot open input file\n" );
			return 0;
		}
		if(!outfp) {
			printf( "cannnot open output file\n" );
			return 0;
		}

		int T, N, I;
		char direction[20];
		vector<vector<int>> board(25, vector<int>(25,0));
		fscanf(infp, "%d", &T);
		for (int i = 0; i < T; i++) {
			fscanf(infp, "%d %s", &N, direction);
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					fscanf(infp, "%d", &I);
					board[j][k] = I;
				}
			}
			solves(board, N, direction);
			fprintf(outfp, "Case #%d:\n", i+1);
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N - 1; k++) {
					fprintf(outfp, "%d ", board[j][k]);
				}
				fprintf(outfp, "%d\n", board[j][N-1]);
			}

		}
		fclose(infp);
		fclose(outfp);
		return 0;
	}
