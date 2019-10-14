#include <cstdio>
#include <algorithm>

using namespace std;

int u, n, a, b;
int nn[50];
char yut[4];
int aaa[2];
int bb[2];
bool pa[2];
bool pb[2];
bool found;
int table[30][6];

int go2(int c, int y)
{
	if (table[c][y] == -2)
	{
		int ret = c;
		int prev = -1;
		int next = -1;
		for (int i=1; i<=y; ++i)
		{
			if (i == 1)
			{
				if (ret == 5)
					next = 20;
				else if (ret == 10)
					next = 25;
				else if (ret == 19)
					next = 29;
				else if (ret == 22)
					next = 27;
				else if (ret == 24)
					next = 15;
				else if (ret == 26)
					next = 22;
				else if (ret == 28)
					next = 29;
				else if (ret == 30)
					next = 30;
				else
					next = ret + 1;
			}
			else
			{
				if (ret == 19)
					next = 29;
				else if (ret == 22)
				{
					if (prev == 21)
						next = 23;
					else if (prev == 26)
						next = 27;
				}
				else if (ret == 24)
					next = 15;
				else if (ret == 26)
					next = 22;
				else if (ret == 28)
					next = 29;
				else if (ret == 30)
					next = 30;
				else
					next = ret + 1;
			}

			prev = ret;
			ret = next;
		}

		table[c][y] = ret;
	}

	return table[c][y];
}

bool post(bool f, int idx, int ta[], int tb[], bool pa[], bool pb[])
{
	bool cat = false;

	if (f)
	{
		for (int i=0; i<u; ++i)
		{
			if (ta[i] == 30)
				pa[i] = true;
			else if (ta[i] != 0)
			{
				for (int j=0; j<u; ++j)
				{
					if (ta[i] == tb[j])
					{
						tb[j] = 0;
						cat = true;
					}
				}
			}
		}
	}
	else
	{
		for (int i=0; i<u; ++i)
		{
			if (tb[i] == 30)
				pb[i] = true;
			else if (tb[i] != 0)
			{
				for (int j=0; j<u; ++j)
				{
					if (tb[i] == ta[j])
					{
						ta[j] = 0;
						cat = true;
					}
				}
			}
		}
	}

	if (nn[idx] >= 4 || cat)
	{
		if (f)
		{
			if (pa[0] && pa[1])
				return !f;
			else
				return f;
		}
		else
		{
			if (pb[0] && pb[1])
				return !f;
			else
				return f;
		}
	}
	else
		return !f;
}

void go(bool f, int idx, int ta[], int tb[], bool pa[], bool pb[])
{
	if (found)
		return;

	if (idx == n || (pa[0] && pa[1] && pb[0] && pb[1]))
	{
		if (ta[0] == 30)
			ta[0] = 0;
		if (ta[1] == 30)
			ta[1] = 0;
		if (tb[0] > 29)
			tb[0] = 0;
		if (tb[1] > 29)
			tb[1] = 0;
		
		sort(ta, ta+2);
		sort(tb, tb+2);
		for (int i=0; i<2; ++i)
		{
			if (aaa[i] != ta[i])
				return;
		}

		for (int i=0; i<2; ++i)
		{
			if (bb[i] != tb[i])
				return;
		}

		found = true;
		return;
	}

	if (f)
	{
		if (pa[0] == false && pa[1] == false && ta[0] == ta[1] && ta[0] != 0)
		{
			int tta[] = {ta[0], ta[1]};
			int ttb[] = {tb[0], tb[1]};
			bool tpa[] = {pa[0], pa[1]};
			bool tpb[] = {pb[0], pb[1]};

			tta[0] = tta[1] = table[tta[0]][nn[idx]];
			go(post(f, idx, tta, ttb, tpa, tpb), idx+1, tta, ttb, tpa, tpb);
		}
		else if (pa[0] && pa[1])
			go(!f, idx, ta, tb, pa, pb);
		else
		{
			for (int i=0; i<u; ++i)
			{
				if (pa[i] == false)
				{
					int tta[] = {ta[0], ta[1]};
					int ttb[] = {tb[0], tb[1]};
					bool tpa[] = {pa[0], pa[1]};
					bool tpb[] = {pb[0], pb[1]};

					tta[i] = table[tta[i]][nn[idx]];
					go(post(f, idx, tta, ttb, tpa, tpb), idx+1, tta, ttb, tpa, tpb);
				}
			}
		}
	}
	else
	{
		if (pb[0] == false && pb[1] == false && tb[0] == tb[1] && tb[0] != 0)
		{
			int tta[] = {ta[0], ta[1]};
			int ttb[] = {tb[0], tb[1]};
			bool tpa[] = {pa[0], pa[1]};
			bool tpb[] = {pb[0], pb[1]};

			ttb[0] = ttb[1] = table[ttb[0]][nn[idx]];
			go(post(f, idx, tta, ttb, tpa, tpb), idx+1, tta, ttb, tpa, tpb);
		}
		else if (pb[0] && pb[1])
			go(!f, idx, ta, tb, pa, pb);
		else
		{
			for (int i=0; i<u; ++i)
			{
				if (pb[i] == false)
				{
					int tta[] = {ta[0], ta[1]};
					int ttb[] = {tb[0], tb[1]};
					bool tpa[] = {pa[0], pa[1]};
					bool tpb[] = {pb[0], pb[1]};

					ttb[i] = table[ttb[i]][nn[idx]];
					go(post(f, idx, tta, ttb, tpa, tpb), idx+1, tta, ttb, tpa, tpb);
				}
			}
		}
	}
}

int main()
{
	for (int i=0; i<30; ++i)
	{
		for (int j=1; j<6; ++j)
			table[i][j] = -2;
	}

	for (int i=0; i<30; ++i)
	{
		for (int j=1; j<6; ++j)
			go2(i, j);
	}
	
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		scanf("%d %d %d %d", &u, &n, &a, &b);
		for (int i=0; i<n; ++i)
		{
			scanf("%s", yut);
			if (strcmp(yut, "Do") == 0)
				nn[i] = 1;
			else if (strcmp(yut, "Gae") == 0)
				nn[i] = 2;
			else if (strcmp(yut, "Gul") == 0)
				nn[i] = 3;
			else if (strcmp(yut, "Yut") == 0)
				nn[i] = 4;
			else if (strcmp(yut, "Mo") == 0)
				nn[i] = 5;
		}

		aaa[0] = aaa[1] = bb[0] = bb[1] = 0;
		for (int i=0; i<a; ++i)
		{
			scanf("%d", &aaa[i]);
			if (aaa[i] == 0)
				aaa[i] = 29;
		}

		for (int i=0; i<b; ++i)
		{
			scanf("%d", &bb[i]);
			if (bb[i] == 0)
				bb[i] = 29;
		}

		sort(aaa, aaa+2);
		sort(bb, bb+2);

		found = false;
		int ta[2] = {0, 0};
		int tb[2] = {0, 0};
		bool tpa[2] = {false, false};
		bool tpb[2] = {false, false};
		
		go(false, 0, ta, tb, tpa, tpb);
		if (found == false)
			go(true, 0, ta, tb, tpa, tpb);
		
		printf("Case #%d: ", c);
		if (found)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}