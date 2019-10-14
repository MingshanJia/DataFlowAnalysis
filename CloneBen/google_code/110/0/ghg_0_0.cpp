#include <iostream>
#include <string>
using namespace std;
char str2char(string s)
{
    int sum = 0, tdo = 1;
    for(int i = s.size() - 1; i>=0; i--)
    {
        if(s[i]=='I')
        {
            sum += tdo;
        }
        tdo *= 2;
    }
    return sum;
}
int main()
{
    int N;
    cin>>N;
    for(int I=0;I<N;I++)
    {
        int n;
        string s, ans = "";
        cin>>n;
        cin>>s;
        for(int i = 0; i<s.size(); i+=8)
        {
            string s1 = s.substr(i,8);
            ans = ans + str2char(s1);
        }
        cout<<"Case #"<<I+1<<": "<<ans<<endl;
    }
    return 0;
}


