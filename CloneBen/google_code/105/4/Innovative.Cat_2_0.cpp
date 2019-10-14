#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string.h>
#include <math.h>

/*
�������߾��ȿ�  ԭ��Sillybird���ı�Innovative Cat.
v2.0(2005.06.05) ���ӿ��ٸ߾��ȳ�������
v2.1(2005.06.18) �޸ĸ߾��ȳ������ڽ��=0ʱ��len<=0��bug��
v2.2(2006.03.19) ����int*bignum�����أ�����static toInt����
v3.0(2006.03.19) ���ӿ��ٳ˷�O(n^1.5)���㷨���Ҿ�����̬����ռ��ˣ����Ǻ���
�����������΢�Ĵ������������ݣ������ڲο���
*/

class bignum{
enum{defaultmaxlen=1000,defaultlimit=10};
public:
int width;
int len;
unsigned int* data;
int limit;
int maxlen;
public:
bignum();
bignum(int Maxlen,int Limit,int 
a=0);//MaxlenΪ�߾��������λ��,LimitΪÿһλ������������
           //Ҳ����һ����������Limit�����½���
           //aΪ��ʼʱ�ø߾�������ֵ���ò����ǿ�ѡ����
bignum(int Maxlen,int Limit,char 
*s);//s��һ���ַ��������Ƕ�һ���߾�������ʼ������һ�ַ�ʽ��
           //����bignum a=(10,10,"123456789000");
bignum(const bignum& a);             //�������캯��
~bignum();        //��������

bignum& operator=(const bignum& b);  //���ظ�ֵ������
bignum& operator=(const char* s);    
//���ظ�ֵ�����������Խ�һ���ַ���ֱ�Ӹ�ֵ��bignum
bignum& operator=(const int a);      
//���ظ�ֵ�����������Խ�һ������ֱ�Ӹ�ֵ��bignum
static int toInt(const bignum& b);
//���ظ�ֵ�����������Խ�һ��bignumֱ�Ӹ�ֵ��������������Խ��

friend ostream& operator<<(ostream& os,const bignum& 
a);//���ز����<<,��ӡ�߾�����������osΪһ�������������cout
friend istream& operator>>(istream& is,bignum& a);//���������>>

void div(bignum &a, bignum &b);
// ���ٸ߾��ȳ�������*this=a/b, a=a%b. �������b����Ϣ��仯��
static bignum slowmulti(const bignum &a, const bignum &b);
// ��ͨ��n^2�ĳ˷���
static bignum quickmulti(const bignum &a, const bignum &b);
// n^1.5�Ŀ��ٳ˷��������bignum��û����ȫ��newΪmaxlen�ĳ��ȣ������Ӷ������⣩

friend const bignum operator+(const bignum& a,const bignum& b);
friend const bignum operator-(const bignum& a,const bignum& b);
friend const bignum operator*(const bignum& a,const bignum& b);
friend const bignum operator/(const bignum& a,const bignum& b);
friend const bignum operator%(const bignum& a,const bignum& b);
friend const bignum operator+(const bignum& a,const int b);
friend const bignum operator-(const bignum& a,const int b);
friend const bignum operator*(const bignum& a,const int b);
friend const bignum operator/(const bignum& a,const int b);
friend const int operator%(const bignum& a,const int b);
friend const bignum operator+(const int b,const bignum& a);
friend const bignum operator-(const int b,const bignum& a);
friend const bignum operator*(const int b,const bignum& a);
friend const int operator/(const int b,const bignum& a);
friend const int operator%(const int b, const bignum& a);

friend bignum& operator+=(bignum& a,const bignum& b);
friend bignum& operator-=(bignum& a,const bignum& b);
friend bignum& operator*=(bignum& a,const bignum& b);
friend bignum& operator/=(bignum& a,const bignum& b);
friend bignum& operator%=(bignum& a,const bignum& b);
friend bignum& operator+=(bignum& a,const int b);
friend bignum& operator-=(bignum& a,const int b);
friend bignum& operator*=(bignum& a,const int b);
friend bignum& operator/=(bignum& a,const int b);
friend bignum& operator%=(bignum& a,const int b);

friend int cmp(const bignum& a,const bignum& b);

friend bool operator>(const bignum& a,const bignum& b);
friend bool operator<(const bignum& a,const bignum& b);
friend bool operator>=(const bignum& a,const bignum& b);
friend bool operator<=(const bignum& a,const bignum& b);
friend bool operator==(const bignum& a,const bignum& b);
friend bool operator!=(const bignum& a,const bignum& b);

friend bool operator>(const bignum& a,const int b);
friend bool operator<(const bignum& a,const int b);
friend bool operator>=(const bignum& a,const int b);
friend bool operator<=(const bignum& a,const int b);
friend bool operator==(const bignum& a,const int b);
friend bool operator!=(const bignum& a,const int b);

friend bool operator>(const int a,const bignum& b);
friend bool operator<(const int a,const bignum& b);
friend bool operator>=(const int a,const bignum& b);
friend bool operator<=(const int a,const bignum& b);
friend bool operator==(const int a,const bignum& b);
friend bool operator!=(const int a,const bignum& b);
};

