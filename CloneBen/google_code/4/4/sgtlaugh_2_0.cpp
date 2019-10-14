#include <bits/stdtr1c++.h>

#define MAX 4444
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

const long long HMOD[] = {2078526727, 2117566807};
const long long BASE[] = {1572872831, 1971536491};

struct stringhash{
    int len;
    vector <long long> P[2], H[2];

    stringhash(){}
    stringhash(char* str){
        int i, j;
        len = strlen(str);

        for (i = 0; i < 2; i++){
            P[i].resize(len + 1, 0);
            H[i].resize(len + 1, 0);
            for (P[i][0] = 1, j = 1; j <= len; j++) P[i][j] = (P[i][j - 1] * BASE[i]) % HMOD[i];

            H[i][0] = 0;
            for (j = 0; j < len; j++){
                H[i][j] = ((H[i][j] * BASE[i]) + str[j] + 1007) % HMOD[i];
                H[i][j + 1] = H[i][j];
            }
        }
    }

    inline long long range_hash(int l, int r){
        long long ar[2];
        ar[0] = H[0][r], ar[1] = H[1][r];
        if (l){
            for (int i = 0; i < 2; i++){
                ar[i] -= ((P[i][r - l + 1] * H[i][l - 1]) % HMOD[i]);
                if (ar[i] < 0) ar[i] += HMOD[i];
            }
        }
        return (ar[0] << 32) ^ ar[1];
    }
};

char str[MAX];
int n, dp[MAX];
tr1::unordered_map <long long, int> dictionary;

int F(int i){
    if (i == n) return 1;
    if (dp[i] != -1) return dp[i];

    int j, k;
    char temp[30];
    long long x, h, res = 0;

    for (j = i, k = 0; k < 25 && j < n; k++, j++){
        temp[k] = str[j];
        sort(temp, temp + k + 1);
        temp[k + 1] = 0;

        stringhash s = stringhash(temp);
        x = 0, h = s.range_hash(0, k);
        if (dictionary.count(h)){
            x = dictionary[h];
            res = (res + (x * F(j + 1)));
            res %= MOD;
        }
    }

    return (dp[i] = res);
}

int main(){
    read();
    write();
    int T = 0, t, q, i, j, k, l;

    scanf("%d", &t);
    while (t--){
        dictionary.clear();
        scanf("%d %d", &n, &q);
        while (n--){
            scanf("%s", str);
            l = strlen(str);
            sort(str, str + l);
            stringhash s = stringhash(str);
            dictionary[s.range_hash(0, l - 1)]++;
        }

        fprintf(stderr, "%d\n", T + 1);
        printf("Case #%d:", ++T);
        while (q--){
            scanf("%s", str);
            n = strlen(str);

            memset(dp, -1, sizeof(dp));
            printf(" %d", F(0));
        }
        puts("");
    }
    return 0;
}
