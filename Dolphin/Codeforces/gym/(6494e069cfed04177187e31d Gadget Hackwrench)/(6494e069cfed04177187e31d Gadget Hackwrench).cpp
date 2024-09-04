#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

vector<int> adj[NN];
int L[NN], R[NN], nn;
int indeg[NN], deep[NN];
int q[NN], qf, qb;

#define _mx 17 // 1 << _mx > n
int pa[NN][17];
int k_th(int u, int k) {
	while(k) u = pa[u][__builtin_ctz(k)], k ^= k & -k;
	return u ? u : 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		indeg[v]++;
		adj[u].push_back(v);
	}
	
	for(int i = 1; i <= n; i++) if(!indeg[i]) {
		q[qb++] = i, deep[i] = 1;
	}
	while(qf < qb) {
		int u = q[qf++];
		for(int i = 1; i < _mx; i++) pa[u][i] = pa[pa[u][i - 1]][i - 1];
		for(int v : adj[u]) {
			pa[v][0] = u;
			deep[v] = deep[u] + 1;
			if(!--indeg[v]) q[qb++] = v;
		}
	}
	
	int m; scanf("%d", &m);
	while(m--) {
		int pa, u; scanf("%d %d", &pa, &u);
		if(deep[pa] >= deep[u]) puts("No");
		else if(k_th(u, deep[u] - deep[pa]) == pa) puts("Yes");
		else puts("No");
	}
	return 0;
}