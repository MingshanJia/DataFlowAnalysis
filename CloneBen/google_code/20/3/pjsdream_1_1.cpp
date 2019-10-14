#include <string.h>
#include <stdio.h>

char num1[300], num2[300], num3[300], op[4], eq[4];

char temp[300];
void strswap(char *a, char *b) {
	strcpy(temp, a); strcpy(a, b); strcpy(b, temp);
}

void shift(char *num)
{
	int i, j;
	for (i=strlen(num)-1, j=250; i>=0; i--, j--)
		temp[j] = num[i]=='?' ? 10 : num[i]-'0';
	for (; j>=0; j--) temp[j] = -1;
	for (i=0; i<=250; i++) num[i] = temp[i];
}

int range1[300][2], range2[300][2], range3[300][2];
int rangesum[300][2];

void getrange(char *num, int range[][2])
{
	int i;

	for (i=0; i<=250 && num[i]==-1; i++) range[i][0] = range[i][1] = 0;
	if (i<250) {
		if (num[i]==10) range[i][0] = 1, range[i][1] = 9;
		else range[i][0] = range[i][1] = num[i];
	}
	else {
		if (num[i]==10) range[i][0] = 0, range[i][1] = 9;
		else range[i][0] = range[i][1] = num[i];
	}

	for (i++; i<=250; i++) {
		if (num[i]==10) range[i][0] = 0, range[i][1] = 9;
		else range[i][0] = range[i][1] = num[i];
	}
}

bool dynamic[300][2];
bool is_possible()
{
	int i;

	getrange(num1, range1);
	getrange(num2, range2);
	getrange(num3, range3);

	for (i=250; i>=0; i--) {
		rangesum[i][0] = range1[i][0] + range2[i][0];
		rangesum[i][1] = range1[i][1] + range2[i][1];
	}

	dynamic[251][0] = true, dynamic[251][1] = false;
	for (i=250; i>=0; i--) {
		int a, b;

		dynamic[i][0] = dynamic[i][1] = false;

		if (dynamic[i+1][0]) {
			for (a=rangesum[i][0]; a<=rangesum[i][1]; a++) for (b=range3[i][0]; b<=range3[i][1]; b++) {
				if (a%10 == b) {
					if (a < 10) dynamic[i][0] = true;
					else dynamic[i][1] = true;
				}
			}
		}
		if (dynamic[i+1][1]) {
			for (a=rangesum[i][0]; a<=rangesum[i][1]; a++) for (b=range3[i][0]; b<=range3[i][1]; b++) {
				if ((a+1)%10 == b) {
					if (a+1 < 10) dynamic[i][0] = true;
					else dynamic[i][1] = true;
				}
			}
		}
	}

	return dynamic[0][0];
}

void print_num(char *num) {
	int i;
	for (i=0; i<=250 && num[i]==-1; i++) ;
	for (; i<=250; i++) printf("%c", num[i]+'0');
}

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);

	while (t--) {
		scanf("%s %s %s %s %s", num1, op, num2, eq, num3);
		
		if (op[0] == '-')
			strswap(num1, num3);

		shift(num1);
		shift(num2);
		shift(num3);

		if (op[0] == '-') {
			// num1 + num2 = num3
			// num3 -> num2 -> num1

			bool first = true;
			for (i=0; i<=250; i++) if (num3[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num3[i] == 10) {
					for (; j<=9; j++) {
						num3[i] = j;
						if (is_possible()) break;
					}
				}
			}
			first = true;
			for (i=0; i<=250; i++) if (num2[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num2[i] == 10) {
					for (; j<=9; j++) {
						num2[i] = j;
						if (is_possible()) break;
					}
				}
			}
			first = true;
			for (i=0; i<=250; i++) if (num1[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num1[i] == 10) {
					for (; j<=9; j++) {
						num1[i] = j;
						if (is_possible()) break;
					}
				}
			}
		}
		else {
			// num1 + num2 = num3
			// num1 -> num2 -> num3

			
			bool first = true;
			for (i=0; i<=250; i++) if (num1[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num1[i] == 10) {
					for (; j<=9; j++) {
						num1[i] = j;
						if (is_possible()) break;
					}
				}
			}
			first = true;
			for (i=0; i<=250; i++) if (num2[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num2[i] == 10) {
					for (; j<=9; j++) {
						num2[i] = j;
						if (is_possible()) break;
					}
				}
			}
			first = true;
			for (i=0; i<=250; i++) if (num3[i] != -1) {
				if (first && i<250) j=1; else j=0;
				first = false;
				if (num3[i] == 10) {
					for (; j<=9; j++) {
						num3[i] = j;
						if (is_possible()) break;
					}
				}
			}
		}

		printf("Case #%d: ", ++tt);

		if (op[0] == '+') {
			print_num(num1);
			printf(" + ");
			print_num(num2);
			printf(" = ");
			print_num(num3);
			printf("\n");
		}
		else {
			print_num(num3);
			printf(" - ");
			print_num(num2);
			printf(" = ");
			print_num(num1);
			printf("\n");
		}
	}

	return 0;
}
