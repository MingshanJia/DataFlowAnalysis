#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int A,B,alpha,beta;
long long Y;

int decom_a,decom_b;
int prev_a,prev_b;

void day0(){
	decom_a = A/100;
	decom_b = B/100;
}
void day1(){
	int baby = 2*min(A,B)/100;
	int a = baby*alpha/100;
	int b = baby*beta/100;
	int c = baby-a-b;
	a+=c/2;
	b+=(c+1)/2;
	A+=a;
	B+=b;
}
void day2(){
	A-=decom_a;
	B-=decom_b;
}

void go(){
	cin>>A>>B>>alpha>>beta>>Y;
	for(int i=0;i<Y;++i){
 		prev_a=A;
		prev_b=B;
		day0();
		day1();
		day2();
		if(A==prev_a&&B==prev_b){
			break;
		}
	}
	printf("%d %d\n", A,B);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;++i){
		printf("Case #%d: ", i);
		go();
	}
}
