// #include <iostream>
// #include <vector>
// #include <algorithm> 
// #include <functional> 
// using namespace std;
// 
// int cas[10];
// vector<int> calculator, base;
// int ans = 999999999999;
// char str[1000000];
// 
// void getBase2(int num, int teacher_num)
// {
// 	if (num > teacher_num)
// 	{
// 		return;
// 	}
// 	for (int i = 0; i < calculator.size(); ++i)
// 	{
// 		if (!(num == 0 && calculator[i] == 0))
// 		{
// 			getBase2(num*10+i, teacher_num);
// 		}
// 	}
// 	if (num != 0)
// 	{
// 		if (teacher_num%num == 0)
// 		{
// 			base.push_back(num);
// 		}
// 	}
// }
// 
// void getBase(int num)
// {
// 	base.clear();
// 	getBase2(0, num);
// 	sort(base.begin(), base.end(), greater<int>());
// 	vector<int> tmp;
// 	for (int i = 0; i < base.size(); ++i)
// 	{
// 		if (base[i] != 1)
// 		{
// 			tmp.push_back(base[i]);
// 		}
// 	}
// 	base.clear();
// 	for (int i = 0; i < tmp.size(); ++i)
// 	{
// 		base.push_back(tmp[i]);
// 	}
// }
// 
// 
// void mimBase(int num, int teacher_num, int step)
// {
// 	itoa(teacher_num, str, 10);
// 	if (ans == (strlen(str)+1))
// 	{
// 		return;
// 	}
// 	if (num == teacher_num)
// 	{
// 		if (ans > step)
// 		{
// 			ans = step;
// 		}
// 	}
// 	if (num >= teacher_num)
// 	{
// 		return;
// 	}
// 	getBase(teacher_num/num);
// 	for (int i = 0; i < base.size(); ++i)
// 	{
// 		itoa(base[i], str, 10);
// 		mimBase(num*base[i], teacher_num, step+strlen(str)+1);
// 	}
// }
// int solve()
// {
// 	calculator.clear();
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		if (cas[i] == 1)
// 		{
// 			calculator.push_back(i);
// 		}
// 	}
// 	ans = 999999999999;
// 	int teacher_num;
// 	cin >> teacher_num;
// 	getBase(teacher_num);
// 	for (int i = 0; i < base.size(); ++i)
// 	{
// 		itoa(base[i], str, 10);
// 		mimBase(base[i], teacher_num, strlen(str)+1);
// 	}
// 	if (teacher_num == 1)
// 	{
// 		for (int i = 0; i < calculator.size(); ++i)
// 		{
// 			if (calculator[i] == 1)
// 			{
// 				ans = 2;
// 				break;
// 			}
// 		}
// 	}
// 	return ans;
// }
// 
// void input(int T)
// {
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		cin >> cas[i];
// 	}
// 	int res = solve();
// 	if (res == 999999999999)
// 	{
// 		cout << "Case #" << T << ": Impossible" << endl;
// 	}
// 	else
// 	{
// 		cout << "Case #" << T << ": " << res << endl;
// 	}
// }
// 
// int main()
// {
// 	int T;
// 	cin >> T;
// 	for (int i = 1; i <= T; ++i)
// 	{
// 		input(i);
// 	}
// 	return 0;
// }






