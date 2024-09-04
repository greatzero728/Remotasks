#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char fjf[1010];
char gc() {
	static char *L = fjf;
	static char *R = fjf;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}

#define NN 1010
#define MM 1010101
#define EE 4040404
#define inf 0x3f3f3f3f

int h[NN][NN], id[NN][NN];
int head[MM], nxt[EE], to[EE], E;
int q[10101010], qf, qb;
int rt[MM], d[MM];
static int i, j, x, y, u, v;
static char c;

void init(int n) {
	E = qf = qb = 0;
	for(i = 1; i <= n; i++) {
		rt[i] = i, head[i] = -1;
		d[i] = inf;
	}
}

int find_root(int u) {
	if(rt[u] == u) return u;
	return rt[u] = find_root(rt[u]);
}

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

int solve() {
	int n, m, N;
	while(c = gc(), (c < 48 || 57 < c) && c ^ 45 && ~c);
	for(n = c - 48; c = gc(), 48 <= c && c <= 57; n = 10 * n + c - 48);
	
	while(c = gc(), (c < 48 || 57 < c) && c ^ 45 && ~c);
	for(m = c - 48; c = gc(), 48 <= c && c <= 57; m = 10 * m + c - 48);
	
	for(i = 1, u = 0; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			while(c = gc(), (c < 48 || 57 < c) && c ^ 45 && ~c);
			for(h[i][j] = c - 48; c = gc(), 48 <= c && c <= 57; h[i][j] = 10 * h[i][j] + c - 48);
			id[i][j] = ++u;
		}
	}
	
	init(N = u);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			if(j > 1) {
				if(h[x = i][y = j - 1] == h[i][j]) rt[find_root(id[x][y])] = find_root(id[i][j]);
			}
			if(i > 1) {
				if(h[x = i - 1][y = j] == h[i][j]) rt[find_root(id[x][y])] = find_root(id[i][j]);
			}
		}
	}
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			if(j > 1) {
				u = find_root(id[x = i][y = j - 1]), v = find_root(id[i][j]);
				if(u != v) add(u, v), add(v, u);
			}
			if(i > 1) {
				u = find_root(id[x = i - 1][y = j]), v = find_root(id[i][j]);
				if(u != v) add(u, v), add(v, u);
			}
		}
	}
	
	int st = find_root(1), ed = find_root(N);
	q[qb++] = st, d[st] = 0;
	while(qf < qb) {
		u = q[qf++];
		if(u == ed) return d[u];
		for(i = head[u]; ~i; i = nxt[i]) {
			v = to[i];
			if(d[v] > d[u] + 1) {
				d[v] = d[u] + 1, q[qb++] = v;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}