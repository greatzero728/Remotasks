#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010, MM = NN << 1;

int Ls[MM], xmn[MM], ymn[MM], x[NN], y[NN];
int Rx[MM], xmx[MM], ymx[MM], id[NN], nc;

int build(int L, int R, bool f = 0) {
	int u = nc++;
	if(R - L < 2) {
		xmn[u] = xmx[u] = x[id[L]], ymn[u] = ymx[u] = y[id[L]];
		return u;
	}
	if(f) nth_element(id + L, id + mid, id + R, [&](int u, int v) {return x[u] < x[v];});
	else nth_element(id + L, id + mid, id + R, [&](int u, int v) {return y[u] < y[v];});
	
	int ls = Ls[u] = build(L, mid, f ^ 1), rs = Rs[u] = build(mid, R, f ^ 1);
	xmn[u] = min(xmn[ls], xmn[rs]), xmx[u] = max(xmx[ls], xmx[rs]);
	ymn[u] = min(ymn[ls], ymn[rs]), ymx[u] = max(ymx[ls], ymx[rs]);
	return u;
}

int z[NN][4];
INT flag[MM][4]

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", x + i, y + i);
		for(int j = 0; j < 4; j++) scanf("%d", z[i] + j);
		id[i] = i;
	}
	build(1, n + 1);
	return 0;
}