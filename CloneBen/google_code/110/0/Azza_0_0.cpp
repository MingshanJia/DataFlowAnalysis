#include <iostream>
#include<vector>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string>

using namespace std;

int numb (vector <int> & v )
{
    int ret = 0;
    reverse(v.begin(), v.end());

    for (int i=0; i < 8; i++)
        ret += v[i] * pow(2.0, (double) i);

    return ret;
}

int main() {
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);

    int T, B;
    cin >> T;

    for (int c= 1; c <=T; c++)
    {
        cin >> B;
        vector <vector <int> > bytes (B);

        char cc;
        for (int i = 0 ; i < B; i++)
            for (int j= 0 ; j < 8; j ++)
            {
                cin >> cc;
                if (cc == 'I')
                    bytes[i].push_back(1);
                else
                    bytes[i].push_back(0);
            }


        cout << "Case #" << c << ": ";

        for (int i=0; i < B; i++)
            cout << (char) numb(bytes[i]);
        cout << endl;

    }

    return 0;
}