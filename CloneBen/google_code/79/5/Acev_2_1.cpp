#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define MAX 32768

using namespace std;
FILE *in; FILE *out;

// =======================================
// BEGIN OF LONG NUMBER IMPLEMENTATION -->

class Long // Class for long numbers
{
    friend Long operator + (long long left, Long const& right);
    friend Long operator - (long long left, Long const& right);
    friend Long operator * (long long left, Long const& right);
    
    private:
        
        #define RADIX_DIGITS 9
        #define RADIX 1000000000

        #define DIGITS 4            // Actual number of stored decimal digits
                                    // is log10(RADIX) * DIGITS     
        #define POSITIVE 0
        #define NEGATIVE 1
    
        int len, size, sign;        // Real digits, allocated digits and sign
        int* num;                   // Pointer to the stored digits
        
        void expand(void)
        {
            int* temp = new int[size * 2];
            memset(temp, 0, sizeof(temp[0]) * size * 2);
            memcpy(temp, num, sizeof(num[0]) * size);
            delete [] num; num = temp; size *= 2;
        }
        void normalize(void) {while (len > 1 && num[len - 1] == 0) len--;}
        
        int compare(const int* rnum, const int rlen) const
        {
			if (len != rlen) return len - rlen;
			for (int i = len - 1; i >= 0; i--)
				if (num[i] != rnum[i]) return num[i] - rnum[i];
			return 0;
		}
        
        // Arithmetical operations
        void intAdd(int carry)
        {
        	for (int i = 0; carry > 0 && i < len; i++)
        	{
            	carry += num[i];
            	num[i] = carry % RADIX; carry /= RADIX;
        	}
        	while (carry)
        	{
            	if (len >= size) expand();
            	num[len++] = carry % RADIX; carry /= RADIX;
        	}
        }
        
        void intSub(int carry)
        {
        	for (int i = 0; carry > 0 && i < len; i++)
        	{
            	num[i] -= carry; carry = 0;
            	if (num[i] < 0) {num[i] += RADIX; carry++;}
        	}
			normalize();
        }
        
        void intMul(long long mul)
        {
            long long carry = 0;            
            for (int i=0; i<len; i++)
            {
                carry += mul * num[i];
                num[i] = carry % RADIX; carry /= RADIX;
            }
            while (carry)
            {
                if (len >= size) expand();
                num[len++] = carry % RADIX; carry /= RADIX;
            }
            normalize();
        }

        void intDiv(long long div)
        {
            long long carry = 0;
            for (int i = len - 1; i >= 0; i--)
            {
				carry = carry * RADIX + num[i];
				num[i] = carry / div; carry %= div;
			}
            normalize();
        }
        
        void intMod(long long mod)
        {
            long long carry = 0;
            for (int i = len - 1; i >= 0; i--)
            {
				carry = carry * RADIX + num[i];
                carry %= mod; num[i] = 0;
            }
            len = 1; num[0] = carry;
        }
        
        void longAdd(Long& a, Long const& b)
        {
            int carry = 0, idx = 0;
            while (a.size < b.len) a.expand();

            for (int i = 0; i < b.len; i++)
        	{
				carry += a.num[idx] + b.num[idx];
				a.num[idx++] = carry % RADIX; carry /= RADIX;
			}
			while (carry)
			{
				if (a.size <= idx) a.expand();
				carry += a.num[idx];
				a.num[idx++] = carry % RADIX; carry /= RADIX;
			}
			a.len = max(a.len, idx);
        }

        void longSub(Long& a, Long const& b)
        {
            int carry = 0;
            for (int i = 0; i < a.len; i++)
            {
				if (i < b.len) carry += b.num[i];
				else if (!carry) break;

				a.num[i] -= carry;
				carry = a.num[i] < 0 ? 1 : 0;
				a.num[i] += carry * RADIX;
			}
			a.normalize();
		}
        
		void longMul(Long& a, Long const& b)
		{
			Long res, temp;
			for (int i = 0; i < b.len; i++)
			{
				temp = a;
				temp.intMul(b.num[i]);
				
				temp.len += i;
				while (temp.size < temp.len) temp.expand();
				for (int c = temp.len - 1; c >= i; c--)
					temp.num[c] = temp.num[c - i];
				for (int c = 0; c < i; c++) temp.num[c] = 0;
				longAdd(res, temp);
			}
			res.normalize();
			res.sign = a.sign;
			a = res;
		}
		
