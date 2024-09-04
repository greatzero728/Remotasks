#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

vector<pii> adj[NN];

int dp[NN][2];

void dfs(int u, int f = 0) {
	for(pii p : adj[u]) {
		int v = p.x, w = p.y;
		if(v == f) continue;
		dfs(v, u);
		if(w && dp[v][1] + 1 > dp[u][0]) {
			dp[u][0] = dp[v][1] + 1;
			if(dp[u][0] > dp[u][1]) swap(dp[u][0], dp[u][1]);
		}
	}
}

void rdfs(int u, int f = 0) {
	for(pii p : adj[u]) {
		int v = p.x, w = p.y;
		if(v == f) continue;
		if(w) {
			int up = dp[u][1];
			if(dp[u][1] == dp[v][1] + 1) up = dp[u][0];
			if(up + 1 > dp[v][0]) {
				dp[v][0] = up + 1;
				if(dp[v][0] > dp[v][1]) swap(dp[v][0], dp[v][1]);
			}
		}
		rdfs(v, u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#else
	freopen("DTREE.INP", "r", stdin);
	freopen("DTREE.OUT", "w", stdout);
#endif
	
	int n, ans = 0; scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		ans += w >> 1, w &= 1;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int R; scanf("%d", &R);
	dfs(1), rdfs(1);
	
	if(R) printf("%d\n", ans + dp[R][1]);
	else {
		int mx = dp[n][1];
		for(int i = 1; i < n; i++) mx = max(mx, dp[i][1]);
		printf("%d\n", ans + mx);
	}
	return 0;
}
