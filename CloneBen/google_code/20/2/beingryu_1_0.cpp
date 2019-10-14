#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int lookup_table[2][11][11][11][2][2][2][2];

inline int& lookup(int op, int a, int b, int c, int lead_a, int lead_b, int lead_c, int carry)
{
	return lookup_table[op][a][b][c][lead_a][lead_b][lead_c][carry];
}

void init()
{
	for (int i = 0;i < 40 * 40 * 40 * 2;i++)
	{
		int ka = i % 40;
		int kb = (i / 40) % 40;
		int kc = (i / 40 / 40) % 40;
		int carry = i / 40 / 40 / 40;

		int a = ka % 10;
		int b = kb % 10;
		int c = kc % 10;

		int lead_a = (ka / 10) % 2;
		int lead_b = (kb / 10) % 2;
		int lead_c = (kc / 10) % 2;

		int wild_a = (ka / 10) / 2;
		int wild_b = (kb / 10) / 2;
		int wild_c = (kc / 10) / 2;

		if (lead_a && !a || lead_b && !b || lead_c && !c)
			continue;

		if ((a + b + carry) % 10 == c)
			lookup(0, wild_a ? 10 : a, wild_b ? 10 : b, wild_c ? 10 : c, lead_a, lead_b, lead_c, carry) |= (1 << (a + b + carry >= 10));
		if ((a - b - carry + 10) % 10 == c)
			lookup(1, wild_a ? 10 : a, wild_b ? 10 : b, wild_c ? 10 : c, lead_a, lead_b, lead_c, carry) |= (1 << (a - b - carry < 0));
	}
}

inline int get_digit(string &str, int idx)
{
	if (str.size() - 1 < idx)
		return 0;
	char v = str[str.size() - 1 - idx];
	return v != '?' ? v - '0' : 10;
}

int feasible(string &a, string &b, string &c, int op)
{
	int dp[251][2] = {0, };
	dp[0][0] = true;

	for (int i = 0;i < 250;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			if (!dp[i][j])
				continue;

			int va = get_digit(a, i);
			int vb = get_digit(b, i);
			int vc = get_digit(c, i);
			
			int lead_a = (a.size() == i + 1 && a.size() > 1);
			int lead_b = (b.size() == i + 1 && b.size() > 1);
			int lead_c = (c.size() == i + 1 && c.size() > 1);


			int res = lookup(op, va, vb, vc, lead_a, lead_b, lead_c, j);
			if (res & 1)
				dp[i + 1][0] = true;
			if (res & 2)
				dp[i + 1][1] = true;
		}
	}

	return dp[250][0];
}

void update(string &a, string &b, string &c, string &todo, int op)
{
	for (int i = 0;i < todo.size();i++)
	{
		if (todo[i] != '?') continue;
		for (int j = (!i && todo.size() > 1);j < 10;j++)
		{
			todo[i] = j + '0';
			if (feasible(a, b, c, op))
				break;
		}
	}
}

string solve(string a, string b, string c, string op)
{
	update(a, b, c, a, op == "-");
	update(a, b, c, b, op == "-");
	update(a, b, c, c, op == "-");

	return a + " " + op + " " + b + " = " + c;
}

int main()
{
	init();

	int tc;
	scanf("%d", &tc);

	for (int ti = 1;ti <= tc;ti++)
	{
		string a, op, b, eq, c;
		cin >> a >> op >> b >> eq >> c;

		printf("Case #%d: %s\n", ti, solve(a, b, c, op).c_str());
	}
	return 0;
}
