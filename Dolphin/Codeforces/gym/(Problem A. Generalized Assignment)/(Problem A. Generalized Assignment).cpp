#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121, MM = 5252, inf = 0x3f3f3f3f;
#define PQ priority_queue<pii, vector<pii>, greater<pii> >

struct mcmf {
	PQ q;
	int d[NN], pv[NN], pe[NN], nxt[MM], to[MM];
	int V, E, k[NN], head[NN], cap[MM], cost[MM];
	
	void add(int u, int v, int f, int c) {
		cap[E] = f, cost[E] = c, to[E] = v, nxt[E] = head[u], head[u] = E++;
		cap[E] = 0, cost[E] = -c, to[E] = u, nxt[E] = head[v], head[v] = E++;
	}
	pii minCost(int s, int t, int x) { //max_flow <= x
		int u, e, g, i = V, f = 0, c = 0;
		while(k[i] = 0, i--);
		while(x) {
			q = PQ(), i = V;
			while(d[i] = inf, i--);
			q.push({d[s] = 0, s});
			while(!q.empty()) {
				g = q.top().x, u = q.top().y, q.pop();
				if(d[u] >= g) for(e = head[u]; ~e; e = nxt[e]) if(cap[e]) {
					g = d[u] + cost[e] + k[u] - k[i = to[e]];
					if(d[i] > g) pv[i] = u, pe[i] = e, q.push({d[i] = g, i});
				}
			}
			if(d[u = t] == inf) break;
			i = V, g = x;
			while(k[i] += d[i], i--);
			for(; u ^ s; u = pv[u]) if(cap[pe[u]] < g) g = cap[pe[u]];
			x -= g, f += g, c += g * k[u = t];
			while(u ^ s) cap[pe[u]] -= g, cap[pe[u] ^ 1] += g, u = pv[u];
		}
		return {f, c};
	}
	void init(int n) {
		V = E = n + 1;
		while(head[--E] = -1, E);
	}
} mc;

int a[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("assignment.in", "r", stdin);
	freopen("assignment.out", "w", stdout);
#endif
	
	int n, k; scanf("%d %d", &n, &k);
	int src = 0, tar = n + n + 1;
	mc.init(tar);
	for(int i = 1; i <= n; i++) {
		mc.add(src, i, k, 0);
		for(int j = 1; j <= n; j++) {
			scanf("%d", a[i] + j);
			mc.add(i, n + j, 1, a[i][j]);
		}
		mc.add(n + i, tar, k, 0);
	}
	cout<<mc.minCost(src, tar, k * n).y;
	return 0;
}