#include<cstdio>
#include<map>
#include<cstring>
using namespace std;

map<char , int> Map;
int value, base;
char str[1000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int cases;
	scanf("%d" , &cases);
	for (int ca = 1; ca <= cases; ++ca)
	{
		scanf("%s" , str);
		printf("Case #%d: ", ca);
		Map.clear();
		base = 2; value = 0;
		Map[str[0]] = 1;
		for (int i = 1; str[i]; ++i)
			if (Map.find(str[i]) == Map.end())
			{
				Map[str[i]] = value;
				++value;
				if (value == 1) value = 2;
			}
		if (value > 2) base = value;
		long long ans = 0;
		for (int i = 0; str[i]; ++i) ans = ans * base + Map[str[i]];
		printf("%I64d\n", ans);
	}

}
