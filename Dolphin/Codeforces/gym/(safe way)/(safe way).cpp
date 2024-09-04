#include <bits/stdc++.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 60;
const int mod = 1e9 + 7;
const ll inf = 1e18 + 9;
const ld pi = acos (-1.0);
const ld eps = 1e-11;

inline void boost () {
	ios_base::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
}
int n;
vector < int > g[N * N];
ld dp[N * N][N * N];
ld ans = mod * 1ll;

struct line {
	ll A, B, C;
	line () {}
	line (ll a, ll b, ll c) {
		A = a, B = b, C = c;
	}                       
	line (ll x1, ll y1, ll x2, ll y2) {
		A = y1 - y2;
		B = x2 - x1;
		C = -(A * x1 + B * y1);
	}
} l[N];

struct point {
	ld x, y;
	point () {}
	point (ld X, ld Y) {
		x = X, y = Y;
	}
	friend point operator -(point a, point b) {
		return point (a.x - b.x, a.y - b.y);
	}
	friend bool operator < (point a, point b) {
		return mp (a.x, a.y) < mp (b.x, b.y);
	}
	friend bool operator == (point a, point b) {
		return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
	}
};

vector < point > p;

bool intersect (line a, line b) {
	return (a.A * b.B - a.B * b.A != 0);
}

point intersection (line a, line b) {
	ld k = a.A * b.B - a.B * b.A;
	ld res1 = -a.C * b.B - a.B * (-b.C);
	ld res2 = a.A * (-b.C) - (-a.C) * b.A;
	ld x = res1 / k, y = res2 / k;
	return point(x, y); 
}

ld ang (point a, point b) {
	ld Angle = (fabs (atan2 (a.y, a.x) - atan2 (b.y, b.x))); 
	return min (Angle, 2 * pi - Angle);
}
ld Cost (point a, point b, point c) {
	point x = c - b;
	point y = b - a;
	return ang (x, y);
}
bool same (line a, point b) {
	return (fabs (a.A * b.x + a.B * b.y + a.C) < eps); 
}

int main () {
	boost ();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen ("saferoute.in", "r", stdin);
	freopen ("saferoute.out", "w", stdout);
#endif
	
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		l[i] = line (x1, y1, x2, y2);
	}
	point st, fn;
	cin >> st.x >> st.y >> fn.x >> fn.y;

	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j < i;j ++) {
			if (intersect (l[i], l[j])) {
				point x = intersection (l[i], l[j]);
				p.pb (x);
			}
		}
	}
	p.pb (st); p.pb (fn);
	sort (p.begin (), p.end ());
	p.erase (unique (p.begin(), p.end()), p.end());
	int pos1 = lower_bound (p.begin (), p.end (), st) - p.begin ();
	int pos2 = lower_bound (p.begin (), p.end (), fn) - p.begin ();

	for (int i = 1;i <= n;i ++) {
		vector < int > pos;
		for (int j = 0;j < sz (p);j ++) 
			if (same (l[i], p[j]))
				pos.pb (j);			
		for (int j = 0;j < sz (pos) - 1;j ++) {
			g[pos[j]].pb (pos[j + 1]);
			g[pos[j + 1]].pb (pos[j]);
		}
	}
	set < pair < ld, pair < int, int > > > q;
	for (int i = 0;i < sz (p);i ++) 
		for (int j = 0;j < sz (p);j ++)
			dp[i][j] = mod * 1ll;
	for (int i = 0;i < sz (g[pos1]);i ++) {
		int go = g[pos1][i];
		dp[pos1][go] = 0;
		q.insert (mp (0.0, mp (pos1, go)));
	}
	while (!q.empty ()) {
		pair < int, int > v = q.begin () -> S;
		q.erase (q.begin ());
		for (auto to : g[v.S]) {
			ld cost = Cost (p[v.F], p[v.S], p[to]);
			cost += dp[v.F][v.S];
			if (cost < dp[v.S][to]) {
				q.erase (mp (dp[v.S][to], mp (v.S, to)));
				dp[v.S][to] = cost;
				q.insert (mp (dp[v.S][to], mp (v.S, to)));
			}
		}
	}
	for (int i = 0;i < sz (p);i ++) 
		if (i != pos2)
			ans = min (ans, dp[i][pos2]);
	if (ans == mod * 1ll) cout << -1;
	else cout << fixed << setprecision (15) << ans / pi * 180;
	return 0;
}