bignum::bignum(){
maxlen=defaultmaxlen;
limit=defaultlimit;
width=0;
int k=limit;
while (k)
  width++,k/=10;
width--;
data=new unsigned int[maxlen+1];
memset(data, 0, sizeof(int) * (maxlen + 1));
*this=0;
}

bignum::bignum(int Maxlen,int Limit,int a){
maxlen=Maxlen;
limit=Limit;
width=0;
int k=limit;
while (k)
  width++,k/=10;
width--;
data=new unsigned int[Maxlen+1];
memset(data, 0, sizeof(int) * (maxlen + 1));
*this=a;
}

bignum::bignum(int Maxlen,int Limit,char *s){
maxlen=Maxlen;
limit=Limit;
width=0;
int k=limit;
while (k)
  width++,k/=10;
width--;
data=new unsigned int[Maxlen+1];
memset(data, 0, sizeof(int) * (maxlen + 1));
*this=s;
}

bignum::bignum(const bignum &a){
maxlen=a.maxlen;
limit=a.limit;
width=a.width;
len=a.len;
data=new unsigned int[maxlen+1];
memcpy(data,a.data, sizeof(int) * (maxlen + 1));
}

bignum::~bignum(){
delete[] data;
}

bignum& bignum::operator=(const bignum& a){
maxlen=a.maxlen;
limit=a.limit;
width=a.width;
len=a.len;
memcpy(data,a.data, sizeof(int) * (maxlen + 1));
return *this;
}

bignum& bignum::operator=(const char* s){
memset(data,0,sizeof(int) * (maxlen + 1));
int length=int(strlen(s));
int k=int(s[length-1])-48;
len=0;
for (int i=length-2;i>=0;i--){
  k=(int(s[i])-48)*int(pow((double)10,(length-1-i-1)%width+1))+k;
  if ((length-1-i-1)%width+1==width){
   data[++len]=k%limit;
   k/=limit;
  }
}
if (k || length==1)
  data[++len]=k;
return *this;
}

bignum& bignum::operator=(const int a){
memset(data, 0, sizeof(int) * (maxlen + 1));
int k=a;
len=0;
while (k){
  data[++len]=k%limit;
  k/=limit;
}
if (!len){
  len=1;
  data[1]=0;
}
return *this;
}

int bignum::toInt (const bignum &b){
int a=0;
for (int i=0; i<b.len; i++)
  a = a*b.limit+b.data[i];
return a;
}

ostream& operator<<(ostream& os,const bignum& a){
//���ز����<<,��ӡ�߾�����������osΪһ�������������cout
os<<a.data[a.len];
for (int i=a.len-1;i;i--)
  os<<setfill('0')<<setw(a.width)<<a.data[i];
return os;
}

istream& operator>>(istream& is,bignum& a){//���������>>
char *s=new char[a.maxlen*a.width+1];
is>>s;
a=s;
return is;
}

