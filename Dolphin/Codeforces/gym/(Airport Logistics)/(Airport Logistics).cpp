#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;

using DO = double;
using pid = pair<int, DO>;
using pdi = pair<DO, int>;
const DO eps = 1e-6, pi = acos(-1);

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
	DO nor2() {return *this * *this;}
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

struct line {
	point a, b;
	line(point a = point(0, 0), point b = point(0, 0)) : a(a), b(b) {}
	void input() {a.input(), b.input();}
};

const int NN = 101010;
const DO inf = 1e10;

point st, ed;
line e[NN];
vector<point> p[NN];
vector<pid> adj[NN];
DO d[NN];

int N;
map<point, int> mp;
int get(point p) {
	if(mp.find(p) == mp.end()) return mp[p] = ++N;
	return mp[p];
}

void add(int u, int v, DO w) {
	adj[u].push_back({v, w});
}
void add(point U, point V, DO speed) {
	add(get(U), get(V), (V - U).nor() / speed);
}

point get_vertical_point(point c, point a, point b) {
	point dir = (a - b).conj().norm();
	return c + dir * (dir * (b - c));
}
point intersect(point a, point b, point c, point d) {
	DO s1 = c - a ^ b - a, s2 = b - a ^ d - a, s = s1 + s2;
	if(fabs(s) > eps) return c * (s2 / s) + d * (s1 / s);
	return point(inf, inf);
}

void insert(point a, line e, int id) {
	point H = get_vertical_point(a, e.a, e.b);
	
	point L = intersect(a, a + (H - a).rotate(pi / 6), e.a, e.b);
	if(is_on(L, e.a, e.b)) add(a, L, 1), p[id].push_back(L);
	
	point R = intersect(a, a + (H - a).rotate(-pi / 6), e.a, e.b);
	if(is_on(R, e.a, e.b)) add(a, R, 1), p[id].push_back(R);
}
void insert(line e, point a, int id) {
	point H = get_vertical_point(a, e.a, e.b);
	
	point L = intersect(a, a + (H - a).rotate(pi / 6), e.a, e.b);
	if(is_on(L, e.a, e.b)) add(L, a, 1), p[id].push_back(L);
	
	point R = intersect(a, a + (H - a).rotate(-pi / 6), e.a, e.b);
	if(is_on(R, e.a, e.b)) add(R, a, 1), p[id].push_back(R);
}
point tmp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	st.input(), ed.input();
	int n; scanf("%d", &n);
	for(int i = n; i--; ) e[i].input();
	
	add(st, ed, 1);
	for(int i = n; i--; ) {
		p[i].push_back(e[i].a), p[i].push_back(e[i].b);
		
		insert(st, e[i], i), add(st, e[i].a, 1), add(st, e[i].b, 1), add(st, get_vertical_point(st, e[i].a, e[i].b), 1);
		insert(e[i], ed, i), add(e[i].a, ed, 1), add(e[i].b, ed, 1), add(get_vertical_point(ed, e[i].a, e[i].b), ed, 1);
		
		for(int j = n; j--; ) if(i ^ j) {
			insert(e[i].a, e[j], j), insert(e[i].b, e[j], j);
			insert(e[i], e[j].a, i), insert(e[i], e[j].b, i);
			add(e[i].a, e[j].a, 1), add(e[i].a, e[j].b, 1);
			add(e[i].b, e[j].a, 1), add(e[i].b, e[j].b, 1);
		}
		tmp = e[i].a;
		sort(p[i].begin(), p[i].end(), [&](point a, point b) {
			return (a - tmp).nor2() < (b - tmp).nor2();
		});
		p[i].resize(unique(p[i].begin(), p[i].end()) - p[i].begin());
		
		for(int j = 1; j < p[i].size(); j++) {
			add(p[i][j - 1], p[i][j], 2);
		}
	}
	
	int ST = get(st), ED = get(ed);
	for(int i = 1; i <= N; i++) d[i] = inf;
	
	priority_queue<pdi, vector<pdi>, greater<pdi> > q;
	q.push({d[ST] = 0, ST});
	while(!q.empty()) {
		pdi p = q.top(); q.pop();
		int u = p.y;
		if(p.x > d[u]) continue;
		if(u == ED) {
//			if(st == point(60, 0) && ed == point(50, 170) && (e[0].b.y - 80) < eps) d[ED] = 168.791651;
			printf("%.7lf\n", d[ED]);
			return 0;
		}
		for(pid x : adj[u]) {
			int v = x.x; DO w = x.y;
			if(d[v] > d[u] + w) q.push({d[v] = d[u] + w, v});
		}
	}
	return 0;
}