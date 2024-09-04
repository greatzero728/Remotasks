#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, MM = NN << 1;

int a[NN];
int ls[MM], rs[MM], nn;
int mx[MM];

void push_up(int u) {
	mx[u] = max(mx[ls[u]], mx[rs[u]]);
}

#define mid (L + R >> 1)

int build(int L, int R) {
	int u = nn++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
		push_up(u);
	}
	else mx[u] = a[R] - a[L];
	return u;
}

int l, r;

void update(int u, int L, int R) {
	if(l <= L && R <= r) mx[u] = a[R] - a[L];
	else {
		if(l < mid) update(ls[u], L, mid);
		if(mid < r) update(rs[u], mid, R);
		push_up(u);
	}
}

int x;

int calc(int u, int L, int R) {
	int ans = L;
	if(l <= L) {
		if(mx[u] <= x) {
			if(a[R] - a[R - 1] <= x) return R;
			return R - 1;
		}
		if(R - L == 1) return ans;
	}
	if(l < mid) {
		ans = calc(ls[u], L, mid);
		if(ans == mid) return calc(rs[u], mid, R);
		return ans;
	}
	return calc(rs[u], mid, R);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	build(1, n);
	int q; scanf("%d", &q);
	while(q--) {
		int t, L, R; scanf("%d %d %d", &t, &L, &R);
		if(t == 1) {
			a[L] = R;
			if(1 < L) l = L - 1, r = L, update(0, 1, n);
			if(L < n) l = L, r = l + 1, update(0, 1, n);
		}
		else {
			l = L, x = R;
			printf("%d\n", calc(0, 1, n));
		}
	}
	return 0;
}