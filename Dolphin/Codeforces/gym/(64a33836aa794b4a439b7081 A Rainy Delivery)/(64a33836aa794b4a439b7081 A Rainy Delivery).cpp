#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

int vst[NN], runs, sz;
vector<int> adj[NN];

void dfs(int u) {
	sz++;
	for(int v : adj[u]) if(vst[v] ^ runs) {
		vst[v] = runs, dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		sz = 0, vst[i] = ++runs, dfs(i);
		ans = max(ans, sz);
	}
	printf("%d\n", ans);
	return 0;
}