const bignum operator+(const bignum& a,const bignum& b){
bignum c(a.maxlen,a.limit);
c.len=a.len>b.len? a.len:b.len;
int tmp,g=0;
for (int i=1;i<=c.len;i++){
  if (i<=a.len)
   if (i<=b.len)
    tmp=a.data[i]+b.data[i]+g;
   else
    tmp=a.data[i]+g;
  else
   tmp=b.data[i]+g;
  c.data[i]=tmp%c.limit;
  g=tmp/c.limit;
}
if (g)
  c.data[++c.len]=g;
return c;
}

const bignum operator-(const bignum& a,const bignum& b){
bignum c(a);
int tmp,g=0;
for (int i=1;(i<=b.len || g);i++){
  tmp=(int)a.data[i]-(i>b.len?0:b.data[i])-g;
  if (tmp<0)
   g=1,tmp+=a.limit;
  else
   g=0;
  c.data[i]=tmp;
}
while (c.len>1 && !c.data[c.len]) c.len--;
return c;
}

bignum bignum::slowmulti(const bignum &a, const bignum &b){
bignum c(a.len+b.len,a.limit);
c.len=a.len+b.len;
for (int i=1;i<=a.len;i++){
  int g=0;
  for (int j=1;j<=b.len+1;j++){
   c.data[i+j-1]+=g+a.data[i]*b.data[j];
   g=c.data[i+j-1]/c.limit;
   c.data[i+j-1]%=c.limit;
  }
}
while (c.len>1 && !c.data[c.len]) c.len--;
return c;
}
bignum bignum::quickmulti(const bignum &a, const bignum &b){
if (a.len<350||b.len<350) return slowmulti(a,b);
bignum c(a.len+b.len,a.limit); c.len = a.len+b.len;
int totsize=a.len>b.len?a.len:b.len, size, i;
size = totsize>>1;
bignum x1(size+2,a.limit), y1(size+2,a.limit);
bignum x2(size+2,a.limit), y2(size+2,a.limit);
for (i=1; i<=size; i++) y1.data[i] = a.data[i]; y1.len = size;
for (i=size+1; i<=a.len; i++) x1.data[i-size] = a.data[i]; x1.len = a.len-size;
for (i=1; i<=size; i++) y2.data[i] = b.data[i]; y2.len = size;
for (i=size+1; i<=b.len; i++) x2.data[i-size] = b.data[i]; x2.len = b.len-size;
bignum hi, lo = quickmulti(y1,y2);
if (x1==0||x2==0) hi = 0; else hi = quickmulti(x1,x2);
bignum mi = quickmulti(x1+y1, x2+y2)-lo-hi;
for (i=1; i<=lo.len; i++) c.data[i] = lo.data[i];
for (i=size+1; i<=size+mi.len; i++) c.data[i] += mi.data[i-size];
for (i=size+size+1; i<=size+size+hi.len; i++) c.data[i] += hi.data[i-size-size];
for (i=1; i<c.len; i++)
  while (c.data[i]>=(unsigned int)c.limit)
    c.data[i+1]++, c.data[i]-=c.limit;
while (c.len>1 && !c.data[c.len]) c.len--;
return c;
}
const bignum operator*(const bignum& a,const bignum& b){
bignum res(a.maxlen, a.limit);
bignum tmp = bignum::quickmulti(a,b);
for (int i=1; i<=tmp.len; i++)
  res.data[i] = tmp.data[i];
res.len = tmp.len;
return res;
}

