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

struct lessstruct
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
	infile.open("D-small-attempt0.in",ifstream::in);
	outfile.open("D-small-attempt0.out" , ifstream::out);



	//cout<<"Reading from the file"<<endl;
	string cases1;
	getline(infile,cases1);
	cases = atoi(cases1.c_str()); //converting the string to int.

	//cout << "Total Cases = " << cases << endl;
	int times = 0;

	int data[500];
	int len;
	while (times < cases) {
		times++;
		string line;
		getline(infile, line);
		stringstream stream1(line);
		int n = 0;
		int m = 0;
		stream1 >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			stream1 >> len;
			data[i] = pow(2, len);
		}

		sort(data, data + n, greater<int>());
		priority_queue<rect, vector<rect>, lessstruct > que;
		
		int result = 1;
		que.push(rect(m, m));
		int pos = 0;
		while (pos < n)
		{
			rect r = que.top();
			que.pop();
			if (data[pos] > r.w){
				que.push(r);
				que.push(rect(m, m));
				++result;
			}
			else 
			{
				int remainWidth = r.w - data[pos];
				int remainHeight = r.h - data[pos];
				que.push(rect(min(data[pos], remainWidth),max(data[pos], remainWidth)));
				que.push(rect(min(r.w, remainHeight),max(r.w, remainHeight)));
				++pos;
			}

		}
		outfile << "Case #" << times << ": " << result << endl;
	}

	return 0;	

}