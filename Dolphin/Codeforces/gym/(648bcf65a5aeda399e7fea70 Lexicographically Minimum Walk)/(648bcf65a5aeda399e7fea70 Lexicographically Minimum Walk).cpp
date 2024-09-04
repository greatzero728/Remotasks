#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010, MM = 303030, CC = 1e6;

bool can[NN], flag[NN];
int head[NN], nxt[MM], to[MM], E;
vector<pii> adj[NN];

void init(int n) {
	E = 0;
	for(int i = 1; i <= n; i++) head[i] = -1;
}
void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

vector<int> ans;
int t;

int dfs(int u) {
	flag[u] = 1;
	if(u == t) {
		for(int x : ans) printf("%d ", x);
		exit(0);
	}
	for(pii p : adj[u]) {
		int v = p.y;
		if(can[v]) {
			if(flag[v]) puts("TOO LONG"), exit(0);
			ans.push_back(p.x);
			return dfs(v);
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m, s; scanf("%d %d %d %d", &n, &m, &s, &t);
	init(n);
	while(m--) {
		int u, v, c; scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({c, v});
		add(v, u);
	}
	
	queue<int> q;
	can[t] = 1, q.push(t);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int e = head[u]; ~e; e = nxt[e]) {
			int v = to[e];
			if(!can[v]) can[v] = 1, q.push(v);
		}
	}
	
	if(can[s]) {
		for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
		dfs(s);
	}
	else puts("IMPOSSIBLE");
	return 0;
}
