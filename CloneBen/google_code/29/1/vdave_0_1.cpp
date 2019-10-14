// Google Code Jam Practice
// by vdave, Hungary, 2008

#include <algorithm>
#include <cstdio>


//////////////////////
// A: ALIEN NUMBERS //
//////////////////////

int sValue[256], tValue[256], sRadix, tRadix;
char sNum[1024], sSource[1024], sTarget[1024];

void exec_alien_numbers()
{
	// Read # of test cases
	int N;
	scanf("%d", &N);

	for (int tc = 1; tc <= N; ++tc)
	{
		// number source_lang target_lang
		scanf("%s %s %s", sNum, sSource, sTarget);

		// Process source language
		sRadix = 0;
		char *s = sSource;
		while (*s)
		{
			sValue[*s++] = (sRadix++);
		}

		// Process target language
		tRadix = 0;
		s = sTarget;
		while (*s)
		{
			tValue[*s++] = (tRadix++);
		}

		// Parse number
		long long num = 0;
		s = sNum;
		while (*s)
		{
			num = num * sRadix;
			num += sValue[*s++];
		}

		// Display number
		s = sNum;
		do
		{
			*s++ = sTarget[num % tRadix];
			num /= tRadix;
		} while (num);
		*s = '\0';
		std::reverse(sNum, s);

		printf("Case #%d: %s\n", tc, sNum);
	}
}

int main(int argc, char *argv[])
{
	exec_alien_numbers();
	return 0;
}

