#include <algorithm>
#include <stdio.h>
#include <memory.h>
using namespace std;

struct _data {
	int p, s;

	inline bool operator < (const _data &rhs) const { return p + s < rhs.p + rhs.s; }
};

int n;
_data data[1010];

bool dynamic[1000010];

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d %d", &data[i].p, &data[i].s);

		sort(data, data+n);

		memset(dynamic, 0, sizeof(dynamic));
		dynamic[0] = true;
		int sum = 0;
		for (i=0; i<n; i++) {
			for (j=min(sum, data[i].p); j>=0; j--) {
				if (dynamic[j]) dynamic[j+data[i].s] = true;
			}
			sum += data[i].s;
		}

		for (i=sum; i>=0; i--) if (dynamic[i]) break;
		printf("Case #%d: %d\n", ++tt, i);
	}

	return 0;
}
