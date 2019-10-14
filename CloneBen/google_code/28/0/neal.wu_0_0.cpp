#include <cstdio>
using namespace std;

int N;

int main ()
{
    scanf ("%d", &N);

    for (int n = 1, w, b; n <= N; n++)
    {
        scanf ("%d %d", &w, &b);
        printf ("Case #%d: %s\n", n, b & 1 ? "BLACK" : "WHITE");
    }

    return 0;
}
