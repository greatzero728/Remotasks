#pragma optimize("O3")
#include<bits/stdc++.h>
#define pc _putchar_nolock

using namespace std;

static char fjf[1010], so[44];
void pt(int x) {
	int n = 0;
	while(so[n++] = x % 10, x /= 10);
	while(n--) pc(so[n] + 48);
}
char gc() {
	static char *L = fjf, *R = L;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}
bool gn(int &x) {
	char c; while(c = gc(), (c < 48 || 57 < c) && ~c);
	for(x = c - 48; c = gc(), 48 <= c && c <= 57; x = 10 * x + c - 48);
	return 1;
}

const int NN = 131313;

int pa[NN], son[NN][2], sz[NN], val[NN], nc, rt;
int make(int x) {
	sz[++nc] = 1, val[nc] = x;
	pa[nc] = son[nc][0] = son[nc][1] = 0;
	return nc;
}
void push_up(int u) {
	int ls = son[u][0], rs = son[u][1];
	sz[u] = 1;
	if(ls) sz[u] += sz[ls];
	if(rs) sz[u] += sz[rs];
}
void rot(int x, bool d) {
	int y = pa[x], z = pa[y];
	if(son[z][0] == y) son[z][0] = x;
	else if(son[z][1] == y) son[z][1] = x;
	pa[x] = pa[pa[son[y][!d] = son[x][d]] = y];
	push_up(son[pa[y] = x][d] = y);
}
void splay(int x, int g) {
	bool d;
	for(int y; pa[x] ^ g; rot(x, d))
	if(pa[y = pa[x]] == g) d = son[y][0] == x;
	else son[y][d = son[pa[y]][0] == y] == x ? rot(x, !d) : rot(y, d);
	push_up(x);
	if(!g) rt = x;
}
int ans[NN << 1], nn;
void print(int u) {
	if(!u) return;
	print(son[u][0]);
	ans[nn++] = val[u], print(son[u][1]);
}
int find(int u, int k) {
	int s;
	while(1) {
		if(k <= sz[s = son[u][0]]) {u = s; continue;}
		if(!(k -= sz[s] + 1)) return u;
		u = son[u][1];
	}
}
void insert(int k, int c) {
	int x = find(rt, k);
	splay(x, 0), splay(k = find(x, k + 1), x);
	if(val[k] || !c) push_up(pa[son[k][0] = c = make(c)] = k), sz[k]++, sz[x]++;
	else val[k] = c;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("key.in", "r", stdin);
	freopen("key.out", "w", stdout);
#endif
	
	int n, m; gn(n), gn(m);
	
	for(int i = 1; i <= n + 2; i++) {
	 	sz[i] = i;
	 	if(i > 1) son[i][0] = i - 1;
	 	if(i < n + 2) pa[i] = i + 1;
	}
	rt = nc = n + 2;
	
	for(int i = 1, pos; i <= n; i++) {
		gn(pos), insert(pos, i);
	}
	print(rt);
	
	for(int i = 0; i < nn; i++) if(ans[i]) {
		int ed = i;
		for(int j = i; j < nn; j++) if(ans[j]) ed = j;
		
		pt(ed - i + 1), pc(10);
		for(int k = i; k <= ed; k++) pt(ans[k]), pc(32);
		return 0;
	}
	return 0;
}