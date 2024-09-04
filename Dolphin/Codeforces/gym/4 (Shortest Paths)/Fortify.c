#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 0x3f3f3f3f
#define NN 202020

int head[NN], nxt[NN * 12], to[NN * 12], wei[NN * 12], E;
int d[NN], q[50505050], qf, qb;
int a[NN], n, m;

void init(int n) {
	E = 0;
	for(int i = 0; i <= n; i++) {
		head[i] = -1, d[i] = inf;
	}
}

void add(int u, int v, int w) {
	wei[E] = w, to[E] = v, nxt[E] = head[u], head[u] = E++;
}

int id(int i, int j) {
	return i * m + j;
}

int solve() {
	scanf("%d %d", &n, &m);
	int N = n * m;
	for(int i = 0; i < N; i++) scanf("%d", a + i);
	
	int src = N, tar = N + 1;
	init(tar);
	
	for(int i = 0; i < n; i++) {
		add(src, id(i, 0), a[id(i, 0)]);
		add(id(i, m - 1), tar, 0);
	}
	for(int i = 1; i < m; i++) {
		add(src, id(n - 1, i), a[id(n - 1, i)]);
		add(id(0, i - 1), tar, 0);
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			add(id(i - 1, j - 1), id(i, j), a[id(i, j)]);
			add(id(i, j), id(i - 1, j - 1), a[id(i - 1, j - 1)]);
			add(id(i - 1, j), id(i, j - 1), a[id(i, j - 1)]);
			add(id(i, j - 1), id(i - 1, j), a[id(i - 1, j)]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < m; j++) {
			add(id(i, j - 1), id(i, j), a[id(i, j)]);
			add(id(i, j), id(i, j - 1), a[id(i, j - 1)]);
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			add(id(i - 1, j), id(i, j), a[id(i, j)]);
			add(id(i, j), id(i - 1, j), a[id(i - 1, j)]);
		}
	}
	
	d[src] = 0;
	qf = qb = 0, q[qb++] = src;
	while(qf < qb) {
		int u = q[qf++];
		for(int e = head[u]; ~e; e = nxt[e]) {
			int v = to[e];
			if(d[v] > d[u] + wei[e]) {
				d[v] = d[u] + wei[e];
				q[qb++] = v;
			}
		}
	}
	return d[tar];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
}