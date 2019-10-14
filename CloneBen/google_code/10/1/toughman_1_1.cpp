#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

 
using namespace std;
 
int main(void) {
  
	int cases;
	
	//Read file "filename".
	
	ifstream infile;
	ofstream outfile;
	infile.open("B-large.in",ifstream::in);
	outfile.open("B-large.out" , ifstream::out);

 
	
	//cout<<"Reading from the file"<<endl;
	string cases1;
	getline(infile,cases1);
	cases = atoi(cases1.c_str()); //converting the string to int.
	//cout << "Total Cases = " << cases << endl;
	int times=0;
			
	while (times < cases) {
			
		string infor;
		getline(infile,infor);
		stringstream stream0(infor);
		string value;
		stream0 >> value;
		int length = atoi(value.c_str());
		stream0 >> value;

		int **array = new int * [length];
		for(int i = 0; i < length; i++){
			array[i] = new int[length];
		}
		int j = 0;
		while(j < length){
			string lineinfor;
			getline(infile,lineinfor);
			stringstream stream1(lineinfor);
			string cost;
			int k = 0;
			while(stream1 >> cost){
				array[j][k++] = atoi(cost.c_str());
			}
			j++;
		}

		if (value == "right"){
			int **newarray = new int * [length];
			for(int i = 0; i < length; i++){
				newarray[i] = new int[length];
			}

			for(int i = 0; i < length; i++){

				int *temp = new int[length];
				for(int kk = length - 1; kk >= 0; kk--){
					temp[kk] = array[i][kk];
				}

				int mark = length - 1;
				for(int kk = length - 1; kk >= 0; kk--){

					if(temp[kk] != 0)
						array[i][mark--] = temp[kk];
				}

				for(;mark >= 0; mark--){
					array[i][mark] = 0;
				}
				int oldy = length - 1;
				for(int j = length - 1; j >= 0; j--){

					if((oldy >= 0) && (oldy - 1) >= 0 && (array[i][oldy] == array[i][oldy - 1])){
						newarray[i][j] = array[i][oldy] + array[i][oldy - 1];
						oldy = oldy - 2;
					} else if((oldy >= 0) && (oldy - 1) >= 0 && (array[i][oldy] != array[i][oldy - 1])){
						newarray[i][j] = array[i][oldy];
						oldy = oldy - 1;
					} else if((oldy >= 0) && (oldy - 1) < 0){
						newarray[i][j] = array[i][oldy];
						oldy = oldy - 1;
					} else if((oldy < 0)){
						newarray[i][j] = 0;
						oldy = oldy - 1;
					}
				}
			}

			outfile << "Case #" << times + 1<< ":" << endl;
			for(int m = 0; m < length; m++){
				for(int n = 0; n < length; n++){
					outfile << newarray[m][n] << " ";
				}
				outfile << endl;
			}
		}


		if (value == "left"){
			int **newarray = new int * [length];
			for(int i = 0; i < length; i++){
				newarray[i] = new int[length];
			}

			for(int i = 0; i < length; i++){

				int *temp = new int[length];
				for(int kk = length - 1; kk >= 0; kk--){
					temp[kk] = array[i][kk];
				}

				int mark = 0;
				for(int kk = 0; kk < length; kk++){

					if(temp[kk] != 0)
						array[i][mark++] = temp[kk];
				}

				for(;mark < length; mark++){
					array[i][mark] = 0;
				}


				int oldy = 0;
				for(int j = 0; j < length; j++){
					if((oldy < length) && (oldy + 1 < length) && (array[i][oldy] == array[i][oldy + 1])){
						newarray[i][j] = array[i][oldy] + array[i][oldy + 1];
						oldy = oldy + 2;
					} else if((oldy < length) && (oldy + 1 < length) && (array[i][oldy] != array[i][oldy + 1])){
						newarray[i][j] = array[i][oldy];
						oldy = oldy + 1;
					} else if((oldy < length) && (oldy + 1 >= length)){
						newarray[i][j] = array[i][oldy];
						oldy = oldy + 1;
					} else if((oldy >= length)){
						newarray[i][j] = 0;
						oldy = oldy + 1;
					}
				}
			}
			outfile << "Case #" << times + 1 << ":" << endl;
			for(int m = 0; m < length; m++){
				for(int n = 0; n < length; n++){
					outfile << newarray[m][n] << " ";
				}
				outfile << endl;
			}
		}

		if (value == "up"){
			int **newarray = new int * [length];
			for(int i = 0; i < length; i++){
				newarray[i] = new int[length];
			}

			for(int i = 0; i < length; i++){

				int *temp = new int[length];
				for(int kk = length - 1; kk >= 0; kk--){
					temp[kk] = array[kk][i];
				}

				int mark = 0;
				for(int kk = 0; kk < length; kk++){

					if(temp[kk] != 0)
						array[mark++][i] = temp[kk];
				}

				for(;mark < length; mark++){
					array[mark][i] = 0;
				}


				int oldy = 0;
				for(int j = 0; j < length; j++){
					if((oldy < length) && (oldy + 1 < length) && (array[oldy][i] == array[oldy + 1][i])){
						newarray[j][i] = array[oldy][i] + array[oldy + 1][i];
						oldy = oldy + 2;
					} else if((oldy < length) && (oldy + 1 < length) && (array[oldy][i] != array[oldy + 1][i])){
						newarray[j][i] = array[oldy][i];
						oldy = oldy + 1;
					} else if((oldy < length) && (oldy + 1 >= length)){
						newarray[j][i] = array[oldy][i];
						oldy = oldy + 1;
					} else if((oldy >= length)){
						newarray[j][i] = 0;
						oldy = oldy + 1;
					}
				}
			}
			outfile << "Case #" << times + 1 << ":" << endl;
			for(int m = 0; m < length; m++){
				for(int n = 0; n < length; n++){
					outfile << newarray[m][n] << " ";
				}
				outfile << endl;
			}
		}


		if (value == "down"){
			int **newarray = new int * [length];
			for(int i = 0; i < length; i++){
				newarray[i] = new int[length];
			}

			for(int i = 0; i < length; i++){

				int *temp = new int[length];
				for(int kk = length - 1; kk >= 0; kk--){
					temp[kk] = array[kk][i];
				}

				int mark = length - 1;
				for(int kk = length - 1; kk >= 0; kk--){

					if(temp[kk] != 0)
						array[mark--][i] = temp[kk];
				}

				for(;mark >= 0; mark--){
					array[mark][i] = 0;
				}
				int oldy = length - 1;
				for(int j = length - 1; j >= 0; j--){

					if((oldy >= 0) && (oldy - 1) >= 0 && (array[oldy][i] == array[oldy - 1][i])){
						newarray[j][i] = array[oldy][i] + array[oldy - 1][i];
						oldy = oldy - 2;
					} else if((oldy >= 0) && (oldy - 1) >= 0 && (array[oldy][i] != array[oldy - 1][i])){
						newarray[j][i] = array[oldy][i];
						oldy = oldy - 1;
					} else if((oldy >= 0) && (oldy - 1) < 0){
						newarray[j][i] = array[oldy][i];
						oldy = oldy - 1;
					} else if((oldy < 0)){
						newarray[j][i] = 0;
						oldy = oldy - 1;
					}
				}
			}
			outfile << "Case #" << times + 1 << ":" << endl;
			for(int m = 0; m < length; m++){
				for(int n = 0; n < length; n++){
					outfile << newarray[m][n] << " ";
				}
				outfile << endl;
			}
		}

		times++;	
	}
		
	return 0;	
 
}