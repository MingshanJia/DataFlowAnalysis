#include <cstdio>
using namespace std;
int main()
{
	int n;
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int test_case = 1 ; test_case <= n ; test_case++)
	{
		char s[100];
		bool appear_alpha[26] = {0,}, appear_digit[10] = {0,};
		scanf("%s", s);

		for (int i = 0 ; s[i] != '\0' ; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				appear_alpha[s[i] - 'a'] = true;
			if (s[i] >= '0' && s[i] <= '9')
				appear_digit[s[i] - '0'] = true;
		}

		int base = 0;
		for (int i = 0 ; i < 26 ; i++)
			if (appear_alpha[i]) base++;
		for (int i = 0 ; i < 10 ; i++)
			if (appear_digit[i]) base++;
		if (base == 1) base++;

		int value_alpha[26], value_digit[10];
		for (int i = 0  ;i < 26 ; i++) value_alpha[i] = -1;
		for (int i = 0 ; i< 10 ; i++) value_digit[i] = -1;

		if (s[0] >= 'a' && s[0] <= 'z')
			value_alpha[s[0] - 'a'] = 1;
		else
			value_digit[s[0] - '0'] = 1;

		int v = 0;
		long long answer = 1;
		for (int i = 1 ; s[i] != '\0' ; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				if (value_alpha[s[i] - 'a'] == -1)
				{
					value_alpha[s[i] - 'a'] = v;
					if (v == 0)
						v += 2;
					else v++;
				}

				answer = answer * base + value_alpha[s[i] - 'a'];
			}
			else
			{
				if (value_digit[s[i] - '0'] == -1)
				{
					value_digit[s[i] - '0'] = v;
					if (v == 0) v += 2; else v++;
				}

				answer = answer * base + value_digit[s[i] - '0'];
			}
		}

		printf("Case #%d: %lld\n", test_case, answer);
	}

	return 0;
}