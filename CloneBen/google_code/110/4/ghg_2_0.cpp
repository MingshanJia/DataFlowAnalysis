#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int numd[9005];
int main()
{

    for(int i = 1 ; i <= 9000 ; i++)
    {
        double sum = 0;
        for(int j = 9000; j >= 1; j -= i)
        {
            sum += log10(j);
        }
        numd[i] = ceil(sum);
    }

    int N, d;
    cin >> N;
    for(int I = 0; I<N; I++)
    {
        cin>>d;
        int ans = -1;
        for(int i = 9000 ; i>= 1; i--)
            if(numd[i]<d)
            {
                ans = i;
            }
        cout<<"Case #"<<I+1<<": ";
        if(ans == -1)
            cout<<"..."<<endl;
        else
        {
            cout<<"IT'S OVER 9000";
            for(int i = 0; i< ans; i++)
                cout<<"!";
            cout<<endl;
        }
    }
    return 0;
}
