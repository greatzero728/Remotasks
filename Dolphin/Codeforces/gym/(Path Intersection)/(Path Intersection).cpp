#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

#define pc _putchar_nolock
static char fjf[1010], so[44];
void pt(int x) {
	int n = 0;
	while(so[n++] = x % 10, x /= 10);
	while(n--) pc(so[n] + 48);
}
char gc() {
	static char *L = fjf, *R = L;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}
bool gn(int &x) {
	char c; while(c = gc(), (c < 48 || 57 < c) && ~c);
	for(x = c - 48; c = gc(), 48 <= c && c <= 57; x = 10 * x + c - 48);
	return 1;
}

const int NN = 10101, MM = NN << 1;

int sz[NN], dep[NN], pa[NN], top[NN], hv[NN], nc;
int dfn[NN], I[NN], head[NN], nxt[MM], to[MM], E;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

void dfs1(int u) {
	sz[u] = 1, hv[u] = -1;
	for(int e = head[u], mx = 0, v; ~e; e = nxt[e]) if((v = to[e]) ^ pa[u]) {
		dep[v] = dep[pa[v] = u] + 1, dfs1(v), sz[u] += sz[v];
		if(sz[v] > mx) mx = sz[hv[u] = v];
	}
}
void dfs2(int u, int f) {
	top[I[dfn[u] = ++nc] = u] = f;
	if(~hv[u]) dfs2(hv[u], f);
	for(int e = head[u]; ~e; e = nxt[e]) {
		f = to[e];
		if(f ^ pa[u] && f ^ hv[u]) dfs2(f, f);
	}
}
int lca(int u, int v) {
	for(; top[u] ^ top[v]; u = pa[top[u]]) if(dep[top[u]] < dep[top[v]]) swap(u, v);
	return dep[u] < dep[v] ? u : v;
}
int dp[NN];
void query(int u, int v) {
	int L, R;
	for(; top[u] ^ top[v]; u = pa[top[u]]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		L = dfn[top[u]], R = dfn[u];
		dp[L]++, dp[R + 1]--;
	}
	if(dep[u] > dep[v]) swap(u, v);
	L = dfn[u], R = dfn[v];
	dp[L]++, dp[R + 1]--;
}
void init(int n) {
	E = nc = 0;
	while(head[n] = -1, n--);
}

void solve() {
	int n; gn(n), init(n);
	for(int i = 1, u, v; i < n; i++) {
		gn(u), gn(v);
		add(u, v), add(v, u);
	}
	
	dfs1(1);
	dfs2(1, 1);
	
	int q; gn(q);
	while(q--) {
		int k; gn(k);
		for(int i = 1; i <= n; i++) dp[i] = 0;
		for(int i = k; i--; ) {
			int u, v; gn(u), gn(v);
			query(u, v);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			dp[i] += dp[i - 1];
			if(dp[i] == k) ans++;
		}
		pt(ans), pc(10);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int t; gn(t);
	for(int i = 1; i <= t; i++) {
		printf("Case %d:\n", i);
		solve();
	}
	return 0;
}