void bignum::div(bignum &a, bignum &b){
int i, j, d, m, n, qhat, rhat, carry;
bignum &c = *this;
c = 0;

if (b.len < 2) {
c = a/b.data[1];
a = a%b.data[1];
return;
}
m = a.len - b.len;
n = b.len;
d = c.limit/(b.data[n] + 1);
if (d > 1) a*=d, b*=d;
for (j = m; j >= 0 ; j--) {
	qhat = a.data[j+n+1] * c.limit + a.data[j+n];
	rhat = qhat % b.data[n];
	qhat = qhat / b.data[n];
	if (qhat == c.limit) {
	qhat = c.limit - 1;
	rhat = a.data[j+n] + b.data[n];
	}
	while (rhat < c.limit && qhat * b.data[n-1] > rhat*c.limit + a.data[j+n-1]) {
	qhat--;
	rhat += b.data[n];
	}
	carry = 0;
	for (i = 1; i <= n + 1; i++) {
	int tmp = a.data[j+i] + carry - qhat * b.data[i];
	carry  = tmp / c.limit;
	tmp %= c.limit;
	if (tmp < 0) {
		a.data[j+i] = tmp + c.limit;
		carry--;
	}
	else a.data[j+i] = tmp;
	}
	if (carry < 0) {
	qhat--;
	a.data[j+1]--;
	carry = 0;
	for (i = 1; i <= n + 1; i++) {
		int tmp = a.data[j+i] + carry + b.data[i] - c.limit + 1;
		if (tmp < 0) {
		a.data[j+i] = tmp + c.limit;
		carry = -1;
		} else {
		a.data[j+i] = tmp;
		carry = 0;
		}
	}
	}
	c.data[j+1] = qhat;
}
a.len = n;
a/=d;
while (a.len > 1 && a.data[a.len] == 0) a.len--;
c.len = m+1 > 1 ? m+1 : 1;
while (c.len > 1 && c.data[c.len] == 0) c.len--;
}

const bignum operator/(const bignum& a,const bignum& b){
bignum u(a), v(b), w(a.maxlen,a.limit);
w.div(u,v);
return w;
}

const bignum operator%(const bignum& a,const bignum& b){
bignum u(a), v(b), w(a.maxlen,a.limit);
w.div(u,v);
return u;
}

const bignum operator+(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a+B;
}

const bignum operator-(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a-B;
}

const bignum operator*(const bignum& a,const int b){
bignum c(a.maxlen,a.limit);
int tmp,g=0;
c.len=a.len;
for (int i=1;i<=c.len;i++){
  tmp=a.data[i]*b+g;
  c.data[i]=tmp%c.limit;
  g=tmp/c.limit;
}
while (g){
  c.data[++c.len]=g%c.limit;
  g/=c.limit;
}
return c;
}

const bignum operator/(const bignum& a,const int b){
bignum c(a.maxlen,a.limit);
int tmp,g=0;
for (int i=a.len;i;i--){
  tmp=g+a.data[i];
  c.data[i]=tmp/b;
  g=(tmp%b)*c.limit;
}
c.len=a.len;
while (c.len>1 && !c.data[c.len]) c.len--;
return c;
}

const int operator%(const bignum& a,const int b){
int tmp,g=0;
for (int i=a.len;i;i--){
  tmp=g+a.data[i];
  g=(tmp%b)*a.limit;
}
return g/a.limit;
}

const bignum operator+(const int b,const bignum& a){
return a+b;
}

const bignum operator-(const int b,const bignum& a){
bignum B(a.maxlen,a.limit,b);
return B-a;
}

const bignum operator*(const int b,const bignum& a){
return a*b;
}

const int operator/(const int b,const bignum& a){
bignum B(a.maxlen,a.limit,b);
return bignum::toInt(B/a);
}

const int operator%(const int b,const bignum& a){
bignum B(a.maxlen,a.limit,b);
return bignum::toInt(B%a);
}

bignum& operator+=(bignum &a,const bignum& b){
a=a+b;
return a;
}

bignum& operator-=(bignum& a,const bignum& b){
return a=a-b;
}

bignum& operator*=(bignum& a,const bignum& b){
return a=a*b;
}

bignum& operator/=(bignum& a,const bignum& b){
return a=a/b;
}

bignum& operator%=(bignum& a,const bignum& b){
return a=a%b;
}

bignum& operator+=(bignum &a,const int b){
return a=a+b;
}

bignum& operator-=(bignum& a,const int b){
return a=a-b;
}

bignum& operator*=(bignum& a,const int b){
return a=a*b;
}

bignum& operator/=(bignum& a,const int b){
return a=a/b;
}

bignum& operator%=(bignum& a,const int b){
return a=a%b;
}