		void longDiv(Long& a, Long const& b)
		{
            Long leftLim, rightLim;
            rightLim.len = max(a.len - b.len + 1, 1);
            while (rightLim.size < rightLim.len) rightLim.expand();
            rightLim.num[rightLim.len-1] = RADIX - 1;
			
            Long res, mid;
            while (leftLim <= rightLim)
            {
                mid = leftLim + rightLim;
				mid.intDiv(2);

                if (b * mid <= a)
                {
                    if (res < mid) res = mid;
                    leftLim = ++mid;
                }
                else rightLim = --mid;
            }
            res.sign = a.sign;
            a = res;
        }
        
        void longMod(Long& a, Long const& b)
        {
            Long temp(a);
            longDiv(temp, b);
            longMul(temp, b);
            longSub(a, temp);
        }
        
        void exp(Long& a, long long power)
        {
            Long mul(a); a = 1;            
            while (power)
            {
				if (power & 1) a *= mul;
				mul *= mul; power >>= 1;
			}
        }
        
        void sqRoot()
        {
            Long leftLim, rightLim(*this);
            Long mid, res;
            
            while (leftLim <= rightLim)
            {
                mid = leftLim + rightLim;
				mid.intDiv(2);

                if (mid * mid <= *this)
                {
                    if (res < mid) res = mid;
                    leftLim = ++mid;
                }
                else rightLim = --mid;
            }
            res.sign = sign;
            *this = res;
        }
        
    public:
        
        // Constructors:
            
        Long()                      // Default constructor
        {
            size = DIGITS;
            sign = POSITIVE;
            num = new int[size]; len = 1;
            memset(num, 0, sizeof(num[0]) * size);
        }
        
        Long(long long init)        // Constructor from integer
        {
            size = DIGITS;
            num = new int[size]; len = 0;
            memset(num, 0, sizeof(num[0]) * size);
            
            sign = init < 0 ? NEGATIVE : POSITIVE;
            init = init < 0 ? -init : init;

            do {num[len++] = init % RADIX; init /= RADIX;} while(init);
        }
        
        Long(string str)             // Constructor from string
        {
            sign = POSITIVE;
            if (str[0] == '-') {sign = NEGATIVE; str = str.substr(1);}

            size = max(DIGITS, (int)str.size() / RADIX_DIGITS + 1);
            num = new int[size]; len = 0;
            memset(num, 0, sizeof(num[0]) * size);
            
            for (int start = (int)str.size() - 1; start >= 0; start -= RADIX_DIGITS)
            {
				num[len] = 0;
				for (int i = min(start, RADIX_DIGITS - 1); i >= 0; i--)
					num[len] = num[len] * 10 + str[start-i] - 48;
				len++;
			}
			normalize();
        }
        
        Long(Long const& right)     // Copy constructor
        {
            len = right.len;
            size = right.size;
            sign = right.sign;

            num = new int[size];
            memcpy(num, right.num, sizeof(num[0]) * size);
        }
        
        // Destructor
        ~Long() {if (num != NULL) delete [] num;}
        
        // Operators
        Long& operator = (Long const& right)
        {
            if (this == &right) return *this;            
            if (num != NULL) delete [] num;
            
            len = right.len;
            size = right.size;
            sign = right.sign;

            num = new int[size];
            memcpy(num, right.num, sizeof(num[0]) * size);
            
            return *this;
        }
		
        Long& operator = (int init)
        {
			while (len > 0) num[--len] = 0;
            if (init < 0) {sign = NEGATIVE; init = -init;}
            else sign = POSITIVE;

            do {num[len++] = init % RADIX; init /= RADIX;} while(init);
            return *this;
		}

        Long& operator = (long long init)
        {
			while (len > 0) num[--len] = 0;
            if (init < 0) {sign = NEGATIVE; init = -init;}
            else sign = POSITIVE;

            do {num[len++] = init % RADIX; init /= RADIX;} while(init);
            return *this;
		}
		
		// Comparison operators
        bool operator < (Long const& right) const
        {
			if (sign != right.sign) return sign == NEGATIVE;			
			return sign == NEGATIVE ? compare(right.num, right.len) > 0 :
									  compare(right.num, right.len) < 0 ; 
		}

