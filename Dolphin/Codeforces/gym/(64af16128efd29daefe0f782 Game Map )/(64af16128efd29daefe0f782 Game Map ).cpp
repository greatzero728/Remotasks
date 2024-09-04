#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010, MM = 303030;

int U[MM], V[MM];
int deg[MM];
int id[NN];

int head[NN], nxt[MM], to[MM], E;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

int ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = m; i--; ) {
		scanf("%d %d", U + i, V + i);
		deg[U[i]]++, deg[V[i]]++;
	}
	
	for(int i = n; i--; ) {
		head[i] = -1;
		id[i] = i;
	}
	sort(id, id + n, [&](int u, int v) {
		return deg[u] < deg[v];
	});
	
	for(int i = m; i--; ) {
		if(deg[U[i]] > deg[V[i]]) add(U[i], V[i]);
		if(deg[V[i]] > deg[U[i]]) add(V[i], U[i]);
	}
	for(int i = 0, u; i < n; i++) {
		u = id[i];
		for(int e = head[u], v; ~e; e = nxt[e]) {
			v = to[e];
			ans[u] = max(ans[u], ans[v] + 1);
		}
	}
	printf("%d\n", *max_element(ans, ans + n) + 1);
	return 0;
}
