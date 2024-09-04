#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using DO = double;

const DO eps = 1e-6;

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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	point A, B; A.input(), B.input();
	DO k; scanf("%lf", &k);
	point M = (A + B) / 2;
	
	point C = M + (B - A).conj() * k;
	point D = M + M - C;
	
	point p;
	if(fabs(C.y - D.y) < eps) p = {min(C.x, D.x), C.y};
	else if(C.y > D.y) p = C;
	else p = D;
	p.print();
	return 0;
}
