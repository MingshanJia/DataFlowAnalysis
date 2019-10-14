#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string name[] = 
{
	"zero",
	"one",
	"double",
	"triple",
	"quadruple",
	"quintuple",
	"sextuple",
	"septuple",
	"octuple",
	"nonuple",
	"decuple",
};

string number[] = 
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int main()
{
	int T;
	cin >> T;
	string phone,format;
	for(int c=1; c<=T; c++)
	{
		cin >> phone >> format;
		cout << "Case #" << c << ":";
		int pointer = 0;
		stringstream sin(format);
		int num;
		char s;
		while(sin >> num)
		{
			sin >> s;
			int count = 0;
			char pre = '-';
			for(int i=pointer,j=0;j<num;j++,i++)
			{
				if(phone[i] == pre)
				{
					count++;
				}
				else if(pre != '-')
				{
					if(count == 1 || count > 10)
					{
						for(int k=0;k<count;k++)
						{
							cout << " " << number[pre-'0'];
						}
					}
					else
					{
						cout << " " << name[count] << " " << number[pre-'0'];
					}
					count = 1;
					pre = phone[i];
				}
				else
				{
					pre = phone[i];
					count = 1;
				}
				pointer = i+1;
			}
			if(count == 1 || count > 10)
			{
				for(int k=0;k<count;k++)
				{
					cout << " " << number[pre-'0'];
				}
			}
			else
			{
				cout << " " << name[count] << " " << number[pre-'0'];
			}
		}
		cout << endl;
	}
}