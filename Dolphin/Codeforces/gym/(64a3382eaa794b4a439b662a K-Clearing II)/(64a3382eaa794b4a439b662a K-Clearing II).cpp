#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010101, MM = NN << 1, inf = 0x3f3f3f3f;

set<pii> s;
set<pii> :: iterator it;

int n, m, k;
int a[NN], ans[NN];
map<int, int> num;

void insert(int x) {
	int L = x, R = x;
	it = s.upper_bound({x + 1, -inf});
	if(it->x == x + 1) R = it->y, s.erase(it);
	
	it = --s.upper_bound({x + 1, -inf});
	if(it->y == x - 1) L = it->x, s.erase(it);
	
	s.insert({L, R});
	return;
}
void erase(int x) {
	it = --s.upper_bound({x + 1, -inf});
	int L = it->x, R = it->y;
	if(L <= x && x <= R) {
		s.erase(it);
		if(L < x) s.insert({L, x - 1});
		if(x < R) s.insert({x + 1, R});
	}
	return;
}

void add(int x) {
	if(!num[x]++) insert(x);
	return;
}

void del(int x) {
	if(!--num[x]) erase(x);
	return;
}

vector<int> B[MM];
int Ls[MM], Rs[MM], mn[MM], mx[MM], A[NN], nc, x;
int build(int L, int R, int a, int b) {
	int u = nc++; mn[u] = a, mx[u] = b;
	if(L >= R || a == b) return u;
	int md = a + b >> 1; B[u].resize(R - L + 1), B[u][0] = 0;
	for(int i = L; i < R; i++) B[u][i - L + 1] = B[u][i - L] + (A[i] <= md);
	int mid = stable_partition(A + L, A + R, [&md](int x) {return x <= md;}) - A;
	return Ls[u] = build(L, mid, a, md), Rs[u] = build(mid, R, md + 1, b), u;
}
int no_big(int u, int L, int R) {
	if(L > R || x < mn[u]) return 0; if(mx[u] <= x) return R - L + 1;
	int a = B[u][L - 1], b = B[u][R];
	return no_big(Ls[u], a + 1, b) + no_big(Rs[u], L - a, R - b);
}
void init(int *a, int n) {
	int i = n, mn, mx;
	for(A[i] = mn = mx = a[i]; --i; A[i] = a[i]) {
		if(a[i] < mn) mn = a[i];
		if(a[i] > mx) mx = a[i];
	}
	nc = 0, build(1, n + 1, mn, mx);
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	s.insert({-inf, -inf});
	s.insert({-inf - 2, -inf - 2});
	s.insert({inf, inf});
	s.insert({inf + 2, inf + 2});
	for(int i = 1; i <= m; i++) add(a[i]);
	for(int i = m; i <= n; i++) {
		it = --s.upper_bound({k + 1, -inf});
		if(it->x <= k && k <= it->y) ans[i] = it->y - k + 1;
		
		if(i < n) add(a[i + 1]);
		del(a[i - m + 1]);
	}
	
	INT sum = 0;
	init(a, n);
	for(int i = m; i <= n; i++) {
		x = ans[i];
		sum += no_big(0, i - m + 1, i);
	}
	printf("%I64d\n", sum);
	return 0;
}