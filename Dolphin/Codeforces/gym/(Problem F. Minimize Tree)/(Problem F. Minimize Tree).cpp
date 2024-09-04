#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 50505;

vector<pii> adj[NN];
int L[NN], R[NN], nn;
int d[NN], a[NN];
INT ans;

void pre_dfs(int u, int f = 0) {
	L[u] = ++nn, a[nn] = d[u];
	ans += d[u];
	for(pii p : adj[u]) {
		int v = p.x, w = p.y;
		if(v != f) {
			d[v] = d[u] + w;
			pre_dfs(v, u);
		}
	}
	R[u] = nn;
}

int Lmn[NN], Rmn[NN];
INT mn[NN], sum[NN], Mn;

int dfs(int u, int f = 0) {
	int sz = 1;
	for(pii p : adj[u]) {
		int v = p.x, w = p.y;
		if(v != f) {
			int sub_sz = dfs(v, u);
			sum[u] += (INT)w * sub_sz + sum[v];
			sz += sub_sz;
			INT add = (INT)(min(Lmn[L[v] - 1], Rmn[R[v] + 1]) + w) * sub_sz + mn[v];
			INT sub = (INT)d[v] * sub_sz + sum[v];
			Mn = min(Mn, add - sub);
		}
	}
	return sz;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	pre_dfs(1);
	
	for(int i = 1; i < n; i++) Lmn[i] = min(Lmn[i - 1], a[i]);
	for(int i = n; i > 1; i--) Rmn[i] = min(a[i], Rmn[i + 1]);
	
	dfs(1);
	
	cout<<ans + Mn;
	return 0;
}