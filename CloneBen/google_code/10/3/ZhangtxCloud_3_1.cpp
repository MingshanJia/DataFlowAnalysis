#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
#include <Windows.h>
#include <time.h>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <utility>
using namespace std;

class tile
{
public:
    int a;
    int b;
};

bool operator<(const tile& lhs, const tile& rhs)
{
    if(lhs.a != rhs.a)
        return lhs.a < rhs.a;
    else
        return lhs.b < rhs.b;
}

void function(int i, ifstream& in_file, ofstream& out_file)
{
    vector<tile> has;
    int num;
    in_file >> num;
    int m;
    in_file >> m;
    vector<int> tile_size;
    int temp;
    for(int i = 0; i < num; i++)
    {
        in_file >> temp;
        tile_size.push_back(temp);
       
    }
    sort(tile_size.begin(), tile_size.end(), greater<int>());
    int result = 0;
    for(int i = 0; i < tile_size.size(); i++)
    {
        int size = tile_size[i];
        size = 1 << size;
        int j;
        int best_index = -1;
        int best_a = 1000000000;
        for(j = 0; j < has.size(); j++)
        {
            if(has[j].a < size)
                continue;
            if(has[j].a < best_a)
            {
                best_a = has[j].a;
                best_index = j;
            }
        }
        if(best_index == -1)
        {
            result ++;
            tile newtile;
            newtile.a = (min((size), (m - size)));
            newtile.b = (max((size), (m - size)));
            has.push_back(newtile);
            newtile.a = (min((m), (m - size)));
            newtile.b = (max((m), (m - size)));
            has.push_back(newtile);
        }
        else
        {
            int a = has[best_index].a;
            int b = has[best_index].b;  
            
            int left_a = a - size;
            int left_b = b - size;

            if(left_a > left_b)
            {
                has[best_index].a = (min((b), (left_a)));
                has[best_index].b = (max((b), (left_a)));
                tile newtile;
                newtile.a = (min((size), (left_b)));
                newtile.b = (max((size), (left_b)));
                has.push_back(newtile);
            }
            else
            {
                has[best_index].a = (min((a), (left_b)));
                has[best_index].b = (max((a), (left_b)));
                tile newtile;
                newtile.a = (min((size), (left_a)));
                newtile.b = (max((size), (left_a)));
                has.push_back(newtile);
            }

        }
    }
    out_file <<"Case #"<<i<<": " << result<<"\n";
}

int main()
{
    ifstream in_file;
    in_file.open("D-large.in");
    ofstream out_file;
    out_file.open("D-large.out");

    int num;
    in_file >> num;
    for(int i = 0; i < num; i ++)
    {
        cout<<i<<endl;
        function(i + 1, in_file, out_file);
    }

    in_file.close();
    out_file.close();
	return 0;
};