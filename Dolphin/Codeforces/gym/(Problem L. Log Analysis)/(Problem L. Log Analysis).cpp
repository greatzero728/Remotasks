#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;

const int NN = 121212, CC = 26;

int pa[NN], son[NN][2], sz[NN], nc, rt;
int sum[NN][CC];
pic val[NN];

int make(int num, char c = 'a') {
	sz[++nc] = num;
	val[nc] = {num, c};
	for(int i = CC; i--; ) sum[nc][i] = 0;
	sum[nc][c - 'a'] = num;
	pa[nc] = son[nc][0] = son[nc][1] = 0;
	return nc;
}
void push_up(int u) {
	int ls = son[u][0], rs = son[u][1];
	sz[u] = val[u].x;
	for(int i = CC; i--; ) sum[u][i] = 0;
	sum[u][val[u].y - 'a'] = val[u].x;
	
	if(ls) {
		sz[u] += sz[ls];
		for(int i = CC; i--; ) sum[u][i] += sum[ls][i];
	}
	if(rs) {
		sz[u] += sz[rs];
		for(int i = CC; i--; ) sum[u][i] += sum[rs][i];
	}
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
int find(int u, int k) {
	while(1) {
		if(k <= sz[son[u][0]]) {u = son[u][0]; continue;}
		k -= sz[son[u][0]];
		
		if(k <= val[u].x) return u;
		k -= val[u].x;
		
		u = son[u][1];
	}
}
void init() {
	nc = 0;
	make(1), make(1);
	sz[rt = pa[2] = 1] = son[1][1] = 2;
}

void split(int k) {
	int u = find(rt, k);
	splay(u, 0);
	
	int ls = son[u][0];
	if(sz[ls] + val[u].x == k) return;
	
	char c = val[u].y;
	int L = k - sz[ls], R = val[u].x - L;
	int A = make(L, c), B = make(R, c);
	
	int rs = son[u][1];
	if(rand() & 1) {
		pa[rs] = B, son[B][1] = rs, push_up(B);
		
		pa[ls] = A, son[A][0] = ls;
		pa[B] = A, son[A][1] = B;
		push_up(A), rt = A;
	}
	else {
		pa[ls] = A, son[A][0] = ls, push_up(A);
		
		pa[A] = B, son[B][0] = A;
		pa[rs] = B, son[B][1] = rs;
		push_up(B), rt = B;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("log.in", "r", stdin);
	freopen("log.out", "w", stdout);
#endif
	
	srand(time(0));
	
	int n, all_sz = 0; scanf("%d", &n);
	init();
	
	int nn = 0;
	while(n--) {
		char c; int L;
		scanf(" %c %d", &c, &L);
		split(L);
		
		if(c == '+') {
			int num;
			scanf("%d %c", &num, &c), all_sz += num;
			
			int x = find(rt, L); splay(x, 0);
			int y = find(x, L + 1); splay(y, x);
			int z = make(num, c);
			pa[z] = y, son[y][0] = z, push_up(y);
			push_up(x);
		}
		else if(c == '-') {
			int num; scanf("%d", &num);
			num = min(all_sz - L + 1, num), all_sz -= num;
			int R = L + num - 1;
			split(R + 1);
			
			int x = find(rt, L); splay(x, 0);
			int y = find(x, R + 2); splay(y, x);
			son[y][0] = 0, push_up(y), push_up(x);
		}
		else {
			int R; scanf("%d", &R);
			R = min(R, all_sz);
			split(R + 1);
			
			int x = find(rt, L); splay(x, 0);
			int y = find(x, R + 2); splay(y, x);
			
			int z = son[y][0], ans = 0;
			for(int i = CC; i--; ) {
				if(sum[z][i]) ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}