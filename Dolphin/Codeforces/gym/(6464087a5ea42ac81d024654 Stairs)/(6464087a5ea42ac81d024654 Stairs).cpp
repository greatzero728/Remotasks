#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using DO = double;

DO RA, RB;
const DO eps = 1e-6;

struct point {
	DO x, y, z;
	point(DO x = 0, DO y = 0, DO z = 0) : x(x), y(y), z(z) {}
	point operator + (point a) {return point(x + a.x, y + a.y, z + a.z);}
	point operator - (point a) {return point(x - a.x, y - a.y, z - a.z);}
	point operator * (DO a) {return point(x * a, y * a, z * a);}
	point operator / (DO a) {return point(x / a, y / a, z / a);}
	point operator ^ (point a) {return point(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);}
	point norm() {DO s = nor(); return s < eps ? *this : point(x / s, y / s, z / s);}
	DO nor() {return sqrt(*this * *this);}
	DO nor2() {return *this * *this;}
	DO operator * (point a) {return x * a.x + y * a.y + z * a.z;}
	bool operator < (const point &a) const {
		return fabs(x - a.x) > eps ? x < a.x : fabs(y - a.y) < eps ? y < a.y : z < a.z;
	}
	bool operator > (const point &a) const {
		return fabs(x - a.x) > eps ? x > a.x : fabs(y - a.y) > eps ? y > a.y : z > a.z;
	}
	bool operator != (const point &a) const {
		return fabs(x - a.x) > eps || fabs(y - a.y) > eps || fabs(z - a.z) > eps;
	}
	bool operator == (const point &a) const {
		return fabs(x - a.x) < eps && fabs(y - a.y) < eps && fabs(z - a.z) < eps;
	}
	void input() {scanf("%lf %lf %lf", &x, &y, &z);}
	void print() {printf("%.5lf %.5lf %.5lf", x, y, z);}
} A, VA, B, VB;

DO get_collide_distance(point P, point A, point B, DO R) {
	point dir = (B - A).norm();
	point M = A + dir * ((P - A) * dir);
	DO d = (P - M).nor();
	
	if(d > R + eps) puts("NO"), exit(0);
	
	DO x = sqrt(R * R - (P - M).nor2());
	point C = M - dir * x;
	if(((C - A) * dir) < -eps) puts("NO"), exit(0);
	
	return (C - A).nor();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%lf", &RA), A.input(), VA.input();
	scanf("%lf", &RB), B.input(), VB.input();
	
	point V = VA - VB;
	DO R = RA + RB;
	
	DO collide_distance = get_collide_distance(B, A, A + V * 20202020, R);
	DO collide_time = collide_distance / V.nor();
	
	A = A + VA * collide_time;
	B = B + VB * collide_time;
	
	puts("YES");
	((A * RB + B * RA) / (RA + RB)).print();
	return 0;
}