        bool operator >  (Long const& right) const {return right < *this;}
        bool operator >= (Long const& right) const {return !(right  > *this);}
        bool operator <= (Long const& right) const {return !(right  < *this);}
        bool operator != (Long const& right) const {return !(right == *this);}
        bool operator == (Long const& right) const
        	{return !((right < *this) || (*this < right));}
        
    	Long  operator ++ (int t) {Long res(*this); *this += 1; return res;}
    	Long  operator -- (int t) {Long res(*this); *this -= 1; return res;}
    	Long& operator ++ (void) {*this += 1; return *this;}
    	Long& operator -- (void) {*this -= 1; return *this;}

		Long& operator += (long long right)
		{
			long long absRight = right < 0 ? -right : right;
			if (absRight < RADIX)
			{
				int rsign = POSITIVE;
				if (right < 0) {right = -right; rsign = NEGATIVE;}

				if (sign == rsign) intAdd(right);
				else
				{
					if (len > 1 || num[0] >= right)
					{
						intSub(right);
						if (len == 1 && num[0] == 0) sign = POSITIVE;
					}
					else
					{
						sign = rsign;
						num[0] = right - num[0];
					}
				}
			}
			else
			{
				Long temp(right);
				if (sign == temp.sign) longAdd(*this, temp);
				else
				{
					if (compare(temp.num, temp.len) >= 0)
					{
						longSub(*this, temp);
						if (len == 1 && num[0] == 0) sign = POSITIVE;
					}
					else
					{
						sign = temp.sign;
						longSub(temp, *this); *this = temp;
					}
				}
			}
			return *this;
		}
    	Long& operator -= (long long right) {this->operator+=(-right); return *this;}

		Long& operator *= (long long right)
        {
			if (right < 0) {sign = !sign; right = -right;}
			
			if (right < RADIX) intMul(right);
			else longMul(*this, Long(right));			
			return *this;
		}
		
		Long& operator /= (long long right)
        {
			if (right < 0) {sign = !sign; right = -right;}
			
			if (right < RADIX) intDiv(right);
			else longDiv(*this, Long(right));
			return *this;
		}
    	
		Long& operator %= (long long right)
        {
			if (right < 0) {sign = !sign; right = -right;}
			
			if (right < RADIX) intMod(right);
			else longMod(*this, Long(right));
			return *this;
		}
    	
		Long& operator += (Long right)
		{
			if (sign == right.sign) longAdd(*this, right);
			else
			{
				if (compare(right.num, right.len) >= 0)
				{
					longSub(*this, right);
					if (len == 1 && num[0] == 0) sign = POSITIVE;
				}
				else
				{
					sign = right.sign;
					longSub(right, *this); *this = right;
				}
			}
			return *this;
		}

    	Long& operator -= (Long right)
    	{
			right.sign = !right.sign;
			this->operator+=(right); return *this;
		}
    	
		Long& operator *= (Long const& right)
        {
			sign = sign != right.sign ? NEGATIVE : POSITIVE;

			longMul(*this, right);
			if (len == 1 && num[0] == 0) sign = POSITIVE;
			return *this;
		}
		
		Long& operator /= (Long const& right)
		{
			sign = sign != right.sign ? NEGATIVE : POSITIVE;			

			longDiv(*this, right);
			if (len == 1 && num[0] == 0) sign = POSITIVE;
			return *this;
        }
           	
		Long& operator %= (Long const& right)
		{
			sign = sign != right.sign ? NEGATIVE : POSITIVE;			

			longMod(*this, right);
			if (len == 1 && num[0] == 0) sign = POSITIVE;
			return *this;
        }
        
        Long& operator ^= (long long right)
        {
            exp(*this, right);
            return *this;
        }

    	Long operator + (long long right) const
    	{
			Long ret(*this);
			ret += right; return ret;
		}
    	
    	Long operator - (long long right) const
    	{
			Long ret(*this);
			ret -= right; return ret;
		}

    	Long operator * (long long right) const
    	{
			Long ret(*this);
			ret *= right; return ret;
		}
    	
    	Long operator / (long long right) const
    	{
			Long ret(*this);
			ret /= right; return ret;
		}

    	Long operator % (long long right) const
    	{
			Long ret(*this);
			ret %= right; return ret;
		}
        
        Long operator ^ (long long right) const
        {
            Long ret(*this);
            ret ^= right; return ret;
        }
    	
    	Long operator + (Long const& right) const
    	{
			Long ret(*this);
			ret += right; return ret;
		}
    	
    	Long operator - (Long const& right) const
    	{
			Long ret(*this);
			ret -= right; return ret;
		}
    	
