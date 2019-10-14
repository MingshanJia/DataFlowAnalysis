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
	infile.open("A-small-practice.in",ifstream::in);
	outfile.open("output.in" , ifstream::out);



	//cout<<"Reading from the file"<<endl;
	string cases1;
	getline(infile,cases1);
	cases = atoi(cases1.c_str()); //converting the string to int.

	//cout << "Total Cases = " << cases << endl;
	int caseNum = 0;
	int n = 0;
	string dir;
	string n_dir;
	string line;
	int data[20][20];
	while (caseNum < cases) {
		caseNum++;
		getline(infile, n_dir);			
		stringstream stream1(n_dir); //using stringstream to parse the price list line into array.

		stream1 >> n >> dir;

		for (int i = 0; i < n; ++i)
		{
			getline(infile, line);
			stringstream lineStream(line);
			for (int j = 0; j < n; j++)
			{
				lineStream >> data[i][j];
			}
		}

		if (dir == "right")
		{
			for (int i = 0; i < n; ++i)
			{
				int pos = n - 1;
				int fixPos = n - 1;
				while (pos >= 0)
				{
					while (pos >= 0 && data[i][pos] == 0)
					{
						--pos;
					}
					int pos1 = pos;
					--pos;
					while (pos >= 0 && data[i][pos] == 0)
					{
						--pos;
					}

					if (pos >= 0)
					{
						if (data[i][pos1] == data[i][pos])
						{
							data[i][fixPos] = data[i][pos] << 1;
							--fixPos;
							--pos;
						}
						else
						{
							data[i][fixPos] = data[i][pos1];
							--fixPos;
						}
					}
					else
					{
						data[i][fixPos] = pos1 >= 0 ? data[i][pos1] : 0;
						--fixPos;
					}
				}

				for (int j = 0; j <= fixPos; j++)
				{
					data[i][j] = 0;
				}
			}
		}
		else if(dir == "left")
		{
			for (int i = 0; i < n; ++i)
			{
				int pos = 0;
				int fixPos = 0;
				while (pos < n)
				{
					while (pos < n && data[i][pos] == 0)
					{
						++pos;
					}
					int pos1 = pos;
					++pos;
					while (pos < n && data[i][pos] == 0)
					{
						++pos;
					}

					if (pos < n)
					{
						if (data[i][pos1] == data[i][pos])
						{
							data[i][fixPos] = data[i][pos] << 1;
							++fixPos;
							++pos;
						}
						else
						{
							data[i][fixPos] = data[i][pos1];
							++fixPos;
						}
					}
					else
					{
						data[i][fixPos] = pos1 < n ? data[i][pos1] : 0;
						++fixPos;
					}
				}

				for (int j = fixPos; j < n; j++)
				{
					data[i][j] = 0;
				}
			}
		}
		else if(dir == "up")
		{
			for (int j = 0; j < n; ++j)
			{
				int pos = 0;
				int fixPos = 0;
				while (pos < n)
				{
					while (pos < n && data[pos][j] == 0)
					{
						++pos;
					}
					int pos1 = pos;
					++pos;
					while (pos < n && data[pos][j] == 0)
					{
						++pos;
					}

					if (pos < n)
					{
						if (data[pos1][j] == data[pos][j])
						{
							data[fixPos][j] = data[pos][j] << 1;
							++fixPos;
							++pos;
						}
						else
						{
							data[fixPos][j] = data[pos1][j];
							++fixPos;
						}
					}
					else
					{
						data[fixPos][j] = pos1 < n ? data[pos1][j] : 0;
						++fixPos;
					}
				}

				for (int i = fixPos; i < n; i++)
				{
					data[i][j] = 0;
				}
			}
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{
				int pos = n - 1;
				int fixPos = n - 1;
				while (pos >= 0)
				{
					while (pos >= 0 && data[pos][j] == 0)
					{
						--pos;
					}
					int pos1 = pos;
					--pos;
					while (pos >= 0 && data[pos][j] == 0)
					{
						--pos;
					}

					if (pos >= 0)
					{
						if (data[pos1][j] == data[pos][j])
						{
							data[fixPos][j] = data[pos][j] << 1;
							--fixPos;
							--pos;
						}
						else
						{
							data[fixPos][j] = data[pos1][j];
							--fixPos;
						}
					}
					else
					{
						data[fixPos][j] = pos1 >= 0 ? data[pos1][j] : 0;
						--fixPos;
					}
				}

				for (int i = 0; i <= fixPos; i++)
				{
					data[i][j] = 0;
				}
			}
		}

		outfile << "Case #" << caseNum << ":" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				outfile << data[i][j] << " ";
			}
			outfile << data[i][n - 1] << endl;
		}
	}

	return 0;	

}