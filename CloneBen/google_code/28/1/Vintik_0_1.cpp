#include <iostream>

using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    cin >> T;

    for (int t=1; t <= T; t++)
    {
        int W, B;
        cin >> W >> B;

        if (B%2 == 0)
            cout << "Case #" << t << ": WHITE" << endl;
        else
            cout << "Case #" << t << ": BLACK" << endl;
    }

    return 0;
}
