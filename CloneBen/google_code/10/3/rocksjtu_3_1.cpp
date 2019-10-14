#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct rect
{
	int w, h;
	rect(int _w, int _h)
	{
		w = _w;
		h = _h;
	}
};

struct myLess
{
	bool operator()(const rect& rect1, const rect& rect2)
	{
		return rect1.w < rect2.w;
	}
};

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
	string dir;
	string n_dir;
	string line;
	int data[500];
	int len;
	while (caseNum < cases) {
		caseNum++;

		getline(infile, line);
		stringstream lineStream(line);
		int n = 0;
		int m = 0;
		lineStream >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			lineStream >> len;
			data[i] = pow(2, len);
		}

		sort(data, data + n, greater<int>());
		priority_queue<rect, vector<rect>, myLess > que;
		
		int result = 1;
		que.push(rect(m, m));
		int pos = 0;
		while (pos < n)
		{
			rect r = que.top();
			que.pop();
			if (data[pos] <= r.w)
			{
				int small_w = r.w - data[pos];
				if (small_w > 0)
				{
					if (small_w > data[pos])
					{
						que.push(rect(data[pos], small_w));
					}
					else
					{
						que.push(rect(small_w, data[pos]));
					}
				}
				if (r.h - data[pos] > r.w)
				{
					que.push(rect(r.w, r.h - data[pos]));
				}
				else
				{
					que.push(rect(r.h - data[pos], r.w));
				}
				++pos;
			}
			else
			{
				que.push(r);
				que.push(rect(m, m));
				++result;
			}
		}
		outfile << "Case #" << caseNum << ": " << result << endl;
	}

	return 0;	

}