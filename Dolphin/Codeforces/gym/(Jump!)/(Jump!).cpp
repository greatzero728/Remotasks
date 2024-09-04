#include <bits/stdc++.h>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

int m;
int n;

vi v[1050][1050];

int was[1050][1050];

queue<ii> q;

int code(int x, int y) {
	re x * m + y;
}

ii decode(int x) {
	if (x == -1)
		re mp(-1, -1);
	re mp(x / m, x % m);
}

int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

int check(int x, int y) {
	re x >= 0 && x < n && y >= 0 && y < m;
}

int checkT(int x, int y, int t) {
	if (t >= v[x][y].back())
		re 0;
	int p = upper_bound(all(v[x][y]), t) - v[x][y].begin();
	re p % 2 == 1;
}

int parse(ii val) {
	ii o = decode(val.fi);
	int t = val.se;

	int x = o.fi;
	int y = o.se;

	if (y == -1) {
		rep(i, n) {
			if (checkT(i, 0, t + 1)) {
				int tmp = code(i, 0);
				if (!was[tmp][t + 1]) {
					was[tmp][t + 1] = 1;
					q.push(mp(tmp, t + 1));
				}
			}
		}

		if (t < 1010)
			q.push(mp(-1, t + 1));

		re -1;
	}

	if (y == m - 1) {
		re t + 1;
	}

	rep(o, 5) {
		int nx = x + dx[o];
		int ny = y + dy[o];

		if (check(nx, ny))
			if (checkT(nx, ny, t + 1)) {
				int tmp = code(nx, ny);
				if (!was[tmp][t + 1]) {
					was[tmp][t + 1] = 1;
					q.push(mp(tmp, t + 1));
				}
			}
	}

	re -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int k;
	cin >> n >> m >> k;

	rep(i, n) rep(j, m) {
		int s = 0;
		rep(o, 2 * k) {
			int x;
			scanf("%d", &x);
			s += x;
			v[i][j].pb(s);
		}
	}

	q.push(mp(-1, 0));
	while (!q.empty()) {
		int tmp = parse(q.front());
		if (tmp != -1) {
			cout << tmp << endl;
			re 0;
		}
		q.pop();
	}
	cout << -1 << endl;
	
	return 0;
}