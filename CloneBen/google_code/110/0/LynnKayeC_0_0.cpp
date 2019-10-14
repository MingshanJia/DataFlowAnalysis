#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void work(ifstream & fin, int caseno)
{
    int n;
    string s;
    fin >> n >> s;
    cout << "Case #" << caseno << ": ";
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 8 == 0)
            sum = 0;
        sum = sum * 2 + (s[i] == 'O' ? 0: 1);
        if (i % 8 == 7)
            cout << char(sum);
    }
    cout << endl;
}


int main()
{
    ifstream fin;
    fin.open("input");
    int casenum;
    fin >> casenum;
    for (int i = 0; i < casenum; ++i) {
        work(fin, i + 1);
    }
    fin.close();
    return 0;
}
