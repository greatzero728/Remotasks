#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using DO = double;
const DO eps = 1e-7, pi = acos(-1);

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

point F;

void calc(point A, point &B) {
	point H = F + (A - B).conj().norm() * ((B - F) * (A - B).conj().norm());
	point st = H, ed = B;
	for(int i = 100; i--; ) {
		point md = (st + ed) / 2;
		if(md.nor() < 1) st = md;
		else ed = md;
	}
	B = st;
}

DO get_angle(point dir) {
	DO al = dir.al();
	if(al < 0) al += 2 * pi;
	return al;
}

using pdd = pair<DO, DO>;

vector<pdd> vec;

void insert(DO st, DO ed) {
	vec.push_back({st, ed});
}

void update() {
	point A, B, C; A.input();
	DO alpha, delta; scanf("%lf %lf", &alpha, &delta), delta /= 2;
	
	point dir = {7, 0}; dir = dir.rotate(alpha);
	
	B = A + dir.rotate(-delta), calc(A, B);
	C = A + dir.rotate(delta), calc(A, C);
	
	DO st = get_angle(B - F), ed = get_angle(C - F);
	if(st > ed) insert(st, 2 * pi), insert(0, ed);
	else insert(st, ed);
}

DO arr[101010];
int num[101010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	while(n--) update();
	
	int nn = 0;
	arr[nn++] = 0, arr[nn++] = 2 * pi;
	for(pdd p : vec) arr[nn++] = p.x, arr[nn++] = p.y;
	sort(arr, arr + nn);
	nn = unique(arr, arr + nn) - arr;
	
	for(pdd p : vec) {
		int L = lower_bound(arr, arr + nn, p.x) - arr;
		int R = lower_bound(arr, arr + nn, p.y) - arr;
		num[L]++, num[R]--;
	}
	
	for(int i = 1; i < nn; i++) num[i] += num[i - 1];
	
	for(int i = 0; i + 1 < nn; i++) if(!num[i]) {
		puts("NO"), exit(0);
	}
	puts("YES");
	return 0;
}