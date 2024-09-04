#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, MM = NN << 1;

#define mid (L + R >> 1)

int l, r, x, nn;
int ls[MM], rs[MM];
INT sum[MM][6];
int num[MM], flag[MM][6];

void push_up(int u) {
	for(int i = 6; i--; ) sum[u][i] = sum[ls[u]][i] + sum[rs[u]][i];
}

int build(int L, int R) {
	int u = nn++;
	for(int i = 6; i--; ) flag[u][i] = -1;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
		push_up(u);
	}
	else {
		scanf("%d", &x);
		for(int i = 0; i < 6; i++) {
			sum[u][i] = x;
			x = __builtin_popcount(x);
		}
	}
	return u;
}

void push_down(int u, int L, int R) {
	if(~flag[u][0]) {
		num[u] = 0;
		
		for(int i = 6; i--; ) {
			sum[ls[u]][i] = (INT)flag[u][i] * (mid - L);
			sum[rs[u]][i] = (INT)flag[u][i] * (R - mid);
			flag[ls[u]][i] = flag[rs[u]][i] = flag[u][i];
			flag[u][i] = -1;
		}
	}
	if(num[u]) {
		int i;
		
		num[ls[u]] += num[u];
		for(i = 0; i + num[u] < 6; i++) {
			sum[ls[u]][i] = sum[ls[u]][i + num[u]];
			flag[ls[u]][i] = flag[ls[u]][i + num[u]];
		}
		while(i < 6) {
			sum[ls[u]][i++] = mid - L;
			if(i) flag[ls[u]][i] = flag[ls[u]][i - 1];
			else flag[ls[u]][i] = 0;
		}
		
		num[rs[u]] += num[u];
		for(i = 0; i + num[u] < 6; i++) {
			sum[rs[u]][i] = sum[rs[u]][i + num[u]];
			flag[rs[u]][i] = flag[rs[u]][i + num[u]];
		}
		while(i < 6) {
			sum[rs[u]][i++] = R - mid;
			if(i) flag[rs[u]][i] = flag[rs[u]][i - 1];
			else flag[rs[u]][i] = 0;
		}
		
		num[u] = 0;
	}
}

INT calc(int u, int L, int R) {
	if(l <= L && R <= r) return sum[u][0];
	push_down(u, L, R);
	
	INT ans = 0;
	if(l < mid) ans += calc(ls[u], L, mid);
	if(mid < r) ans += calc(rs[u], mid, R);
	return ans;
}

void replace(int u, int L, int R) {
	if(l <= L && R <= r) {
		num[u] = 0;
		for(int k = x, i = 0; i < 6; i++) {
			sum[u][i] = (INT)k * (R - L);
			flag[u][i] = k;
			k = __builtin_popcount(k);
		}
		return;
	}
	push_down(u, L, R);
	if(l < mid) replace(ls[u], L, mid);
	if(mid < r) replace(rs[u], mid, R);
	push_up(u);
}

void update(int u, int L, int R) {
	if(l <= L && R <= r) {
		for(int i = 6; i--; ) flag[u][i] = 0;
		
		num[u] = 1;
		for(int i = 0; i < 5; i++) {
			sum[u][i] = sum[u][i + 1];
		}
		sum[u][5] = R - L;
		return;
	}
	push_down(u, L, R);
	if(l < mid) update(ls[u], L, mid);
	if(mid < r) update(rs[u], mid, R);
	push_up(u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, q; scanf("%d %d", &n, &q);
	
	build(1, n + 1);
	while(q--) {
		int t; scanf("%d %d %d", &t, &l, &r), r++;
		if(t == 1) printf("%I64d\n", calc(0, 1, n + 1));
		else if(t == 2) scanf("%d", &x), replace(0, 1, n + 1);
		else update(0, 1, n + 1);
	}
	return 0;
}