int cmp(const bignum& a,const bignum& b){
if (a.len>b.len)
  return 1;
if (a.len<b.len)
  return -1;
for (int i=a.len;i;i--){
  if (a.data[i]>b.data[i])
   return 1;
  if (a.data[i]<b.data[i])
   return -1;
}
return 0;
}

bool operator>(const bignum& a,const bignum& b){
return cmp(a,b)==1;
}

bool operator<(const bignum& a,const bignum& b){
return cmp(a,b)==-1;
}

bool operator>=(const bignum& a,const bignum& b){
return cmp(a,b)>=0;
}

bool operator<=(const bignum& a,const bignum& b){
return cmp(a,b)<=0;
}

bool operator==(const bignum& a,const bignum& b){
return !cmp(a,b);
}

bool operator!=(const bignum& a,const bignum& b){
return cmp(a,b)!=0;
}

bool operator>(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a>B;
}

bool operator<(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a<B;
}

bool operator>=(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a>=B;
}

bool operator<=(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a<=B;
}

bool operator==(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a==B;
}

bool operator!=(const bignum& a,const int b){
bignum B(a.maxlen,a.limit,b);
return a!=B;
}

bool operator>(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
return A>b;
}

bool operator<(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
return A<b;
}

bool operator>=(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
return A>=b;
}

bool operator<=(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
return A<=b;
}

bool operator==(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
return A==b;
}

bool operator!=(const int a,const bignum& b){
bignum A(b.maxlen,b.limit,a);
        return A!=b;
}




struct signbignum
{
	char sign;
	bignum b;
};
signbignum operator * (signbignum a, bignum b)
{
	a.b *= b;
	return a;
}
signbignum operator + (signbignum a, signbignum b)
{
	if (b.sign==0)
		if (a.sign==0)
			a.b += b.b;
		else
			if (a.b<b.b) a.b = b.b-a.b, a.sign = 0;
			else a.b -= b.b;
	else
		if (a.sign==1)
			a.b += b.b;
		else
			if (a.b<b.b) a.b = b.b-a.b, a.sign = 1;
			else a.b -= b.b;
	return a;
}
signbignum operator - (signbignum a, signbignum b)
{
	b.sign = 1-b.sign;
	return a + b;
}



FILE *Fin = fopen("C-small-attempt1.in","r");
//FILE *Fin = stdin;
ofstream Fou("c.out");
//#define Fou cout

int n,m;
int n1[1000], n2[1000];

bignum C[200][200];
int main()
{
	int i,j,k,caseN,t;
	fscanf(Fin,"%d",&caseN);

	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for (i=2; i<=30; i++)
	{
		C[i][0] = 1;
		C[i][i] = 1;
		for (j=1; j<i; j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
	
		bignum sq5;
		sq5 = 2236067;
		sq5 = sq5 * 10000000+9774997;
		sq5 = sq5 * 10000000+8969640;
		sq5 = sq5 * 10000000+9173669;
	for (t=0; t<caseN; t++)
	{
		Fou<<"Case #"<<t+1<<": ";
		fscanf(Fin,"%d",&n);

		bignum a, b;
		for (i=0; i<=n; i++)
		{
			if (i%2==0)
			{
				bignum cur = C[n][i];
				for (j=0; j+j<i; j++)
					cur *= 5;
				for (j=0; j<n-i; j++)
					cur *= 3;
				a += cur;
			} else
			{
				bignum cur = C[n][i];
				for (j=0; j+j+1<i; j++)
					cur *= 5;
				for (j=0; j<n-i; j++)
					cur *= 3;
				b += cur;
			}
		}
		bignum aa;
		aa = b*sq5 + ((a*10000000)*10000000)*10000000*1000000;
		aa/=10000000;
		aa/=10000000;
		aa/=10000000;
		aa/=1000000;
		int res;
		res = aa%1000;
		if (res>=100)
			Fou<<res<<endl;
		else if (res>=10)
			Fou<<'0'<<res<<endl;
		else Fou<<"00"<<res<<endl;
	}
	return 0;
}