// #include <iostream>
// #include <queue>
// #include <string>
// #include <set>
// 
// using namespace std;
// 
// struct node
// {
// 	string mp;
// 	int num;
// };
// 
// int N;
// 
// void print(const string& mp)
// {
// 	int index = 0;
// 	cout << endl;
// 	for(int i = 0; i < N; ++i)
// 	{
// 		for(int j = 0; j < N; ++j)
// 		{
// 			cout << mp[index];
// 			++index;
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }
// 
// 
// int getIndex(int r, int v)
// {
// 	return r * N + v;
// }
// 
// int getRow(int n)
// {
// 	return n / N;
// }
// 
// int getCol(int n)
// {
// 	return n % N;
// }
// 
// int isSuccess(const string& mp)
// {
// 	for(int i = 0; i < mp.size(); ++i)
// 	{
// 		if(mp[i] == '.')
// 		{
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
// 
// int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
// 
// struct point 
// {
// 	int r,v;
// };
// 
// int visit[305][305] = {0};
// 
// void testClick(string& mp, int index)
// {
// 	point pt;
// 	pt.r = getRow(index);
// 	pt.v = getCol(index);
// 	queue<point> q;
// 	queue<point> q1;
// 	q.push(pt);
// 
// 	int i;
// 	memset(visit, 0, sizeof(visit));
// 	visit[pt.r][pt.v] = 1;
// 
// 	mp[index] = '0';
// 	//print(mp);
// 	while(q.empty() == 0)
// 	{
// 		pt = q.front();  q.pop();
// 
// 		if(pt.r == 2 && pt.v == 1)
// 		{
// 			int a = 1;
// 		}
// 		for(i = 0; i < 8; ++i)
// 		{
// 			point pt1 = pt;
// 			pt1.r += dir[i][0];
// 			pt1.v += dir[i][1];
// 			if(pt1.r < 0 || pt1.v < 0 || pt1.r >= N || pt1.v >= N)
// 			{
// 				continue;
// 			}
// 
// 			if(mp[getIndex(pt1.r, pt1.v)] == '*')
// 			{
// 				break;
// 			}
// 
// 			if(visit[pt1.r][pt1.v] == 1)
// 			{
// 				continue;
// 			}
// 
// 			visit[pt1.r][pt1.v] = 1;
// 
// 			if(pt1.r == 2 && pt1.v == 2)
// 			{
// 				int a = 1;
// 			}
// 
// 			q1.push(pt1);
// 		}
// 
// 		if(i == 8)
// 		{
// 			while(q1.empty() == 0)
// 			{
// 				q.push(q1.front());
// 				mp[getIndex(q1.front().r, q1.front().v)] = '0';
// 				q1.pop();
// 			}
// 		}
// 		else
// 		{
// 			while(q1.empty() == 0) 
// 			{
// 				q1.pop();
// 			}
// 		}
// 	}
// }
// 
// int bfs(const string& mp)
// {
// 	node nd;
// 	nd.mp = mp;
// 	nd.num = 0;
// 
// 	queue<node> q;
// 	q.push(nd);
// 
// 	set<string> status;
// 	status.insert(mp);
// 
// 	while(q.empty() == 0)
// 	{
// 		nd = q.front();   q.pop();
// 		if(isSuccess(nd.mp))
// 		{
// 			return nd.num;
// 		}
// 
// 		for(int i = 0; i < nd.mp.size(); ++i)
// 		{
// 			if(nd.mp[i] == '.')
// 			{
// 				//²âÊÔµã»÷
// 				node nd1 = nd;
// 				testClick(nd1.mp, i);
// 				++nd1.num;
// 				if(status.find(nd1.mp) == status.end())
// 				{
// 					//print(nd1.mp);
// 					status.insert(nd1.mp);
// 					q.push(nd1);
// 				}
// 			}
// 		}
// 	}
// 	return -1;
// }
// 
// 
// int main()
// {
// 	//freopen("a.in", "rb", stdin);
// 	int nCase;
// 	cin >> nCase;
// 	for(int i = 1; i <= nCase; ++i)
// 	{
// 		cout << i << endl;
// 		string mp, str;
// 		cin >> N;
// 		for(int j = 1; j <= N; ++j)
// 		{
// 			cin >> str;
// 			mp += str;
// 		}
// 
// 		printf("Case #%d: %d\n",i, bfs(mp));
// 	}
// 	return 0;
// }



#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

struct node
{
	string mp;
	int num;
};

int N;

void print(const string& mp)
{
	int index = 0;
	cout << endl;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << mp[index];
			++index;
		}
		cout << endl;
	}
	cout << endl;
}


