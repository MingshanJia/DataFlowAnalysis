#include <iostream>
#include <vector>
#include <algorithm> 
#include <functional> 
using namespace std;

int cas[10];
vector<int> calculator, base;
int ans = 999999999999;
char str[1000000];

void getBase2(int num, int teacher_num)
{
	if (num > teacher_num)
	{
		return;
	}
	for (int i = 0; i < calculator.size(); ++i)
	{
		if (!(num == 0 && calculator[i] == 0))
		{
			getBase2(num*10+i, teacher_num);
		}
	}
	if (num != 0)
	{
		if (teacher_num%num == 0)
		{
			base.push_back(num);
		}
	}
}

void getBase(int num)
{
	base.clear();
	getBase2(0, num);
	sort(base.begin(), base.end(), greater<int>());
	vector<int> tmp;
	for (int i = 0; i < base.size(); ++i)
	{
		if (base[i] != 1)
		{
			tmp.push_back(base[i]);
		}
	}
	base.clear();
	for (int i = 0; i < tmp.size(); ++i)
	{
		base.push_back(tmp[i]);
	}
}


void mimBase(int num, int teacher_num, int step)
{
	itoa(teacher_num, str, 10);
	if (ans == (strlen(str)+1))
	{
		return;
	}
	if (num == teacher_num)
	{
		if (ans > step)
		{
			ans = step;
		}
	}
	if (num >= teacher_num)
	{
		return;
	}
	getBase(teacher_num/num);
	for (int i = 0; i < base.size(); ++i)
	{
		itoa(base[i], str, 10);
		mimBase(num*base[i], teacher_num, step+strlen(str)+1);
	}
}
int solve()
{
	calculator.clear();
	for (int i = 0; i < 10; ++i)
	{
		if (cas[i] == 1)
		{
			calculator.push_back(i);
		}
	}
	ans = 999999999999;
	int teacher_num;
	cin >> teacher_num;
	getBase(teacher_num);
	for (int i = 0; i < base.size(); ++i)
	{
		itoa(base[i], str, 10);
		mimBase(base[i], teacher_num, strlen(str)+1);
	}
	if (teacher_num == 1)
	{
		for (int i = 0; i < calculator.size(); ++i)
		{
			if (calculator[i] == 1)
			{
				ans = 2;
				break;
			}
		}
	}
	return ans;
}

void input(int T)
{
	for (int i = 0; i < 10; ++i)
	{
		cin >> cas[i];
	}
	int res = solve();
	if (res == 999999999999)
	{
		cout << "Case #" << T << ": Impossible" << endl;
	}
	else
	{
		cout << "Case #" << T << ": " << res << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		input(i);
	}
	return 0;
}