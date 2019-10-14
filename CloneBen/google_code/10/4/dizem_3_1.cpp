#include <iostream>
#include <string>

using namespace std;

/*
4
1 6 2
2 6 2 2
3 6 2 1 1
7 277 3 8 2 6 1 3 6
*/

int T, N, M;
int S[10000];
int ans;

struct block
{
    int w;
    int h;
};

char cmp(block a, block b)
{
    return a.w < b.w;
}

char cmp_int(int a, int b)
{
    return a > b;
}

int pow(int n)
{
    int re = 1;
    for (int i = 0; i < n; i++)
    {
        re *= 2;
    }
    return re;
}

block blocks[2000];
int num = 0;

void fenge(int index, int now_w)
{
    if (blocks[index].w == now_w)
    {
        int t_h = blocks[index].h - now_w;
        if (t_h >= now_w)
            blocks[index].h = t_h;
        else
        {
            blocks[index].h = now_w;
            blocks[index].w = t_h;
        }
    }
    else
    {
        int t_h1 = blocks[index].h - now_w;
        int t_w1 = blocks[index].w;
        int t_h2 = now_w;
        int t_w2 = blocks[index].w - now_w;
        if (t_h1 >= t_w1)
        {
            blocks[index].h = t_h1;
            blocks[index].w = t_w1;
        }
        else
        {
            blocks[index].h = t_w1;
            blocks[index].w = t_h1;
        }
        if (t_h2 >= t_w2)
        {
            blocks[num].h = t_h2;
            blocks[num].w = t_w2;
        }
        else
        {
            blocks[num].h = t_w2;
            blocks[num].w = t_h2;
        }
        num++;
    }
}


int main()
{
    //freopen("az_in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int temp_s;
    cin >> T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin >> N >> M;
        memset(S, 0, sizeof(S));
        ans = 0;
        num = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> temp_s;
            S[i] = pow(temp_s);
        }
        sort(S, S + N, cmp_int);
        for (int i = 0; i < N; i++)
        {
            int now_w = S[i];
            int temp_index = -1;
            for (int j = 0; j < num; j++)
            {
                if (blocks[j].w >= now_w)
                {
                    temp_index = j;
                    break;
                }
            }
            if (temp_index == -1)
            {
                blocks[num].w = M;
                blocks[num].h = M;
                temp_index = num;
                num++;
                ans++;
            }
            fenge(temp_index, now_w);
            sort(blocks, blocks + num, cmp);
        }
        cout << "Case #" << cnt << ": " << ans << endl;
    }
    return 0;
}