int getIndex(int r, int v)
{
	return r * N + v;
}

int getRow(int n)
{
	return n / N;
}

int getCol(int n)
{
	return n % N;
}

int isSuccess(const string& mp)
{
	for(int i = 0; i < mp.size(); ++i)
	{
		if(mp[i] == '.')
		{
			return 0;
		}
	}
	return 1;
}

int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

struct point 
{
	int r,v;
};

int visit[305][305] = {0};

int testClick(string& mp, int index)
{
	point pt;
	pt.r = getRow(index);
	pt.v = getCol(index);
	queue<point> q;
	queue<point> q1;
	q.push(pt);

	int i;
	memset(visit, 0, sizeof(visit));
	visit[pt.r][pt.v] = 1;

	mp[index] = '0';
	//print(mp);
	int res = 1;
	while(q.empty() == 0)
	{
		pt = q.front();  q.pop();

		for(i = 0; i < 8; ++i)
		{
			point pt1 = pt;
			pt1.r += dir[i][0];
			pt1.v += dir[i][1];
			if(pt1.r < 0 || pt1.v < 0 || pt1.r >= N || pt1.v >= N)
			{
				continue;
			}

			if(mp[getIndex(pt1.r, pt1.v)] == '*')
			{
				break;
			}

			if(mp[getIndex(pt1.r, pt1.v)] == '0')
			{
				continue;;
			}

			// 			if(visit[pt1.r][pt1.v] == 1)
			// 			{
			// 				continue;
			// 			}
			// 
			// 			visit[pt1.r][pt1.v] = 1;

			q1.push(pt1);
		}

		if(i == 8)
		{
			res += q1.size();
			while(q1.empty() == 0)
			{
				q.push(q1.front());
				mp[getIndex(q1.front().r, q1.front().v)] = '0';
				q1.pop();
			}
		}
		else
		{
			while(q1.empty() == 0) 
			{
				q1.pop();
			}
		}
	}

	return res;
}

int getRes(string& mp)
{
	int num = 0;
	string tmp = mp;
	for(int i = 0; i < tmp.size(); ++i)
	{
		if(tmp[i] == '*')
		{
			point pt;
			pt.r = getRow(i);
			pt.v = getCol(i);

			for(int j = 0; j < 8; ++j)
			{
				point pt1 = pt;
				pt1.r += dir[j][0];
				pt1.v += dir[j][1];

				if(pt1.r < 0 || pt1.v < 0 || pt1.r >= N || pt1.v >= N)
				{
					continue;
				}

				if(tmp[getIndex(pt1.r, pt1.v)] == '.')
				{
					tmp[getIndex(pt1.r, pt1.v)] = '1';
				}
			}
		}
	}

	//print(tmp);
	queue<int> q;
	for(int i = 0; i < tmp.size(); ++i)
	{
		if(tmp[i] == '.')
		{
			q.push(i);
		}
	}

	while(q.empty() == 0)
	{
		if(mp[q.front()] == '.')
		{
			testClick(mp, q.front());
			//print(mp);
			++num;
		}
		q.pop();
	}


	for(int i = 0; i < mp.size(); ++i)
	{
		if(mp[i] == '.')
		{
			++num;
		}
	}

	return num;
}

/*
10
..*.....*.
.........*
..........
..........
..........
..........
....*.....
..........
..........
**........
*/
int main()
{
	freopen("a.in", "rb", stdin);
	freopen("a.out", "wb", stdout);
	int nCase;
	cin >> nCase;
	for(int i = 1; i <= nCase; ++i)
	{
		//cout << i << endl;
		string mp, str;
		cin >> N;
		for(int j = 1; j <= N; ++j)
		{
			cin >> str;
			mp += str;
		}

		printf("Case #%d: %d\n",i, getRes(mp)); 
		//printf("Case #%d: %d\n",i, bfs(mp));
	}
	return 0;
}