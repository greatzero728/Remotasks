#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

struct point {
	DO x, y;
	point(DO x = 0, DO y = 0) : x(x), y(y) {}
	point operator + (point a) {return point(x + a.x, y + a.y);}
	point operator - (point a) {return point(x - a.x, y - a.y);}
	point operator * (DO a) {return point(x * a, y * a);}
	point operator / (DO a) {return point(x / a, y / a);}
	DO operator ^ (point a) {return x * a.y - y * a.x;}
	DO operator * (point a) {return x * a.x + y * a.y;}
	bool operator < (const point &a) const {
		return fabs(x - a.x) > eps ? x < a.x : y < a.y;
	}
	bool operator > (const point &a) const {
		return fabs(x - a.x) > eps ? x > a.x : y > a.y;
	}
	bool operator == (const point &a) const {
		return fabs(x - a.x) < eps && fabs(y - a.y) < eps;
	}
	bool operator != (const point &a) const {
		return fabs(x - a.x) > eps || fabs(y - a.y) > eps;
	}
	point operator & (point a) {
		return point(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	point rotate (DO al) {return *this & point(cos(al), sin(al));}
	point conj() {return point(-y, x);}
	DO al() {return atan2(y, x);}
	DO nor() {return sqrt(*this * *this);}
	point norm() {
		DO s = nor();
		return s < eps ? *this : point(x / s, y / s);
	}
	bool pos() {return y > eps || x > -eps && y > -eps;}
	void input() {scanf("%lf %lf", &x, &y);}
	void print() {printf("%lf %lf\n", x, y);}
};

int sgn(DO a) {return a < -eps ? -1 : a > eps;}
bool is_on(point c, point a, point b) {
	if(sgn(a - b ^ b - c)) return 0;
	return sgn((a - c) * (b - c)) <= 0;
} //Check c is in line a-b
DO angle(point a, point b) {return acos(a * b / a.nor() / b.nor());}
DO angle(point A, point F, point B) {return angle(A - F, B - F);}
DO pdist(point c, point a, point b) {
	point x = c - a, y = c - b, s = a - b;
	if(sgn(x * s) >= 0) return x.nor();
	if(sgn(y * s) <= 0) return y.nor();
	return fabs(x ^ y) / s.nor();
}
bool is_in_poly(point a, point *p, int n) {
	int i = -1;
	while(++i < n) if(is_on(a, p[i], p[i + 1])) return 1;
	bool f = 0; point b, c;
	while(i--) {
		if((b = p[i]) > (c = p[i + 1])) swap(b, c);
		if(sgn(c - b ^ a - b) < 0 && b.x < a.x - eps && a.x < c.x + eps) f ^= 1;
	}
	return f;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
//	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	
	return 0;
}
