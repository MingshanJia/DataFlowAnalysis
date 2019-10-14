#include <bits/stdc++.h>
using namespace std;
typedef long double DB;
const int maxt = 101;
const DB eps = 1e-12;
int sgn(DB x) {
	return (x > eps) - (x < -eps);
}
int dcmp(DB x, DB y) {
	return sgn(x - y);
}
int t, tot, cnt[7];
struct Point2D {
	DB x, y;
	bool operator < (Point2D const &t) const {
		int tmp = sgn(x - t.x);
		return tmp < 0 || (!tmp && sgn(y - t.y) < 0);
	}
	Point2D operator - (Point2D const &t) const {
		return (Point2D){x - t.x, y - t.y};
	}
	DB det(Point2D const &t) const {
		return x * t.y - y * t.x;
	}
	DB dot(Point2D const &t) const {
		return x * t.x + y * t.y;
	}
	DB abs() const {
		return sqrt(dot(*this));
	}
} p[3], pp[7];
inline DB Angle(Point2D A) {
	return atan2(A.y, A.x);
}
inline Point2D CirclePoint(Point2D C, DB R, DB angle) {
	return (Point2D){C.x + cos(angle) * R, C.y + sin(angle) * R};
}
void getCircleCircleIntersection(Point2D C1, DB R1, Point2D C2, DB R2) {
	DB d = (C1 - C2).abs();
	if(dcmp(fabs(R1 - R2), d) >= 0) {
		pp[tot++] = C1;
		pp[tot++] = C2;
		return;
	}
	if(dcmp(R1 + R2, d) < 0)
		return;
	DB a = Angle(C2 - C1);
	DB da = acos((R1 * R1 + d * d - R2 * R2) / (2 * R1 * d));
	pp[tot++] = CirclePoint(C1, R1, a - da);
	pp[tot++] = CirclePoint(C1, R1, a + da);
}
struct Point3D {
	DB x, y, z;
	void read() {
		int _x, _y, _z;
		scanf("%d%d%d", &_x, &_y, &_z);
		x = _x;
		y = _y;
		z = _z;
	}
	Point3D operator - (Point3D const &t) const {
		return (Point3D){x - t.x, y - t.y, z - t.z};
	}
	Point3D operator * (DB const &t) const {
		return (Point3D){x * t, y * t, z * t};
	}
	DB dot(Point3D const &t) const {
		return x * t.x + y * t.y + z * t.z;
	}
	Point3D det(Point3D const &t) const {
		return (Point3D){y * t.z - z * t.y, z * t.x - x * t.z, x * t.y - y * t.x};
	}
	DB abs() const {
		return sqrt(dot(*this));
	}
	Point3D norm() const {
		return *this * (1 / abs());
	}
} a[3];
DB r[3];
bool solve() {
	tot = 0;
	getCircleCircleIntersection(p[0], r[0], p[1], r[1]);
	getCircleCircleIntersection(p[0], r[0], p[2], r[2]);
	getCircleCircleIntersection(p[1], r[1], p[2], r[2]);
	for(int i = 0; i < tot; ++i) {
		int cnt = 0;
		for(int j = 0; j < 3; ++j)
			cnt += dcmp((pp[i] - p[j]).abs(), r[j]) <= 0;
		if(cnt == 3)
			return 1;
	}
	return 0;
}
bool check(DB rad) {
	r[0] = r[1] = rad, r[2] = rad * 5;
	if(solve())
		return 1;
	r[0] = r[2] = rad, r[1] = rad * 5;
	if(solve())
		return 1;
	r[1] = r[2] = rad, r[0] = rad * 5;
	if(solve())
		return 1;
	r[0] = r[1] = rad * 3, r[2] = rad;
	if(solve())
		return 1;
	r[0] = r[2] = rad * 3, r[1] = rad;
	if(solve())
		return 1;
	r[1] = r[2] = rad * 3, r[0] = rad;
	if(solve())
		return 1;
	return 0;
}
int main() {
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		for(int i = 0; i < 3; ++i)
			a[i].read();
		Point3D vec = (a[1] - a[0]).det(a[2] - a[0]);
		if(!sgn(vec.abs())) {
			DB mx = max((a[1] - a[0]).abs(), max((a[2] - a[0]).abs(), (a[2] - a[1]).abs()));
			printf("Case #%d: %.10f\n", Case, (double)(mx / 6));
			continue;
		}
		vec = vec.norm();
		Point3D v1 = (a[1] - a[0]).norm(), v2 = vec.det(v1);
		for(int i = 0; i < 3; ++i)
			p[i] = (Point2D){v1.dot(a[i]), v2.dot(a[i])};
		DB L = 0, R = 1000;
		for(int i = 0; i < maxt; ++i) {
			DB M = L + (R - L) / 2;
			if(check(M))
				R = M;
			else
				L = M;
		}
		printf("Case #%d: %.10f\n", Case, (double)L);
	}
	return 0;
}