    	Long operator * (Long const& right) const
    	{
			Long ret(*this);
			ret *= right; return ret;
		}
    	
    	Long operator / (Long const& right) const
    	{
			Long ret(*this);
			ret /= right; return ret;
		}
		
		Long operator % (Long const& right) const
		{
            Long ret(*this);
            ret %= right; return ret;
        }
    	
    	int toInt() const {return num[0];}
    	string toString() const
    	{
			string ret;
			char buff[RADIX_DIGITS + 2];

			if (sign == NEGATIVE) ret = "-";
			sprintf(buff, "%d", num[len - 1]); ret += buff;
			for (int i = len - 2; i >= 0; i--)
				{sprintf(buff, "%09d", num[i]); ret += buff;}
			return ret;
		}

    	static Long sqrt(Long right)
    	{
            right.sqRoot(); return right;
        }
    	
}; // End of class Long


Long operator + (long long left, Long const& right) {return right + left;}
Long operator * (long long left, Long const& right) {return right * left;}
Long operator - (long long left, Long const& right) {return Long(left) - right;}

// <-- END OF LONG NUMBER IMPLEMENTATION
// =====================================


int n;
long long l, h;
long long a[MAX], gg[MAX];

long long parseLong()
{
	char buff[32];
	fscanf(in, "%s", buff);
	long long ret = 0;
	for (int i = 0; i < (int)strlen(buff); i++)
		ret = ret * 10 + buff[i] - 48;
	return ret;
}

string toString(long long num)
{
	if (num == 0) return "0";
	string ret;
	while (num) {ret.push_back(num % 10 + 48); num /= 10;}
	reverse(ret.begin(), ret.end());
	return ret;
}

long long gcd(long long a, long long b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

Long gcd(Long a, Long b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

Long lcm(Long a, Long b)
{
	return a * b / gcd(a, b);
}

void eval(int testNum)
{
	n = parseLong();
	l = parseLong();
	h = parseLong();
	for (int i = 0; i < n; i++)
		a[i] = parseLong();
	
	sort(a, a + n);
	gg[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		gg[i] = gcd(gg[i + 1], a[i]);
	
	if (l == 1)
		{fprintf(out, "1\n"); return;}
	
	long long tg = gg[0];
	vector < long long > divs;
	for (long long i = 1; i * i <= tg; i++) if (tg % i == 0)
	{
		divs.push_back(i);
		divs.push_back(tg / i);
	}
	sort(divs.begin(), divs.end());
	
	for (int i = 0; i < (int)divs.size(); i++)
		if (divs[i] >= l && divs[i] <= h)
			{fprintf(out, "%s\n", toString(divs[i]).c_str()); return;}
	
	/*
	10 8251 9901
	825 330 66 150 75 550 165 110 55 275
	*/
	
	Long g = 1LL;
	for (int i = 0; i < n; i++)
	{
		if (g > h) break;
		if (i > 0 && gg[i] != gg[i - 1])
		{
			divs.clear();
			for (long long d = 1; d * d <= gg[i]; d++) if (gg[i] % d == 0)
			{
				divs.push_back(d);
				divs.push_back(gg[i] / d);
			}
			sort(divs.begin(), divs.end());
			for (int i = 0; i < (int)divs.size(); i++)
				if (divs[i] >= l && divs[i] <= h && Long(divs[i]) % g == 0)
					{fprintf(out, "%s\n", toString(divs[i]).c_str()); return;}
		}
		g = lcm(g, a[i]);
	}
	
	if (g < l)
	{
		Long x = Long(l) / g;
		if (Long(l) % g != Long(0)) x++;
		g *= x;
	}
	
	if (g >= l && g <= h)
		{fprintf(out, "%s\n", g.toString().c_str()); return;}
	fprintf(out, "NO\n");
	
	/*
	long long ans = -1;
	for (long long cur = l; cur <= h; cur++)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] % cur != 0 && cur % a[i] != 0) {flag = 0; break;}
		if (flag) {ans = cur; break;}
	}
	if (ans == -1)
		fprintf(out, "NO\n");
	else
		fprintf(out, "%s\n", toString(ans).c_str());
	*/
}

int main(void)
{
	unsigned sTime = clock();
	in = fopen("PerfectHarmony.in", "rt");
	out = fopen("PerfectHarmony.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++)
	{
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		eval(test);
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n", (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
