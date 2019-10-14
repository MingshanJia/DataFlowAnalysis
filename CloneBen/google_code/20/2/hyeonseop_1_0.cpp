#pragma warning(disable:4996)

#include <iostream>

#define L (250 + 10)

int tc;
int n1, n2, n3;

char pm;

char num1[L] = {0, };
char num2[L] = {0, };
char num3[L] = {0, };
char res[L] = {0, };

void input(){
	scanf("%s %c %s %*c %s", num1, &pm, num2, num3);
}

bool check(){
	int i;
	if(pm == '+'){
		for(i = 0; i < n3; i++){
			res[i] = num3[i] - '0';
		}
		for(i = 0; i < n1; i++){
			res[n3 - n1 + i] -= num1[i] - '0';
		}
		for(i = 0; i < n2; i++){
			res[n3 - n2 + i] -= num2[i] - '0';
		}
		for(i = n3 - 1; 0 < i; i--){
			if(res[i] == -10){
				res[i - 1]--;
				res[i] = 0;
			}
			if(res[i] != 0){
				return false;
			}
		}
		if(res[0] != 0){
			return false;
		}
	}
	else{
		for(i = 0; i < n1; i++){
			res[i] = num1[i] - '0';
		}
		for(i = 0; i < n3; i++){
			res[n1 - n3 + i] -= num3[i] - '0';
		}
		for(i = 0; i < n2; i++){
			res[n1 - n2 + i] -= num2[i] - '0';
		}
		for(i = n1 - 1; 0 < i; i--){
			if(res[i] == -10){
				res[i - 1]--;
				res[i] = 0;
			}
			if(res[i] != 0){
				return false;
			}
		}
		if(res[0] != 0){
			return false;
		}
	}
	return true;
}

bool back3(int i){
	int j, t;
	for(; num3[i] != '?' && num3[i] != '\0'; i++);
	if(num3[i] == '\0'){
		return check();
	}
	t = n3 - i;
	for(j = 0; j < 10; j++){
		if(i == 0 && j == 0 && n3 != 1){
			continue;
		}
		num3[i] = j + '0';
		if(pm == '+'){
			if(((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != (((n3 < t) ? '0' : num3[n3 - t]) - '0') && ((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != ((((n3 < t) ? '0' : num3[n3 - t]) - '0' + 9) % 10)){
				continue;
			}
		}
		else{
			if(((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0') && ((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0' + 9) % 10){
				continue;
			}
		}
		if(back3(i + 1)){
			return true;
		}
	}
	num3[i] = '?';
	return false;
}

bool back2(int i){
	int j, t;
	for(; num2[i] != '?' && num2[i] != '\0'; i++);
	if(num2[i] == '\0'){
		return back3(0);
	}
	t = n2 - i;
	for(j = 0; j < 10; j++){
		if(i == 0 && j == 0 && n2 != 1){
			continue;
		}
		num2[i] = j + '0';
		if(((n3 < t) ? '0' : num3[n3 - t]) != '?'){
			if(pm == '+'){
				if(((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != (((n3 < t) ? '0' : num3[n3 - t]) - '0') && ((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != ((((n3 < t) ? '0' : num3[n3 - t]) - '0' + 9) % 10)){
					continue;
				}
			}
			else{
				if(((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0') && ((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0' + 9) % 10){
					continue;
				}
			}
		}
		if(back2(i + 1)){
			return true;
		}
	}
	num2[i] = '?';
	return false;
}

bool back1(int i){
	int j, t;
	for(; num1[i] != '?' && num1[i] != '\0'; i++);
	if(num1[i] == '\0'){
		return back2(0);
	}
	t = n1 - i;
	for(j = 0; j < 10; j++){
		if(i == 0 && j == 0 && n1 != 1){
			continue;
		}
		num1[i] = j + '0';
		if(((n2 < t) ? '0' : num2[n2 - t]) != '?' && ((n3 < t) ? '0' : num3[n3 - t]) != '?'){
			if(pm == '+'){
				if(((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != (((n3 < t) ? '0' : num3[n3 - t]) - '0') && ((((n1 < t) ? '0' : num1[n1 - t]) - '0') + (((n2 < t) ? '0' : num2[n2 - t]) - '0')) % 10 != ((((n3 < t) ? '0' : num3[n3 - t]) - '0' + 9) % 10)){
					continue;
				}
			}
			else{
				if(((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0') && ((((n2 < t) ? '0' : num2[n2 - t]) - '0') + (((n3 < t) ? '0' : num3[n3 - t]) - '0')) % 10 != (((n1 < t) ? '0' : num1[n1 - t]) - '0' + 9) % 10){
					continue;
				}
			}
		}
		if(back1(i + 1)){
			return true;
		}
	}
	num1[i] = '?';
	return false;
}

void process(){
	n1 = strlen(num1);
	n2 = strlen(num2);
	n3 = strlen(num3);
	back1(0);
}

void output(){
	printf("Case #%d: %s %c %s = %s\n", tc, num1, pm, num2, num3);
}

int main(){
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(tc = 1; tc <= t; tc++){
		input();
		process();
		output();
	}
	return 0;
}