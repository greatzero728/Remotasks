#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int NN = 202020, MM = NN << 2, inf = 0x3f3f3f3f;

int r1[NN], c1[NN], r2[NN], c2[NN];
int c[NN];

int xrr[MM], nx;
bool vst[MM];
vector<ppi> vec[MM];

int yrr[NN << 1], ny;

#define mid (L + R >> 1)

int ls[MM], rs[MM], nn, l, r, x;
int sum[MM], mn[MM], flag[MM], all;

int build(int L, int R) {
	int u = nn++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
	}
	sum[u] = yrr[R] - yrr[L];
	return u;
}

int update(int u, int x) {
	mn[u] += x, flag[u] += x;
	return 0;
}

void push_down(int u) {
	if(flag[u]) {
		update(ls[u], flag[u]);
		update(rs[u], flag[u]);
		flag[u] = 0;
	}
}

void push_up(int u) {
	mn[u] = min(mn[ls[u]], mn[rs[u]]);
	sum[u] = 0;
	if(mn[u] == mn[ls[u]]) sum[u] += sum[ls[u]];
	if(mn[u] == mn[rs[u]]) sum[u] += sum[rs[u]];
}

int update(int u, int L, int R) {
	if(l <= L && R <= r) return update(u, x);
	push_down(u);
	if(l < mid) update(ls[u], L, mid);
	if(mid < r) update(rs[u], mid, R);
	push_up(u);
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = n; i--; ) {
		scanf("%d %d %d %d", r1 + i, c1 + i, r2 + i, c2 + i);
		xrr[nx++] = c1[i], xrr[nx++] = c2[i] + 1;
		yrr[ny++] = r1[i], yrr[ny++] = r2[i] + 1;
	}
	yrr[ny++] = inf;
	sort(yrr, yrr + ny);
	ny = unique(yrr, yrr + ny) - yrr;
	
	for(int i = m; i--; ) {
		scanf("%d", c + i);
		xrr[nx++] = c[i], xrr[nx++] = c[i] + 1;
	}
	sort(xrr, xrr + nx);
	nx = unique(xrr, xrr + nx) - xrr;
	
	for(int i = n; i--; ) {
		int st = lower_bound(xrr, xrr + nx, c1[i]) - xrr;
		int ed = lower_bound(xrr, xrr + nx, c2[i] + 1) - xrr;
		int mn = lower_bound(yrr, yrr + ny, r1[i]) - yrr;
		int mx = lower_bound(yrr, yrr + ny, r2[i] + 1) - yrr;
		vec[st].push_back({{mn, mx}, 1});
		vec[ed].push_back({{mn, mx}, -1});
	}
	for(int i = m; i--; ) {
		int id = lower_bound(xrr, xrr + nx, c[i]) - xrr;
		vst[id] = 1;
	}
	
	yrr[ny] = inf;
	all = yrr[ny] - yrr[0], build(0, ny);
	
	INT ans = 0;
	for(int i = 0; i + 1 < nx; i++) {
		for(ppi p : vec[i]) {
			l = p.x.x, r = p.x.y, x = p.y, update(0, 0, ny);
		}
		if(!vst[i]) {
			ans += (INT)(all - sum[0]) * (xrr[i + 1] - xrr[i]);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}