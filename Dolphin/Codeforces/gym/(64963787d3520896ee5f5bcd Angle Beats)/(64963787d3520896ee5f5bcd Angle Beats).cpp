#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

struct point {
	int x, y, id;
	point(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
	point operator + (point a) {return point(x + a.x, y + a.y);}
	point operator - (point a) {return point(x - a.x, y - a.y);}
	point operator * (int a) {return point(x * a, y * a);}
	point operator / (int a) {return point(x / a, y / a);}
	int operator ^ (point a) {return x * a.y - y * a.x;}
	int operator * (point a) {return x * a.x + y * a.y;}
	bool operator < (const point &a) const {
		return x - a.x > 0 ? x < a.x : y < a.y;
	}
	bool operator > (const point &a) const {
		return x - a.x > 0 ? x > a.x : y > a.y;
	}
	bool operator == (const point &a) const {
		return x - a.x == 0 && y - a.y == 0;
	}
	bool operator != (const point &a) const {
		return x != a.x || y != a.y;
	}
	point operator & (point a) {
		return point(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	point rotate (int al) {return *this & point(cos(al), sin(al));}
	point conj() {return point(-y, x);}
	int al() {return atan2(y, x);}
	int nor() {return sqrt(*this * *this);}
	void input() {scanf("%d %d", &x, &y);}
	void print() {printf("%lf %lf\n", x, y);}
};

const int NN = 4040;

int ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, q; scanf("%d %d", &n, &q);
	
	return 0;
}