#include <stdio.h>
#include <string.h>

int u,n,a,b;
int v1[52][2][31][31];
int v2[52][2][31][31][31][31];

int thrown[64];

int moves[31][5]
=
{
	{30,30,30,30,30},//0
	{ 2, 3, 4, 5, 6},//1
	{ 3, 4, 5, 6, 7},//2
	{ 4, 5, 6, 7, 8},//3
	{ 5, 6, 7, 8, 9},//4
	{20,21,22,23,24},//5
	{ 7, 8, 9,10,11},//6
	{ 8, 9,10,11,12},//7
	{ 9,10,11,12,13},//8
	{10,11,12,13,14},//9
	{25,26,22,27,28},//10
	{12,13,14,15,16},//11
	{13,14,15,16,17},//12
	{14,15,16,17,18},//13
	{15,16,17,18,19},//14
	{16,17,18,19, 0},//15
	{17,18,19, 0,30},//16
	{18,19, 0,30,30},//17
	{19, 0,30,30,30},//18
	{ 0,30,30,30,30},//19
	{21,22,23,24,15},//20
	{22,23,24,15,16},//21
	{27,28, 0,30,30},//22
	{24,15,16,17,18},//23
	{15,16,17,18,19},//24
	{26,22,27,28, 0},//25
	{22,27,28, 0,30},//26
	{28, 0,30,30,30},//27
	{ 0,30,30,30,30},//28
	{ 1, 2, 3, 4, 5},//29
	{30,30,30,30,30} //30
};

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		const char *ansstr = "NO";
		scanf("%d%d%d%d",&u,&n,&a,&b);
		for(int i = 0;i < n;i ++)
		{
			char word[256];
			scanf("%s",word);
			if(stricmp(word, "Do") == 0)
			{
				thrown[i] = 0;
			}
			else if(stricmp(word, "Gae") == 0)
			{
				thrown[i] = 1;
			}
			else if(stricmp(word, "Gul") == 0)
			{
				thrown[i] = 2;
			}
			else if(stricmp(word, "Yut") == 0)
			{
				thrown[i] = 3;
			}
			else if(stricmp(word, "Mo") == 0)
			{
				thrown[i] = 4;
			}
			else
			{
				while(1) {fprintf(stderr,"Unknown!\n");}
			}
		}
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		if(u == 1) {
			v1[0][0][29][29] = 1;
			for(int i = 0;i < n;i ++)
			{
				for(int t = 0; t < 2; t ++)
				{
					for(int m1 = 0; m1 < 31; m1 ++)
					{
						for(int m2 = 0; m2 < 31; m2 ++)
						{
							if(m1 == 30 || m2 == 30) continue; // 진행불가
							if(v1[i][t][m1][m2] == 0) continue;
							int nt = t ^ 1;
							if(t == 0)
							{
								if(thrown[i] >= 3) nt = t;
								int nm = moves[m1][thrown[i]];
								if(nm == m2)
								{
									nt = t;
									v1[i+1][nt][nm][29] = 1;
								}
								else
								{
									v1[i+1][nt][nm][m2] = 1;
								}
							}
							else
							{
								if(thrown[i] >= 3) nt = t;
								int nm = moves[m2][thrown[i]];
								if(nm == m1)
								{
									nt = t;
									v1[i+1][nt][29][nm] = 1;
								}
								else
								{
									v1[i+1][nt][m1][nm] = 1;
								}
							}
						}
					}
				}
			}
			{
				int m1 = 29, m2 = 29;
				if(a != 0) scanf("%d",&m1);
				if(b != 0) scanf("%d",&m2);
				for(int i = 0;i < 2;i ++)
				{
					for(int j = 0;j < 2; j++)
					{
						for(int k = 0;k < 2;k++)
						{
							int nm1 = m1;
							int nm2 = m2;
							if(j && m1 == 29) nm1 = 30;
							if(k && m2 == 29) nm2 = 30;
							if(v1[n][i][nm1][nm2])
								ansstr = "YES";
						}
					}
				}
			}
		}
		if(u == 2) {
			v2[0][0][29][29][29][29] = 1;
		}

		printf("Case #%d: %s\n", testcase, ansstr);
	}
	return 0;
}