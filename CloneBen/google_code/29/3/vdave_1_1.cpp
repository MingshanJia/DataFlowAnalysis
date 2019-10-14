// Google Code Jam Practice
// by vdave, Hungary, 2008

#include <algorithm>
#include <cstdio>
#include <vector>


//////////////////////
// A: ALIEN NUMBERS //
//////////////////////

int sValue[256], tValue[256], sRadix, tRadix;
char sNum[1024], sSource[1024], sTarget[1024];
char sMData[] = "0123456789abcdef";

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


/////////////////////////
// B: ALWAYS TURN LEFT //
/////////////////////////

char sMaze1[10240], sMaze2[10240];

void exec_always_turn_left()
{
	// Read # of test cases
	int N;
	scanf("%d", &N);

	for (int tc = 1; tc <= N; ++tc)
	{
		// Read input
		scanf("%s %s", sMaze1, sMaze2);

		// Get maze size
		int maxY = 0, minX = 0, maxX = 0;
		int cX = 0, cY = -1, dX = 0, dY = 1, t;

		// Entrace -> Exit
		char *s = sMaze1;
		while (s[1])
		{
			switch (*s)
			{
			case 'W':
				cX += dX;
				cY += dY;
				break;
			case 'L':
				t = dX; dX = dY; dY = -t;
				break;
			case 'R':
				t = dX; dX = -dY; dY = t;
				break;
			}

			if (cX > maxX) maxX = cX;
			if (cX < minX) minX = cX;
			if (cY > maxY) maxY = cY;
			s++;
		}

		// Step out of maze and return
		cX += dX;
		cY += dY;
		dX = -dX;
		dY = -dY;

		// Exit -> Entrance
		s = sMaze2;
		while (s[1])
		{
			switch (*s)
			{
			case 'W':
				cX += dX;
				cY += dY;
				break;
			case 'L':
				t = dX; dX = dY; dY = -t;
				break;
			case 'R':
				t = dX; dX = -dY; dY = t;
				break;
			}

			if (cX > maxX) maxX = cX;
			if (cX < minX) minX = cX;
			if (cY > maxY) maxY = cY;
			s++;
		}

		// Initialize maze data
		int mH = maxY + 1;
		int mW = maxX - minX + 1;
		std::vector<std::vector<int> > mD(mH, std::vector<int>(mW, 0));

		// Entrace -> Exit
		cX = 0, cY = 0, dX = 0, dY = 1;
		s = sMaze1 + 1;
		while (*s)
		{
			switch (*s)
			{
			case 'W':
				if (dY == -1) t = 1;
				else if (dY == 1) t = 2;
				else if (dX == 1) t = 8;
				else if (dX == -1) t = 4;
				mD[cY][cX - minX] |= t;

				cX += dX;
				cY += dY;
				break;
			case 'L':
				t = dX; dX = dY; dY = -t;
				break;
			case 'R':
				t = dX; dX = -dY; dY = t;
				break;
			}
			s++;
		}

		dX = -dX;
		dY = -dY;
		cX += dX;
		cY += dY;

		// Exit -> Entrance
		s = sMaze2 + 1;
		while (*s)
		{
			switch (*s)
			{
			case 'W':
				if (dY == -1) t = 1;
				else if (dY == 1) t = 2;
				else if (dX == 1) t = 8;
				else if (dX == -1) t = 4;
				mD[cY][cX - minX] |= t;

				cX += dX;
				cY += dY;
				break;
			case 'L':
				t = dX; dX = dY; dY = -t;
				break;
			case 'R':
				t = dX; dX = -dY; dY = t;
				break;
			}
			s++;
		}

		printf("Case #%d:\n", tc);
		for (int v = 0; v < mH; ++v)
		{
			for (int u = 0; u < mW; ++u)
			{
				printf("%c", sMData[mD[v][u]]);
			}
			printf("\n");
		}
	}
}


int main(int argc, char *argv[])
{
	// exec_alien_numbers();
	exec_always_turn_left();
	return 0;
}

