#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

void CaptainHammer()
{
    double g = 9.8;
    double pi = acos(-1.0);
    int numOfCases = 0;
    cin >> numOfCases;
    for(int i = 1; i <= numOfCases; ++i)
    {
        int v, d;
        cin >> v >> d;
        double theta = asin(g * d / (v * v)) / 2;
        theta = theta * 180 / pi;
        cout << "Case #" << i << ": " << fixed << setprecision(7) << theta << endl;
    }
}

int main()
{
    CaptainHammer();
}
