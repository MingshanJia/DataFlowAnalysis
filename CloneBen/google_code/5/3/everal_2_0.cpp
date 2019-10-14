#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Moist()
{
    int numOfCases = 0;
    cin >> numOfCases;
    for(int i = 1; i <= numOfCases; ++i)
    {
        int caseNum = 0;
        cin >> caseNum;
        int dollars = 0;
        string sMax;
        string s;
        getline(cin, s);
        for(int i = 1; i <= caseNum; ++i)
        {
            getline(cin, s);
            if(s < sMax)
                ++dollars;
            else if(s > sMax)
                sMax = s;
        }
        cout << "Case #" << i << ": " << dollars << endl;
    }
}

int main()
{
    Moist();
}
