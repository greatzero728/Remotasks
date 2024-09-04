#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 303030, MM = NN << 1;

#define _mx 19 // 1 << _mx > n
int dep[NN], pa[NN][_mx], head[NN], nxt[MM], to[MM], E;
int sz[NN];

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

struct LCA {
	int dfs(int u) {
		int e = 0, v;
		sz[u] = 1;
		while(++e < _mx) pa[u][e] = pa[pa[u][e - 1]][e - 1];
		for(e = head[u]; ~e; e = nxt[e]) if((v = to[e]) ^ pa[u][0]) {
			dep[v] = dep[pa[v][0] = u] + 1, sz[u] += dfs(v);
		}
		return sz[u];
	}
	int k_th(int u, int k) {
		while(k) u = pa[u][__builtin_ctz(k)], k ^= k & -k;
		return u ? u : 1;
	}
	int lca(int u, int v) {
		if(dep[u] < dep[v]) swap(u, v);
		if((u = k_th(u, dep[u] - dep[v])) == v) return u;
		int i = _mx;
		while(i--) if(pa[u][i] ^ pa[v][i]) u = pa[u][i], v = pa[v][i];
		return pa[u][0];
	}
} lc;

void init(int n) {
	E = 0;
	while(head[n] = -1, n--);
}

int dist(int u, int v) {
	int w = lc.lca(u, v);
	return dep[u] + dep[v] - (dep[w] << 1);
}

void solve() {
	int n, q; scanf("%d %d", &n, &q);
	init(n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	lc.dfs(1);
	
	while(q--) {
		int u, v; scanf("%d %d", &u, &v);
		if(dep[u] < dep[v]) swap(u, v);
		
		int d = dist(u, v);
		if(d & 1) puts("0");
		else if(u == v) printf("%d\n", n);
		else {
			d >>= 1;
			if(dep[u] == dep[v]) printf("%d\n", n - sz[lc.k_th(u, d - 1)] - sz[lc.k_th(v, d - 1)]);
			else {
				u = lc.k_th(u, d - 1);
				printf("%d\n", sz[lc.k_th(u, 1)] - sz[u]);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#else
	freopen("library.in", "r", stdin);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}