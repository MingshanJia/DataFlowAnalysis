#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

struct vect {
	ld x, y, z;
	
	vect(ld x = 0, ld y = 0, ld z = 0): x(x), y(y), z(z) {}
	vect &operator +=(const vect &v2) {x += v2.x, y += v2.y, z += v2.z; return *this;}
	vect operator +(const vect &v2) {return vect(*this) += v2;}
	vect &operator /=(const double d) {x /= d, y /= d, z /= d; return *this;}
	vect operator /(const double d) {return vect(*this) /= d;}
	vect &operator *=(const double d) {x *= d, y *= d, z *= d; return *this;}
	vect operator *(const double d) {return vect(*this) *= d;}
	ld dot(const vect &v2) {return x * v2.x + y * v2.y + z * v2.z;}
	ld norm() {return sqrtl(x * x + y * y + z * z);}
};

istream &operator >>(istream &s, vect &v) {return s >> v.x >> v.y >> v.z;}
ostream &operator <<(ostream &s, vect &v) {return s << '(' << v.x << ' ' << v.y << ' ' << v.z << ')';}

int main() {
	int nt, it;
	
	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n, i;
		vect p, v, t;
		ld s;
		
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> t, p += t, cin >> t, v += t;
		}
		p /= n, v /= n;
//		cout << p << v << ' ' << p.dot(v) << '\n';
		
		s = (v.norm() ? max(-(p.dot(v) / v.norm()), ld(0)) / v.norm() : 0);
		
//		cout << "Case #" << it << ": " << setprecision(20) << (p + v * (s / v.norm())).norm() << ' ' << s / v.norm() << '\n';
		cout << "Case #" << it << ": " << setprecision(20) << (p + v * s).norm() << ' ' << s << '\n';
	}
	
	return 0;
}
