#include <stdio.h>
#include <string.h>

char a[307], b[307], c[307];
char ta[307], tb[307], tc[307];
char resa[307], resb[307], resc[307];
char opa;
int lena, lenb, lenc;
bool retflag;

long long char_to_num(char *str)
{
	int i;
	long long val = 0;
	for(i = 0; i < strlen(str); i++)
		val = val*10 + str[i]-'0';
	
	return val;
}

bool check(void)
{
	long long numa, numb, numc;
	numa = char_to_num(ta);
	numb = char_to_num(tb);
	numc = char_to_num(tc);
	if(opa == '+')
	{
		if(numa + numb == numc) 
		{
			retflag = true;
			strcpy(resa, ta); strcpy(resb, tb); strcpy(resc, tc);
		}
	}
	else
	{
		if(numa - numb == numc) 
		{
			retflag = true;
			strcpy(resa, ta); strcpy(resb, tb); strcpy(resc, tc);
		}
	}
	return false;
}

void dfs(int seqn, int now)
{
	if(retflag) return;
	if(seqn == 0 && now == lena)
	{
		dfs(1, 0);
		return;
	}
	if(seqn == 1 && now == lenb)
	{
		dfs(2, 0);
		return;
	}
	if(seqn == 2 && now == lenc)
	{
		check();
		return;
	}

	char i;
	if(seqn == 0)
	{
		if(a[now] != '?') 
		{
			ta[now] = a[now];
			dfs(seqn, now+1);
			return;
		}
		for(i = '0' + ((now == 0 && lena>1) ? 1 : 0); i <= '9'; i++)
		{
			ta[now] = i;
			dfs(seqn, now+1);
		}
	}
	else if(seqn == 1)
	{
		if(b[now] != '?') 
		{
			tb[now] = b[now];
			dfs(seqn, now+1);
			return;
		}
		for(i = '0' + ((now == 0 && lenb>1) ? 1 : 0); i <= '9'; i++)
		{
			tb[now] = i;
			dfs(seqn, now+1);
		}
	}
	else
	{
		if(c[now] != '?') 
		{
			tc[now] = c[now];
			dfs(seqn, now+1);
			return;
		}
		for(i = '0' + ((now == 0 && lenc>1) ? 1 : 0); i <= '9'; i++)
		{
			tc[now] = i;
			dfs(seqn, now+1);
		}
	}
}

int main(void)
{
	int t, tl, i;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(tl = 1; tl <= t; tl++)
	{
		scanf("%s %c %s = %s",a, &opa, b, c);
		lena = strlen(a);
		lenb = strlen(b);
		lenc = strlen(c);
		for(i = 0; i < 20; i++)
			ta[i] = 0;
		for(i = 0; i < 20; i++)
			tb[i] = 0;
		for(i = 0; i < 20; i++)
			tc[i] = 0;
		retflag = false;
		dfs(0, 0);
		printf("Case #%d: %s %c %s = %s\n", tl, resa, opa, resb, resc);
	}
	
	return 0;
}