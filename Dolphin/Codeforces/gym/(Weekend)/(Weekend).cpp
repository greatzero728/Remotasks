#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121, inf = 0x3f3f3f3f;

int d[NN][NN], id[11], f[11];

int solve() {
	int n, m, N; scanf("%d %d %d", &n, &m, &N);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) d[i][j] = inf;
		d[i][i] = 0;
	}
	while(m--) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		d[u][v] = d[v][u] = w;
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	int ans = inf;
	for(int i = 1; i <= N; i++) scanf("%d", id + i), f[i] = i;
	do {
		int s = d[1][id[f[1]]] + d[id[f[N]]][n];
		for(int i = 1; i < N; i++) s += d[id[f[i]]][id[f[i + 1]]];
		ans = min(ans, s);
	}
	while(next_permutation(f + 1, f + N + 1));
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case %d: %d\n", i, solve());
	}
	return 0;
}
