#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010, MM = NN << 1;
const INT inf = 1e17;

int sz[NN], dep[NN], pa[NN], top[NN], hv[NN], nc;
int dfn[NN], I[NN], head[NN], nxt[MM], to[MM], E;
int g[NN], st[NN], ed[NN];

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
	st[u] = dfn[u];
	if(~hv[u]) dfs2(hv[u], f);
	for(int e = head[u]; ~e; e = nxt[e]) {
		f = to[e];
		if(f ^ pa[u] && f ^ hv[u]) dfs2(f, f);
	}
	ed[u] = nc;
}
int lca(int u, int v) {
	for(; top[u] ^ top[v]; u = pa[top[u]]) if(dep[top[u]] < dep[top[v]]) swap(u, v);
	return dep[u] < dep[v] ? u : v;
}

using ppb = pair<pii, bool>;
vector<pii> Lv, Rv;

int l, r, x, n, nn;
int ls[MM], rs[MM];
INT sum[MM], mx[MM], Lmx[MM], Rmx[MM];

#define mid (L + R >> 1)

void push_up(int u) {
	sum[u] = sum[ls[u]] + sum[rs[u]];
	mx[u] = max({mx[ls[u]], Rmx[ls[u]] + Lmx[rs[u]], mx[rs[u]]});
	Lmx[u] = max(Lmx[ls[u]], sum[ls[u]] + Lmx[rs[u]]);
	Rmx[u] = max(Rmx[ls[u]] + sum[rs[u]], Rmx[rs[u]]);
}

int build(int L, int R) {
	int u = nn++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
		push_up(u);
	}
	else {
		mx[u] = sum[u] = Lmx[u] = Rmx[u] = g[I[L]];
	}
	return u;
}

INT mx_, sum_, Lmx_, Rmx_;
INT tmx_, tsum_, tLmx_, tRmx_;

void L_calc(int u, int L, int R) {
	if(l <= L && R <= r) {
		tsum_ = sum_ + sum[u];
		tmx_ = max({mx_, Rmx_ + Lmx[u], mx[u]});
		tLmx_ = max({Lmx_, sum_ + Lmx[u]});
		tRmx_ = max({Rmx_ + sum[u], Rmx[u]});
		
		mx_ = tmx_, sum_ = tsum_;
		Lmx_ = tLmx_, Rmx_ = tRmx_;
		return;
	}
	if(l < mid) L_calc(ls[u], L, mid);
	if(mid < r) L_calc(rs[u], mid, R);
}
void R_calc(int u, int L, int R) {
	if(l <= L && R <= r) {
		tsum_ = sum_ + sum[u];
		tmx_ = max({mx_, Rmx_ + Rmx[u], mx[u]});
		tLmx_ = max({Lmx_, sum_ + Rmx[u]});
		tRmx_ = max({Rmx_ + sum[u], Lmx[u]});
		
		mx_ = tmx_, sum_ = tsum_;
		Lmx_ = tLmx_, Rmx_ = tRmx_;
		return;
	}
	if(mid < r) R_calc(rs[u], mid, R);
	if(l < mid) R_calc(ls[u], L, mid);
}

INT query(int u, int v) {
	int w = lca(u, v);
	
	Lv.clear();
	for(; top[u] ^ top[w]; u = pa[top[u]]) {
		Lv.push_back({dfn[top[u]], dfn[u]});
	}
	Lv.push_back({dfn[w], dfn[u]});
	
	Rv.clear();
	for(; top[v] ^ top[w]; v = pa[top[v]]) {
		Rv.push_back({dfn[top[v]], dfn[v]});
	}
	int L = dfn[w], R = dfn[v];
	if(L < R) Rv.push_back({L + 1, R});
	
	sum_ = 0, mx_ = Lmx_ = Rmx_ = -inf;
	for(pii p : Lv) {
		l = p.x, r = p.y + 1, R_calc(0, 1, n + 1);
	}
	for(int i = Rv.size(); i--; ) {
		l = Rv[i].x, r = Rv[i].y + 1, L_calc(0, 1, n + 1);
	}
	return mx_;
}

void init(int n) {
	while(head[n] = -1, n--);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	init(n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	for(int i = 1; i <= n; i++) scanf("%d", g + i);
	dfs1(1), dfs2(1, 1);
	
	build(1, n + 1);
	int q; scanf("%d", &q);
	while(q--) {
		int u, v; scanf("%d %d", &u, &v);
		printf("%I64d\n", query(u, v));
	}
	return 0;
}