#include<stdio.h>
#include<stdbool.h>

#define NN 1010101

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int a[NN], sz, n, m;
bool flag[NN], vst[NN];
int head[NN], nxt[NN << 3], to[NN << 3], E;

int id(int x, int y) {
	return (x - 1) * m + y;
}

void dfs(int u) {
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		sz++;
		if(!vst[v]) vst[v] = 1, dfs(v);
	}
}

bool out(int x, int y) {
	return x < 1 || x > n || y < 1 || y > m;
}

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int R; scanf("%d %d %d", &n, &m, &R);
	for(int i = R; i--; ) {
		int x, y; scanf("%d %d", &x, &y);
		a[i] = id(x, y);
		flag[a[i]] = head[a[i]] = -1;
	}
	
	int N = n * m;
	for(int i = R; i--; ) {
		int y = a[i] % m;
		if(!y) y = m;
		int x = (a[i] - y) / m + 1;
		
		int u = a[i];
		for(int k = 4; k--; ) {
			int X = x + dx[k], Y = y + dy[k];
			if(out(X, Y)) continue;
			int v = id(X, Y);
			if(flag[v]) add(u, v);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++) if(flag[i] && !vst[i]) {
		sz = 0, vst[i] = 1, dfs(i);
		if(sz > ans) ans = sz;
	}
	printf("%d\n", ans);
}