const int NN = 101010, N = 316;

#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;

#define pc _putchar_nolock
static char fjf[1010], so[44];
void pt(INT x) {
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

int x[NN], y[NN], p[NN], pos[NN];
int L[NN], R[NN], id[NN];

INT ans[NN], sum;

INT dist(int u, int v) {
	return abs((INT)(x[u] - x[v]) * (y[u] - y[v]));
}

int B[NN], n;
int prv[NN], nxt[NN];

void update(int u, int x) {
	for(; u; u ^= u & -u) B[u] += x;
}

void add(int u) {
	int R = p[u] + 1;
	while(R <= n + 1) {
		if(!B[R]) R += R & -R;
		else R += R & -R >> 1;
	}
	int L = prv[R];
	if(L) sum += dist(pos[L], u);
	if(R <= n) {
		sum += dist(u, pos[R]);
		if(L) sum -= dist(pos[L], pos[R]);
	}
	update(u, 1);
}

void del(int u) {
	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int q; gn(n), gn(q);
	for(int i = 1; i <= n; i++) {
		gn(x[i]), gn(y[i]), gn(p[i]);
		pos[p[i]] = i;
	}
	
	for(int i = q; i--; ) {
		gn(L[i]), gn(R[i]);
		id[i] = i;
	}
	sort(id, id + q, [&](int u, int v) {
		int a = L[u] / N, b = L[v] / N;
		if(a != b) return a < b;
		if(a & 1) return R[u] < R[v];
		return R[u] > R[v];
	});
	
	nxt[0] = n + 1, prv[n + 1] = 0;
	int st = L[id[0]], ed = L[id[0]];
	add(st);
	
	for(int i = 0, u; i < q; i++) {
		u = id[i];
		while(st < L[u]) del(st++);
		while(ed > R[u]) del(ed--);
		while(st > L[u]) add(--st);
		while(ed < R[u]) add(++ed);
		ans[u] = sum;
		break;
	}
	for(int i = q; i--; ) pt(ans[i]), pc(10);
	return 0;
}